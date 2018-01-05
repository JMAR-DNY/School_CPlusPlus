// FileName   : boat.cpp
// programmer : J. Marron
// implementations of the boat class


#include "boat.h"

boat::boat()
{
	length = 10;
	width = depth = 5;
	oars = 2;
}


boat::boat(double l, double w, double d, int o)
{
	length = l;
	width = w;
	depth = d;
	oars = o;
}


boat::~boat()
{
	length = width = depth = oars = 0;
}


void boat::speed(double s)
{
	cout << "The boat's rowing speed is " << s << " knots." << endl;
}


void boat::display()
{
	cout << "This boat  is " << length << " long and "
		<< width << " wide and " << depth << " deep with "
		<< oars << " oars";
}