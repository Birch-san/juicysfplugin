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

RjManualCallQueue::RjManualCallQueue(int RingBufferSize)
: fifo(RingBufferSize)
{
    // TODO: data should be aligned to a cache line boundary.
    // Allocate double size buffer to easily support variable length messages,
    // by hanging them over the end of the buffer.
    fifodata = new char[ RingBufferSize * 2 ];
}
    
RjManualCallQueue::~RjManualCallQueue()
{
    delete [] fifodata;
}


bool RjManualCallQueue::isEmpty() {
    return fifo.getTotalSize() == fifo.getFreeSpace();
}

template <class Functor>
bool RjManualCallQueue::callf(Functor const & f) {
    size_t allocSize = roundUpToCacheLineBoundary(sizeof(WorkItem<Functor>));
    
    int idx1, idx2, sz1, sz2;
    fifo.prepareToWrite(static_cast<int>(allocSize), idx1, sz1, idx2, sz2);
    
    if (sz1+sz2 < allocSize) return false;
    
    // double size buffer means we can ignore idx2 and sz2
    new (fifodata+idx1) WorkItem<Functor> (f);

    fifo.finishedWrite(static_cast<int>(allocSize));
    
    return true;
}
    
bool RjManualCallQueue::synchronize() {
    bool didSomething = false;
    
    while (fifo.getNumReady() > 0) {
        
        int idx1, idx2, sz1, sz2;
        fifo.prepareToRead(1, idx1, sz1, idx2, sz2);
        didSomething = true;
        
        Work *w = reinterpret_cast<Work*>(fifodata+idx1);
        
        // notice only one function pointer invocation here, not two virtual function calls
        size_t sizeofWorkItem = (*w->execAndDestructFn) (w);
        size_t allocSize = roundUpToCacheLineBoundary(sizeofWorkItem);
        
        fifo.finishedRead(static_cast<int>(allocSize));
    }
    
    return didSomething;
}

RjManualCallQueue::Work::Work(WorkExecAndDestructFunctionPtr f) :
execAndDestructFn(f)
{}

/** WorkItem template - extends Work for each type of Functor */
template <class Functor>
RjManualCallQueue::WorkItem<Functor>::WorkItem(Functor const & fun) :
Work(&WorkItem::myExecAndDestruct),
myCall(fun)
{}

template <class Functor>
size_t RjManualCallQueue::WorkItem<Functor>::myExecAndDestruct(void *workItemStorage) {
    // cast to *concrete* work item pointer
    WorkItem *that = reinterpret_cast<WorkItem*>(workItemStorage);
    that->myCall();
    that->~WorkItem(); // invoke concrete dtor (destructs functor)
    
    return sizeof(WorkItem);
}
    
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
    
    
// Used to avoid false sharing and to give
// correct alignment to embedded structs.
size_t RjManualCallQueue::roundUpToCacheLineBoundary(size_t x) {
    return x; // TODO
}
