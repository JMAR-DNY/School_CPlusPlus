// FileName   : position.h
// programmer : J. Marron
// template definitions of the position class

#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using std::cout;
using std::endl;

class position{
public:
	position();
	void printFloor();
	void setDefaultPosition();

	friend class turtle;
	friend class pen;

	void clearPosition(pen n);
	void clearFloor();

	int posx, posy, tempx, tempy;

private:
	char floor[22][22];

	int spaces;

	const unsigned char tiles = 0;};

#endif