// FileName   : direction.cpp
// programmer : J. Marron
// non templated implementations of the direction class

#include "direction.h"

using std::cout;
using std::endl;

//Default direction constructor
direction::direction(){
	currentDir = 'E';}

/***************************************************************************************************
*
*   Function Name     :		directionValidation
*
*   Purpose           :		checks if the input for the direction is valid or not
*
*   Input Parameters  :		tempDir
*
*	Output parameters :		currentDirection
*
*   Return Value      :		none
*
***************************************************************************************************/
void direction::directionValidation(){
	if (toupper(tempDir) == 'N' || toupper(tempDir) == 'S' || toupper(tempDir) == 'E' || 
		toupper(tempDir) == 'W'){
		currentDir = toupper(tempDir);
		cout << "The turtle is now facing " << currentDir << endl;
	}
	else
	cout << "Invalid Direction" << endl;}