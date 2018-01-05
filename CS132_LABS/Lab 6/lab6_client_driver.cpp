////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : lab6_client_driver.cpp
//
// This program		 : creates a sailboat object of a derived class of boat, sets specific
//		parameters to it through a function and then displays those parameters through another function.
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 10/15/15
//
// Date last revised : 10/15/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

#include"boat.h"
#include"sailboat.h"

int main(){
	sailboat blackpearl(25, 6, 3, 8, 12, 10, 3);
	blackpearl.speed(20);
	blackpearl.display();
}

/* CONSOLE OUTPUT
The boat's sailing speed is 20 knots.
This boat  is 25 long and 6 wide and 3 deep with 8 oars.
It has a mast height of 12 a keel depth of 10 and 3 sails.
Press any key to continue . . .
*/