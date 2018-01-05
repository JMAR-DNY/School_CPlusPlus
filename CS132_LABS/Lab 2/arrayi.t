////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : arrayi.t
//
// This file contains the implementation of the templated array class functions 
// 
//
// Programmer        : Jeffrey Marron with contributions from B.J. Streller
//
// Date created      : 9/13/15 & in the past
//
// Date last revised : 9/13/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ARRAYI_T_
#define ARRAYI_T_

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace::std;

// Member function definitions for class Array

// Initialize static data member at file scope
template<typename T>
int Array<T>::arrayCount = 0;   // no objects yet


// Default constructor for class Array
template<typename T>
Array<T>::Array(int arraySize)
{
	++arrayCount;             // count one more object
	size = arraySize;         // default size is 10
	ptr = new int[size];      // create space for array
	assert(ptr != 0);  // terminate if memory not allocated
	int i;
	for (i = 0; i < size; i++)
		ptr[i] = 0;            // initialize array
}

// Copy constructor for class Array
template<typename T>
Array<T>::Array(const Array<T> &init)
{
	++arrayCount;             // count one more object
	size = init.size;         // size this object
	ptr = new int[size];      // create space for array    possible rechange to new int size
	assert(ptr != 0);  // terminate if memory not allocated
	cout << "copy constr arrayi " << endl;
	int i;
	for (i = 0; i < size; i++)
		ptr[i] = init.ptr[i];  // copy init into object
	cout << endl << "copy constructor working" << endl;
}

// Destructor for class Array
template<typename T>
Array<T>::~Array()
{
	--arrayCount;             // one fewer objects
	delete[] ptr;            // reclaim space for array
}

// Get the size of the array
template<typename T>
int Array<T>::getSize() const
{
	return size;
}

// Overloaded assignment operator
template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &right)
{
	if (&right != this)
	{    // check for self-assignment
		delete[] ptr;        // reclaim space
		size = right.size;    // resize this object
		ptr = new int[size];  // create space for array copy  possibly chaneg to new int size
		assert(ptr != 0);     // terminate if memory not allocated
		int i;
		for (i = 0; i < size; i++)
			ptr[i] = right.ptr[i];  // copy array into object
	}
	//this points to ptr to int,  *this returns ptr value
	//ie, the address of the array
	return *this;   // enables x = y = z;
}

// + operator for arrays
template<typename T>
Array<T>  Array<T>::operator + (const Array<T>& right)
{
	int large, small;
	if (size > right.size)
	{
		large = size;
		small = right.size;
	}
	else
	{
		large = right.size;
		small = size;
	}
	Array z(large);
	int i;
	for (i = 0; i < small; i++)
		z.ptr[i] = ptr[i] + right.ptr[i];
	for (i = small; i < large; i++)
	{
		if (right.size == small)
			z.ptr[i] = ptr[i];
		else  z.ptr[i] = right.ptr[i];
	}
	cout << "# of arrays instantiated " << getArrayCount() << endl;
	return z;
}

// - operator for arrays
template<typename T>
Array<T>  Array<T>::operator - (const Array<T>& right)
{
	int large, small;
	if (size > right.size)
	{
		large = size;
		small = right.size;
	}
	else
	{
		large = right.size;
		small = size;
	}
	Array z(large);
	int i;
	for (i = 0; i < small; i++)
		z.ptr[i] = ptr[i] - right.ptr[i];
	for (i = small; i < large; i++)
	{
		if (right.size == small)
			z.ptr[i] = ptr[i];
		else  z.ptr[i] = right.ptr[i];
	}
	cout << "# of arrays instantiated " << getArrayCount() << endl;
	return z;
}

// Determine if two arrays are equal and
// return 1 if true, 0 if false.
template<typename T>
int Array<T>::operator==(const Array<T> &right) const
{
	if (size != right.size)
		return 0;    // arrays of different sizes
	int i;
	for (i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return 0; // arrays are not equal

	return 1;       // arrays are equal
}

// Determine if two arrays are not equal and
// return 1 if true, 0 if false.
template<typename T>
int Array<T>::operator!=(const Array<T> &right) const
{
	if (size != right.size)
		return 1;         // arrays of different sizes
	int i;
	for (i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return 1;      // arrays are not equal

	return 0;            // arrays are equal
}

// Overloaded subscript operator
template<typename T>
int &Array<T>::operator[](int subscript)
{
	// check for subscript out of range error
	assert(0 <= subscript && subscript < size);
	return ptr[subscript];   // reference return creates lvalue
}

// Return the number of Array objects instantiated
template<typename T>
int Array<T>::getArrayCount()
{
	return arrayCount;
}

// Overloaded input operator for class Array;
// inputs values for entire array.
template<typename T>
istream &operator>>(istream &input, Array<T> &a)
{
	cout << "Input " << a.size << " numbers into the array: " <<endl;
	int i;
	for (i = 0; i < a.size; i++)
		input >> a.ptr[i];

	return input;   // enables cin >> x >> y;
}

// Overloaded output operator for class Array
template<typename T>
ostream &operator<<(ostream &output, const Array<T> &a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		output << a.ptr[i] << ' ';

		if ((i + 1) % 10 == 0)
			output << endl;
	}  //end for

	if (i % 10 != 0)
		output << endl;

	return output;   // enables cout << x << y;
}


#endif