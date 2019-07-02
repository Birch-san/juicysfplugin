#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

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

class RjManualCallQueue {
public:
    RjManualCallQueue(int RingBufferSize);
    ~RjManualCallQueue();
    
    bool isEmpty();
    
    template <class Functor>
    bool callf(Functor const & f);
    
    bool synchronize();
    
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
        Work( WorkExecAndDestructFunctionPtr f );
        
        WorkExecAndDestructFunctionPtr execAndDestructFn;
    };
    
    /** WorkItem template - extends Work for each type of Functor */
    template <class Functor>
    struct WorkItem : public Work {
        explicit WorkItem(Functor const & fun);
    private:
        static size_t myExecAndDestruct(void *workItemStorage);
        
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
    size_t roundUpToCacheLineBoundary( size_t x );
};
