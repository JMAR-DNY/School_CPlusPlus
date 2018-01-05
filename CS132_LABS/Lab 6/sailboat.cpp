// FileName   : boat.cpp
// programmer : J. Marron
// implementations of the sailboat class


#include "sailboat.h"

sailboat::sailboat()
{
	length = 10;
	width = depth = 5;
	oars = 2;
	mastHeight = 12;
	keelDepth = 10;
	sails = 3;
}

sailboat::sailboat(double l, double w, double d, int o, double m, double k, int s)
{
	length = l;
	width = w;
	depth = d;
	oars = o;
	mastHeight = m;
	keelDepth = k;
	sails = s;
}

sailboat::~sailboat()
{
	length = width = depth = oars = 0;
}

void sailboat::speed(double s)
{
	cout << "The boat's sailing speed is " << s << " knots." << endl;
}

void sailboat::display()
{
	cout << "This boat  is " << length << " long and "
		<< width << " wide and " << depth << " deep with "
		<< oars << " oars. " <<endl<< "It has a mast height of " <<
		mastHeight << " a keel depth of " << keelDepth << " and " <<
		sails << " sails." <<endl;
}