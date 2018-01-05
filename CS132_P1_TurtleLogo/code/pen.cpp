// FileName  : turtle.cpp
// programmer : J. Marron
// non templated implementations of the turtle class

#include "pen.h"
#include <iostream>

using namespace std;

//Default pen constructor
pen::pen(){
	down = false;
	currentBrush = block;}

/***************************************************************************************************
*
*   Function Name     :		changeBrush
*
*   Purpose           :		To change the currentBrush 
*
*   Input Parameters  :		brushSelect
*
*	Output parameters :		currentBrush
*
*   Return Value      :		none
*
***************************************************************************************************/
void pen::changeBrush(){
	cout << "Select a brush: " << endl
		<< "1 pie: " << pie << endl
		<< "2 diamond: " << diamond << endl
		<< "3 mist: " << mist << endl
		<< "4 block: " << block << endl
		<< "5 Return to Program" << endl;
	cin >> brushSelect;
	cout << endl;

	switch (brushSelect){

	case 1:
		currentBrush = pie;
		break;
	case 2:
		currentBrush = diamond;
		break;
	case 3:
		currentBrush = mist;
		break;
	case 4:
		currentBrush = block;
		break;
	case 5:
		break;
	default:
		cout << "Invalid input" << endl;
		break;}
	cout << currentBrush << " is now the current brush." << endl;}

/***************************************************************************************************
*
*   Function Name     :		penMsg
*
*   Purpose           :		Prints the status of the pen to the console
*
*   Input Parameters  :		down
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void pen::penMsg(){
	if (down){
		cout << "The pen is down" << endl;}
	else{
		cout << "The pen is up";}}