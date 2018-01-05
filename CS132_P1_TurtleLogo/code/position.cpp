// FileName   : position.cpp
// programmer : J. Marron
// non templated implementations of the position class

#include "position.h"
#include "turtle.h"
#include "direction.h"
#include "pen.h"
#include <iostream>

//Default position constructor
position::position(){
	// initializes the floor
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
			floor[i][j] = tiles;
	}

	//defines the floor borders
	const unsigned char topLeftCorner = 201;
	const unsigned char topRightCorner = 187;
	const unsigned char bottomLeftCorner = 200;
	const unsigned char bottomRightCorner = 188;
	const unsigned char verticleWall = 186;
	const unsigned char horizontalWall = 205;

	//creates corners
	floor[0][0] = topLeftCorner;
	floor[0][21] = topRightCorner;
	floor[21][0] = bottomLeftCorner;
	floor[21][21] = bottomRightCorner;

	//creates horizontal walls
	for (int i = 1; i < 21; i++)
		floor[0][i] = horizontalWall;

	for (int i = 1; i < 21; i++)
		floor[21][i] = horizontalWall;

	//creates verticle walls
	for (int i = 1; i < 21; i++)
		floor[i][0] = verticleWall;

	for (int i = 1; i < 21; i++)
		floor[i][21] = verticleWall;

	posx = 1;
	posy = 1;}

/***************************************************************************************************
*
*   Function Name     :		printfloor
*
*   Purpose           :		Prints the array
*
*   Input Parameters  :		none
*
*	Output parameters :		floor[][]
*
*   Return Value      :		none
*
***************************************************************************************************/

void position::printFloor(){
	for (int i = 0; i < 22; i++)
	{
		{
			for (int j = 0; j < 22; j++)
				cout << floor[i][j];
		}
		cout << endl;}}

/***************************************************************************************************
*
*   Function Name     :		setDefaultPosition
*
*   Purpose           :		Resets posx and posy to their default values
*
*   Input Parameters  :		none
*
*	Output parameters :		posx, posy
*
*   Return Value      :		none
*
***************************************************************************************************/

void position::setDefaultPosition(){
	posx = 1;
	posy = 1;}

/***************************************************************************************************
*
*   Function Name     :		clearPosition
*
*   Purpose           :		Clears the turtle character from the floor
*
*   Input Parameters  :		pen.down, floor[][]
*
*	Output parameters :		pen.currentBrush, tiles
*
*   Return Value      :		none
*
***************************************************************************************************/
void position::clearPosition(pen n){
	if (n.down)
	{
		floor[posx][posy] = n.currentBrush;
	}
	else{
		floor[posx][posy] = tiles;}}

/***************************************************************************************************
*
*   Function Name     :		clearFloor
*
*   Purpose           :		Clears the floor
*
*   Input Parameters  :		floor[][]
*
*	Output parameters :		tiles
*
*   Return Value      :		none
*
***************************************************************************************************/
void position::clearFloor(){
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
			floor[i][j] = tiles;}
	cout << "Temporal shift completed. Floor is clear" << endl;}