/**************************************************************************************************
*
*   File name :			lab1_driver.cpp
*
*						Lab1
*
*
*   Programmer:  		Jeffrey Marron with contributions from B.J. Streller
*
*   Date Written:		9/4/2015 & in the past
*
*   Date Last Revised:	9/4/2015
*
***************************************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <new>
using std::bad_alloc;

#include<cstdlib>

#define int_array 1
#define pointer2int_array 2

// Prototype declarations

int getSize();

void*  getArray(int &howMuch, int typeOf);

void populateArray(int num_of, int* ptr);

void sort(int count, int** value);

void printSortedArray(int num, int **pt);

/////////////////////////// -- main -- ///////////////////////////////////////////////////////

int  main()
{

	int SIZE = getSize();

	int* dataArray = (int*)getArray(SIZE, int_array);
	int** pointerArray = (int**)getArray(SIZE, pointer2int_array);
	(void)populateArray(SIZE, dataArray);

	for (int i = 0; i < SIZE; i++)
	{
		pointerArray[i] = &dataArray[i];
	}

	(void)sort(SIZE, pointerArray);
	(void)printSortedArray(SIZE, pointerArray);

	//For loop to print original data put into dataArray
		cout << "original dataArray: " << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << dataArray[i] << " ";
		}

	delete[] dataArray;
	delete[] pointerArray;
	
	cout << endl << endl;

	return (0);

}
////////////////////////////////  -- end main --  ////////////////////////////////////////////////

/***************************************************************************************************
*
*   Function Name:		getSize
*
*   Purpose:			requests an integer from user
*
*   Input Parameters:		none
*
*   Output parameters:		none
*
*   Return Value:		retuns the user entered integer howMuch
*
***************************************************************************************************/

int getSize()
{
	int howMuch;
	cout << "enter the size of the array :  ";
	cin >> howMuch;
	cout << endl;
	return howMuch;
}

/***************************************************************************************************
*
*   Function Name:		getArray
*
*   Purpose:			dynamically allocates either an array of ints or an aaray of
*				int pointers
*
*   Input Parameters:		an int howMuch - the size of array to allocate
*				an int typeOf indicating the type of array to allocate
*
*   Output parameters:		none
*
*   Return Value:		returns a pointer to an int array or an array of int pointers
*
***************************************************************************************************/

void*  getArray(int &howMuch, int typeOf)
{

	try
	{
		switch (typeOf)
		{
		case int_array:
		{
			int* p = new int[howMuch];
			return(p);
		}

		case pointer2int_array:
		{
			int** p = new int*[howMuch];
			return(p);
		}
		default:
		{
			cerr << " problem allocating array \n\n";
			exit(666);
		}

		}
	}
	catch (bad_alloc &memoryAllocationException)
	{
		cerr << memoryAllocationException.what() << endl;
		exit(666);
	}
}

/***************************************************************************************************
*
*   Function Name     :		populate array
*
*   Purpose           :		to input values into the data array
*
*   Input Parameters  :		an int num_of to specify the size of the array 
*   
*	Output parameters :		an int* ptr to point to the data in the integer array
*
*
*   Return Value      :		none
*
***************************************************************************************************/

void populateArray(int num_of, int* ptr)
{
	cout << "input values one at a time then press enter: " << endl;
	for (int i = 0; i < num_of; i++)
	{
		cin >> ptr[i];
	}
	cout << endl;
}

/***************************************************************************************************
*
*   Function Name     :		sort
*
*   Purpose           :		to sort the pointer array
*
*   Input Parameters  :		int count to specify size of array
*
*	Output parameters :		int value to change the order of the array		
*
*
*   Return Value      :		none
*
***************************************************************************************************/

void sort(int count, int** value)
	{
		int* temp;
		int iteration;
		int index;
		for (iteration = 1; iteration < count; iteration++)
		{
			for (index = 0; index < count - iteration; index++)
				if (*value[index] > *value[index + 1])
				{
				temp = value[index];
				value[index] = value[index + 1];
				value[index + 1] = temp;
				}
		}
}

/***************************************************************************************************
*
*   Function Name     :		printSortedArray
*
*   Purpose           :		to print the sorted array
*
*   Input Parameters  :		int num to specify size of array
*
*	Output parameters :		int pt to be printed from the array
*
*   Return Value      :		none
*
***************************************************************************************************/
void printSortedArray(int num, int **pt)
{
	//Ascending
	cout << "Ascending: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << *pt[i] << " ";
	}
	cout << endl <<endl;
	//Descending
	cout << "Descending: " << endl;
	for (int i = num; i-- > 0;)
	{
		cout << *pt[i] << " ";
	}
	cout << endl <<endl;
}

/*
enter the size of the array :  7

input values one at a time then press enter :
26
14
57
33
41
60
19

Ascending:
14 19 26 33 41 57 60

Descending :
		   60 57 41 33 26 19 14

		   original dataArray :
26 14 57 33 41 60 19

Press any key to continue . . .


enter the size of the array :  10

input values one at a time then press enter:
14
57
19
60
41
26
33
-34
-666
666

Ascending:
-666 -34 14 19 26 33 41 57 60 666

Descending:
666 60 57 41 33 26 19 14 -34 -666

original dataArray:
14 57 19 60 41 26 33 -34 -666 666

Press any key to continue . . .
*/