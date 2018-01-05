// FileName   : boat.h
// programmer : J. Marron
// definitions of the sailboat class

#ifndef SAILBOAT_H
#define SAILBOAT_H

#include <iostream>
#include"boat.h"

using std::cout;
using std::endl;

class sailboat :protected boat{
	public:
	sailboat();
	sailboat(double, double, double, int, double, double, int);
	~sailboat();
	void speed(double);
	void display();
private:
	double length,
		width,
		depth,
		mastHeight, 
		keelDepth;
	int oars, sails;

};


#endif;