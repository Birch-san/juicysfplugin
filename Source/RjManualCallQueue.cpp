#include "../JuceLibraryCode/JuceHeader.h"
#include "RjManualCallQueue.h"
#include <functional>
#include <iostream>

/**
 By jimc, on the JUCE forums:
 https://forum.juce.com/t/whats-best-practice-for-gui-change-notification/12264/61
 
 A function call queue which enables functions to be called
 asychronously on another thread.
 
 It has the following special features:
 - No locking and avoids using the system allocator (except
 during the constructor).
 
 Watch out for:
 - Objects you pass as function arguments (which are passed by value)
 doing memory allocation, which may result in a lock.
 */

template <int RingBufferSize>
RjManualCallQueue<RingBufferSize>::RjManualCallQueue()
: fifo(RingBufferSize)
{
    // TODO: data should be aligned to a cache line boundary.
    // Allocate double size buffer to easily support variable length messages,
    // by hanging them over the end of the buffer.
    fifodata = new char[ RingBufferSize * 2 ];
}
    
template <int RingBufferSize>
RjManualCallQueue<RingBufferSize>::~RjManualCallQueue()
{
    delete [] fifodata;
}


template <int RingBufferSize>
bool RjManualCallQueue<RingBufferSize>::isEmpty() {
    return fifo.getTotalSize() == fifo.getFreeSpace();
}

template <int RingBufferSize, class Functor>
bool RjManualCallQueue<RingBufferSize>::Work<Functor>::callf(Functor const & f) {
    size_t allocSize = roundUpToCacheLineBoundary(sizeof(WorkItem<Functor>));
    
    int idx1, idx2, sz1, sz2;
    fifo.prepareToWrite(allocSize, idx1, sz1, idx2, sz2);
    
    if (sz1+sz2 < allocSize) return false;
    
    // double size buffer means we can ignore idx2 and sz2
    new (fifodata+idx1) WorkItem<Functor> (f);

    fifo.finishedWrite(allocSize);
    
    return true;
}
    
    
    
    bool synchronize() {
        
        bool didSomething = false;
        
        
        
        while (fifo.getNumReady() > 0) {
            
            int idx1, idx2, sz1, sz2;
            
            fifo.prepareToRead(1, idx1, sz1, idx2, sz2);
            
            didSomething = true;
            
            
            
            Work *w = reinterpret_cast<Work*>(fifodata+idx1);
            
            // notice only one function pointer invocation here, not two virtual function calls
            
            size_t sizeofWorkItem = (*w->execAndDestructFn) (w);
            
            size_t allocSize = roundUpToCacheLineBoundary(sizeofWorkItem);
            
            
            fifo.finishedRead(allocSize);
            
        }
        
        return didSomething;
        
    }
    
    
    
    
    
private:
    
    
    
    // Avoid a vtable and two separate virtual function
    
    // dispatches (operator() and destructor) by putting
    
    // everything into a single function and implementing
    
    // our own virtual function call.
    
    
    
    // type for pointer to a function that executes work,
    
    // calls the destructor for the and returns size of
    
    // concrete instance.
    
    typedef size_t (*WorkExecAndDestructFunctionPtr)( void *workItemStorage );
    
    
    
    class Work {
        
        // NOTE: no vtable.
        
    public:
        
        Work( WorkExecAndDestructFunctionPtr f ) :
        
        execAndDestructFn(f)
        
        { }
        
        WorkExecAndDestructFunctionPtr execAndDestructFn;
        
    };
    
    
    
    /** WorkItem template - extends Work for each type of Functor */
    
    template <class Functor>
    
    struct WorkItem : public Work {
        
        explicit WorkItem(Functor const & fun) :
        
        Work(&WorkItem::myExecAndDestruct),
        
        myCall(fun)
        
        {}
        
        
        
    private:
        
        static size_t myExecAndDestruct(void *workItemStorage) {
            
            // cast to *concrete* work item pointer
            
            WorkItem *that = reinterpret_cast<WorkItem*>(workItemStorage);
            
            that->myCall();
            
            that->~WorkItem(); // invoke concrete dtor (destructs functor)
            
            return sizeof(WorkItem);
            
        }
        
        
        
        Functor myCall;
        
    };
    
    
    
    /* For clarity (maybe) what's happening here is:
     
     1  There are instances of the templated class
     
     WorkItem for each type of Functor, and hence
     
     multiple versions of myExecAndDestruct.
     
     2  When the WorkItem is created the
     
     Work::execAndDestructFn pointer is set to
     
     point to the appropriate instance of
     
     myExecAndDestruct - the pointer is passed
     
     to the Work superclass constructor by the
     
     WorkItem<Functor> class.
     
     
     
     To call we:
     
     -  Get the data from the fifo.
     
     -  Cast it to be a Work.
     
     -  Call the appropriate instance of myExecAndDestruct
     
     via the execAndDestructFn pointer.
     
     */
    
    
    
    AbstractFifo fifo;
    
    char *fifodata;
    
    
    // Used to avoid false sharing and to give
    
    // correct alignment to embedded structs.
    
    size_t roundUpToCacheLineBoundary( size_t x )
    
    {
        
        return x; // TODO
        
    }
    
};
