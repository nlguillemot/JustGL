/*
    The MIT License (MIT)

    Copyright (c) 2016 Nicolas Guillemot

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
*/

#ifndef JUSTGL_DELTATIMER_H
#define JUSTGL_DELTATIMER_H

#include "justgl.h"

class DeltaTimer
{
public:
    uint64_t LastTicks = 0;
    uint64_t CurrTicks = 0;

    uint64_t DeltaTicks = 0;
    float DeltaSeconds = 0.0;

    void Update()
    {
        LastTicks = CurrTicks;
        CurrTicks = GetCurrentTicks();
        
        if (LastTicks == 0)
        {
            LastTicks = CurrTicks;
        }
        
        DeltaTicks = CurrTicks - LastTicks;
        DeltaSeconds = (float)DeltaTicks / GetTicksPerSecond();
    }
};

#endif // JUSTGL_DELTATIMER_H