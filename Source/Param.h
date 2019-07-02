#pragma once

/*
 ==============================================================================
 
 Copyright (c) 2012 by Vinnie Falco
 
 This file is provided under the terms of the MIT License:
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 ==============================================================================
 */

/** A concurrent, named parameter.
 */
class Param
{
public:
    /** Synchronizes state.
     */
    class Listener
    {
    public:
        /** Called when value changes.
         */
        virtual void onParamChange (Param* param, double value) { }
    };
    
public:
    Param (String name,
           double initialValue,
           vf::CallQueue& owningThread);
    
    /** Return the internal name.
     */
    String getName () const;
    
    /** Add or remove a Listener.
     */
    void addListener (Listener* listener, vf::CallQueue& thread);
    void removeListener (Listener* listener);
    
    /** Change the value.
     */
    void setValue (double value);
    
private:
    void doSetValue (double value);
    
protected:
    double doGetValue () const;
    
private:
    struct State
    {
        State (double initialValue)
        : value (initialValue)
        {
        }
        double value;
    };
    
    typedef vf::ConcurrentState <State> StateType;
    
    String m_name;
    StateType m_state;
    vf::CallQueue& m_thread;
    vf::Listeners <Listener> m_listeners;
};
