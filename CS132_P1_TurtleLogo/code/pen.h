// FileName   : turtle.h
// programmer : J. Marron
// definitions of the turtle class

#ifndef PEN_H
#define PEN_H

#include <iostream>

using std::cout;
using std::endl;

class pen{
public:
	pen();
	void changeBrush();
	void penMsg();

	bool down;
	char currentBrush;
	int brushSelect;

	const unsigned char pie = 227;
	const unsigned char diamond = 4;
	const unsigned char mist = 176;
	const unsigned char block = 254;};

#endif

