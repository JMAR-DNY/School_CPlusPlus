// FileName  : turtle.cpp
// programmer : J. Marron
// non templated implementations of the turtle class

#include "turtle.h"
#include <iostream>

using std::cin;

//Default turtle constructor.
turtle::turtle(){}

/***************************************************************************************************
*
*   Function Name     :		movement
*
*   Purpose           :		Moves the turtle around the array & draws if the pen is down
*
*   Input Parameters  :		tempSpaces, floor.posx, floor.posy, pen.down
*
*	Output parameters :		posx, posy, currentBrush
*
*   Return Value      :		none
*
***************************************************************************************************/
void turtle::movement(){
	if (cin.fail() == true || tempSpaces < 1 || tempSpaces>20 || tempSpaces != floor(tempSpaces)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid move input." << endl;
	}
	else{
		spaces = tempSpaces;
	}

	switch (direction1.currentDir){
		
	case 'N':
		for (int i = 0; i < spaces; i++)
			if (floor1.posx > 1){
			if (pen1.down)
			{
				floor1.floor[floor1.posx][floor1.posy] = pen1.currentBrush;
				floor1.posx--;
			}
			else
				floor1.posx--;
			}

			else if (floor1.posx == 1){
				cout << "You've hit a wall" << endl;
				i = spaces;
			}
			break;

	case 'S':
		for (int i = 0; i < spaces; i++)
			if (floor1.posx < 20){
			if (pen1.down)
			{
				floor1.floor[floor1.posx][floor1.posy] = pen1.currentBrush;
				floor1.posx++;
			}
			else
				floor1.posx++;
			}
			else if (floor1.posx == 20){
				cout << "You've hit a wall" << endl;
				i = spaces;
			}
			break;

	case 'E':

		for (int i = 0; i < spaces; i++)
			if (floor1.posy < 20){
			if (pen1.down)
			{
				floor1.floor[floor1.posx][floor1.posy] = pen1.currentBrush;
				floor1.posy++;
			}
			else
				floor1.posy++;
			}
			else if (floor1.posy == 20){
				cout << "You've hit a wall" << endl;
				i = spaces;
			}
			break;

	case 'W':
		for (int i = 0; i < spaces; i++)
			if (floor1.posy > 1){
			if (pen1.down)
			{
				floor1.floor[floor1.posx][floor1.posy] = pen1.currentBrush;
				floor1.posy--;
			}
			else
				floor1.posy--;
			}
			else if (floor1.posx == 1){
				cout << "You've hit a wall" << endl;
				i = spaces;
			}
			break;}
	cout << "The turtle's current position is now (" << floor1.posx << "," << floor1.posy << ")" << endl;}

/***************************************************************************************************
*
*   Function Name     :		placeTurtle
*
*   Purpose           :		Sets the posx and posy coordinates to the turtle avatar
*
*   Input Parameters  :		floor.posx, floor.posy
*
*	Output parameters :		avatar
*
*   Return Value      :		none
*
***************************************************************************************************/
void turtle::placeTurtle(){
	floor1.floor[floor1.posx][floor1.posy] = avatar;}

/***************************************************************************************************
*
*   Function Name     :		jump
*
*   Purpose           :		Allows the turtle to jump to user defined x and y coordinates
*
*   Input Parameters  :		floor.tempx, floor.tempy
*
*	Output parameters :		floor.posx, floor.posy
*
*   Return Value      :		none
*
***************************************************************************************************/
void turtle::jump(){
	if (cin.fail() == true || floor1.tempx < 1 || floor1.tempx>20 || floor1.tempy < 1 || floor1.tempy>20
		|| floor1.tempx != floor(floor1.tempx) || floor1.tempy != floor(floor1.tempy)){
		cin.clear();
		cin.ignore(100, '\n');	
		cout << "Invalid jump input" << endl;
	}
	else{
		floor1.posx = floor1.tempx;
		floor1.posy = floor1.tempy;
		cout << "Jump to (" << floor1.posx << "," << floor1.posy << ") was sucessful" << endl;}}

/***************************************************************************************************
*
*   Function Name     :		status
*
*   Purpose           :		Displays the current status on the console 
*
*   Input Parameters  :		floor.posx, floor.posy, pen.down, direction.currentDir
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void turtle::status(){
	cout << "Pen = ";
	if (pen1.down){
		cout << "down, ";} else{ cout << "up, ";}
		cout << "Direction = " << direction1.currentDir << ", " <<
		"Position = (" << floor1.posx << "," << floor1.posy << ")" << endl;}