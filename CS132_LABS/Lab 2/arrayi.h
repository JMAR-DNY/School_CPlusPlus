////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : arrayi.h
//
// This file contains the class definition for the array template
// 
//
// Programmer        : Jeffrey Marron with contributions from B.J. Streller
//
// Date created      : 9/13/15 & in the past
//
// Date last revised : 9/13/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ARRAYI_H_
#define ARRAYI_H_

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace::std;

template<typename T> class Array;
template<typename T>
ostream &operator<< (ostream& output, const Array<T> &a);
template<typename T>
istream &operator>> (istream &input, Array<T> &a);

template<typename T>
class Array
{
	friend ostream &operator<< <>(ostream &output, const Array<T> &a);
	friend istream &operator>> <>(istream &input, Array<T> &a);

public:
	Array(int = 10);	//constructor
	Array(const Array<T> &init);	//copy constructor
	~Array();		//destructor
	int getSize() const;	//return size
	Array<T> &operator = (const Array<T> &right);
	int operator==(const Array<T> &right) const;
	Array<T> operator + (const Array<T> &right);
	Array<T> operator - (const Array<T> &right);
	int operator != (const Array<T> &right) const;
	int &operator[] (int subscript);

	static int getArrayCount();	//get count of existing
	//array objects

private:
	int *ptr;	//ptr to first array element
	int size;	//size of the array
	static int arrayCount;	// #of arrays instantiated
};

#include "arrayi.t"


#endif
