// FileName   : turtle.h
// programmer : J. Marron
// definitions of the turtle class

#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include "position.h"
#include "direction.h"
#include "pen.h"

using std::cout;
using std::endl;

class turtle{
public:
	turtle();

	direction direction1;
	position floor1;
	pen pen1;

	void movement();
	void placeTurtle();
	void jump();
	void status();

	const unsigned char avatar = 15;
	int spaces, tempSpaces;};

#endif