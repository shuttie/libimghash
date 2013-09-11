/*
 * Copyright 2012 Sociohub LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Roman Grebennikov
 */

#include <iostream>
#include <fstream>
#include <ios>
#include <sys/timeb.h>
#include "simplehasher.h"
#include <sys/stat.h>

#define PASS_COUNT 10
#define TEST_COUNT 100

int currentTimeMillis() {
    timeb tb;
    ftime(&tb);
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}


int main(int argc, char* argv[]) {
    if (argc == 2) {
        imghash::Source data;
        data.loadFile(argv[1]);
        // hashing
        imghash::Hasher *hasher = new imghash::SimpleHasher(8);
        for (int pass=0; pass<PASS_COUNT; ++pass) {
            int msecStart = currentTimeMillis();
            for (int test=0; test<TEST_COUNT; ++test) {
                imghash::Hash hash = hasher->hash(data);
            }
            int msecEnd = currentTimeMillis();
            float perf = (float)TEST_COUNT*1000.0f/(float)(msecEnd - msecStart);
            printf("pass %2d: done %d in %dms, speed=%f\n", pass, TEST_COUNT, msecEnd-msecStart, perf);
        }
        delete hasher;
    } else {
        printf("Usage: ./benchmark <input_file>");
    }
}

