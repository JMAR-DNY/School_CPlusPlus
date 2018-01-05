////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : lab2_client_driver.cpp
//
// This program 
// 
//
// Programmer        : Jeffrey Marron with contributions from B.J. Streller
//
// Date created      : 9/13/15 & in the past
//
// Date last revised : 9/13/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace::std;

#include "arrayi.h"

int main()
{
	Array<int> A1(4), A2(7), A3(9);
	Array<double> B1(4), B2(7), B3(9);
	Array<float> C1(4), C2(7), C3(9);
	
	cin >> A1 >> A2;

	A1.getSize();
	A2.getSize();
	A3 = A1 - A2;

	cout << A1 << A2 << A3;

	cin >> B1 >> B2;

	B1.getSize();
	B2.getSize();
	B3 = B1 - B2;

	cout << B1 << B2 << B3;

	cin >> C1 >> C2;

	C1.getSize();
	C2.getSize();
	C3 = C1 - C2;

	cout << C1 << C2 << C3;
  return 0;
}

/*
Input 4 numbers into the array:
6 7 8 9
Input 7 numbers into the array:
1 2 3 4 5 6 7
# of arrays instantiated 4
copy constr arrayi

copy constructor working
6 7 8 9
1 2 3 4 5 6 7
5 5 5 5 5 6 7
Input 4 numbers into the array:
6 7 8 9
Input 7 numbers into the array:
1 2 3 4 5 6 7
# of arrays instantiated 4
copy constr arrayi

copy constructor working
6 7 8 9
1 2 3 4 5 6 7
5 5 5 5 5 6 7
Input 4 numbers into the array:
6 7 8 9
Input 7 numbers into the array:
1 2 3 4 5 6 7
# of arrays instantiated 4
copy constr arrayi

copy constructor working
6 7 8 9
1 2 3 4 5 6 7
5 5 5 5 5 6 7
Press any key to continue . . .
*/