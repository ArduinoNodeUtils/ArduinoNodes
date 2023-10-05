// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <Wire.h>

namespace nf {
template <typename T, size_t S>
class Queue {

public:

	bool pushBack (T value) {
	    _array[_cursorPosition] = value;
	    _cursorPosition++;
	    _cursorPosition = _cursorPosition % S;

	    _filled = _filled < S ? _filled + 1 : S;

	    return true;
    }

	T peakLast () {
	    return peakLast (0);
    }

	T peakLast (int position) {
	    if (position > _filled) {
	    	return peakLast (_filled);
	    }
	    int arrayPos = _cursorPosition - (position + 1);

	    if (arrayPos < 0) {
	    	arrayPos = S + arrayPos;
	    }
	    return _array[arrayPos];
    }

    void clear() {

    }

	int size () {

	    return _filled;
    }

// 	void print () {
// 	    Serial.print ("(");
// 	    for (int i = 0; i < SIZE; i++) {
// 
// 	    	if (_cursorPosition == i)  {
// 	    		Serial.print ("->");
// 	    	}
// 	    	Serial.print (_array[i]);
// 	    	Serial.print (",");
// 	    }
// 	    Serial.println (")");
// 
//     }
// 
// 	void debugPrint () {
// 	    Serial.print ("(");
// 	    for (int i = 0; i < min (size (), SIZE); i++) {
// 	    	Serial.print (peakLast (i));
// 	    	Serial.print (":");
// 	    }
// 	    Serial.println(")");
//     }

private:

	T _array[S];
	int _filled = 0;
	int _cursorPosition = 0;
};
}
#endif