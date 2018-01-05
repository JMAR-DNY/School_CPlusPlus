// FileName  : maze.cpp
// programmer : J. Marron
// Implementations of the maze class
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <stack>
#include "maze.h"
#include <algorithm>

using namespace std;
string inFilename;

/***************************************************************************************************
*
*   Function Name     :		maze
*
*   Purpose           :		maze constructor.  Creates the maze
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
maze::maze(){
	cin.clear(); cin.ignore();
	cout << "Enter the input file name: " << flush;
	getline(cin, inFilename);
	ifstream inFile(inFilename);
	for (int i = 1; i < 11; i++){
		for (int j = 1; j < 11; j++)
			Floor[i][j] = tiles;}
	//creates corners
	Floor[0][0] = topLeftCorner;
	Floor[0][11] = topRightCorner;
	Floor[11][0] = bottomLeftCorner;
	Floor[11][11] = bottomRightCorner;

	//creates horizontal walls
	for (int i = 1; i < 11; i++)
		Floor[0][i] = horizontalWall;

	for (int i = 1; i < 11; i++)
		Floor[11][i] = horizontalWall;

	//creates verticle walls
	for (int i = 1; i < 11; i++)
		Floor[i][0] = verticleWall;

	for (int i = 1; i < 11; i++)
		Floor[i][11] = verticleWall;
	for (int Q = 0; Q < 100; Q++){
		inFile >> one[Q];
		if (one[Q] == '1'){Floor[((Q / 10 + 1))][(Q - (((Q / 10)) * 10) + 1)] = Wall;}
		if (one[Q] == 'E'){Floor[((Q / 10 + 1))][(Q - (((Q / 10)) * 10) + 1)] = Exit;}}}
////// END Maze //////

/***************************************************************************************************
*
*   Function Name     :		
*
*   Purpose           :		the maze class deconstructor
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
maze::~maze() {
	row = 0;
	col = 0;
	goback = 0;
	CheckTrapped = 0;}
////// END ~maze //////

/***************************************************************************************************
*
*   Function Name     :		PrintMaze
*
*   Purpose           :		prints the maze to the console
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void maze::PrintMaze(){
	for (int i = 0; i < 12; i++){{
			for (int j = 0; j < 12; j++)
				cout << Floor[i][j];}
		cout << endl;}}
////// END printMaze //////

/***************************************************************************************************
*
*   Function Name     :		start
*
*   Purpose           :		maze constructor
*
*   Input Parameters  :		row, col
*
*	Output parameters :		row, col
*
*   Return Value      :		row, col, StartingColumnTemp, StartingRowTemp
*
***************************************************************************************************/
char maze::start(int& row, int& col){
	int StartingColumnTemp, StartingRowTemp;
	cout << "Enter starting x,  y coordinates: " << endl;
	cout << "Enter a number between 1-10 for the starting row: " << endl;
	do{while (row < 1 || row > 10){cin >> row;}

		cout << "Enter a number between 1-10 for the starting column: " << endl;
		while (col <1 || col >10){cin >> col;}

		while (Floor[row][col] != 0){
			cout << "Coordinates are on a wall tile.  Reenter coordinates: " << endl;
			cout << "Enter row: " << endl;
			cin >> row;
			cout << "Enter column: " << endl;
			cin >> col;}
	} while (row < 1 && row && row > 10 && col <1 && col >10 && Floor[row][col] == 0);
	Floor[row][col] = guy;
	colStack.push(col);
	rowStack.push(row);
	StartingColumnTemp = col;
	StartingRowTemp = row;
	return row, col, StartingColumnTemp, StartingRowTemp;}
////// END start //////

/***************************************************************************************************
*
*   Function Name     :		MovingEast
*
*   Purpose           :		Moves the guy East through the maze
*
*   Input Parameters  :		row, col, goback
*
*	Output parameters :		row, col, goback
*
*   Return Value      :		row, col
*
***************************************************************************************************/
char maze::MovingEast(int& row, int& col, int& goback){
	int StartingColumnTemp, StartingRowTemp;
	col = col + 1;

	cout << "Starting column: " << col << endl;
	cout << "Starting row:  " << row << endl;
	for (col; col > 0 && col < 11; col++){
		if (Floor[row][col] == 0 && Floor[row][col] != 'X'){
			Floor[row][col] = movement;
			colStack.push(col);
			rowStack.push(row);
			goback = goback + 1;
			cout << "Row #:" << row << " Column #: " << col << " Has a crumb " << endl;
			CheckTrapped = 0;}

		else{
			if (Floor[row][col] == 'X'){
				cout << "I am FREE!" << endl;
				col = 99;
				return(col);}

			cout << "Wall at: " << row << " " << col << endl;
			cout << "Last column traversed: " << (col - 1) << endl;
			CheckTrapped = CheckTrapped + 1;
			
			if (CheckTrapped >4){
				cout << "Trapped. Going back" << endl;
				colStack.pop();
				rowStack.pop();
				if (colStack.empty() && rowStack.empty()){//row and column stack empty
					cout << "Trapped. Going back" << endl;
					maze::MovingSouth(row, col, goback);
					maze::MovingNorth(row, col, goback);}

				col = colStack.top();//when guy goes back to the beginning
				row = rowStack.top();
				if (colStack.size() == 1 && rowStack.size() == 1){
					maze::MovingWest(row, col, goback);}
				return row, col;}

			cout << "Unable to go East: " << CheckTrapped << endl;
			col = colStack.top();
			row = rowStack.top();
			return row, col;}}

	cout << "Current row: " << row << endl << "Current column: " << col << endl;
	col = colStack.top();
	row = rowStack.top();
	return row, col;}
////// END MovingEast //////

/***************************************************************************************************
*
*   Function Name     :		MovingSouth
*
*   Purpose           :		Moves the guy South through the maze
*
*   Input Parameters  :		row, col, goback
*
*	Output parameters :		row, col, goback
*
*   Return Value      :		row, col
*
***************************************************************************************************/
char maze::MovingSouth(int& row, int& col, int& goback)
{
	int StartingColumnTemp, StartingRowTemp;
	cout << "Starting column: " << col << endl;
	cout << "Starting row: " << row << endl;
	row = row + 1;
	goback = 0;
	for (row; row > 0 && row < 11; row++){
		if (Floor[row][col] == 0 && Floor[row][col] != 'X'){
			Floor[row][col] = movement;
			colStack.push(col);
			rowStack.push(row);
			goback = goback + 1;
			cout << "Row #:" << row << " Column #: " << col << " Has a crumb" << endl;
			CheckTrapped = 0;}
		else{
			if (Floor[row][col] == 'X'){
				cout << "I am FREE!" << endl;
				col = 99;
				return(col);}

			cout << "Wall at: " << row << " " << col << endl;
			CheckTrapped = CheckTrapped + 1;
			cout << "Unable to go South: " << CheckTrapped << endl;
			if (CheckTrapped > 4){
				if (CheckTrapped > 100){//prevents infinite loop condition
					while (!colStack.empty() && !rowStack.empty()){
						colStack.pop();
						rowStack.pop();}
					return(row, col);}
				cout << "Trapped. Going back." << endl;

				colStack.pop();
				rowStack.pop();
				if (colStack.empty() && rowStack.empty()){
					cout << "Help, I'm TRAPPED!" << endl;
					col = 99;
					return(col);}

				StartingColumnTemp = colStack.top();
				StartingRowTemp = colStack.top();
				col = colStack.top();
				row = rowStack.top();
				MovingNorth(row, col, goback);
				return row, col;
			}
			if (colStack.size() == 1 && rowStack.size() == 1){
				maze::MovingNorth(row, col, goback);}
			col = colStack.top();
			row = rowStack.top();
			return row, col;}}
	row = row - 1;
	col = colStack.top();
	row = rowStack.top();
	return row, col;}
////// END MovingSouth

/***************************************************************************************************
*
*   Function Name     :		MovingNorth
*
*   Purpose           :		Moves the guy North through the maze
*
*   Input Parameters  :		row, col, goback
*
*	Output parameters :		row, col, goback
*
*   Return Value      :		row, col
*
***************************************************************************************************/
char maze::MovingNorth(int& row, int& col, int& goback){
	int StartingColumnTemp, StartingRowTemp;
	cout << "Starting column: " << col << endl;
	cout << "Starting row: " << row << endl;
	row = row - 1;
	goback = 0;

	for (row; row > 0 && row < 11; row--){
		if (Floor[row][col] == 0){
			Floor[row][col] = movement;
			colStack.push(col);
			rowStack.push(row);
			goback = goback + 1;
			cout << "This row has a crumb: " << row << endl;
			CheckTrapped = 0;}
		else{
			if (Floor[row][col] == 'X'){
				cout << "I am FREE!" << endl;
				col = 99;
				return(col);}

			cout << "Wall at: " << row << " " << col << endl;
			CheckTrapped = CheckTrapped + 1;
			cout << "Unable to go North: " << CheckTrapped << endl;
			if (CheckTrapped > 4 && CheckTrapped < 8){

				cout << "Trapped. Going back." << endl;
				colStack.pop();
				rowStack.pop();
				if (colStack.empty() && rowStack.empty()){
					cout << "Help, I'm TRAPPED!" << endl;
					col = 99;
					return(col);}
				StartingColumnTemp = colStack.top();
				StartingRowTemp = colStack.top();

				col = colStack.top();
				row = rowStack.top();
				MovingWest(row, col, goback);

				return row, col;}
			row = row + 1;
			col = colStack.top();
			row = rowStack.top();
			return row, col;}
		if (colStack.size() == 1 && rowStack.size() == 1){
			maze::MovingSouth(row, col, goback);}}
	row = row + 1;
	col = colStack.top();
	row = rowStack.top();
	return row, col;}
////// END MovingNorth //////

/***************************************************************************************************
*
*   Function Name     :		MovingWest
*
*   Purpose           :		Moves the guy West through the maze
*
*   Input Parameters  :		row, col, goback
*
*	Output parameters :		row, col, goback
*
*   Return Value      :		row, col
*
***************************************************************************************************/
char maze::MovingWest(int& row, int& col, int& goback){
	int StartingColumnTemp, StartingRowTemp;
	cout << "Starting column: " << col << endl;
	cout << "Starting row: " << row << endl;
	col = col - 1;
	goback = 0;

	for (col; col > 0 && col < 11; col--){
		if (Floor[row][col] == 0){
			Floor[row][col] = movement;
			colStack.push(col);
			rowStack.push(row);
			goback = goback + 1;
			cout << "This column has a crumb" << col << endl;
			CheckTrapped = 0;}
		else{
			if (Floor[row][col] == 'X'){
				cout << "I am FREE!" << endl;
				col = 99;
				return(col);}

			cout << "Wall at: " << row << " " << col << endl;
			col = col + 1;
			CheckTrapped = CheckTrapped + 1;
			if (CheckTrapped > 4){
				cout << "Trapped. Going back." << endl;

				colStack.pop();
				rowStack.pop();
				if (colStack.empty() && rowStack.empty()){
					cout << "Help, I'm TRAPPED!" << endl;
					col = 99;
					return(col);}
				StartingColumnTemp = colStack.top();
				StartingRowTemp = colStack.top();

				col = colStack.top();
				row = rowStack.top();
				maze::MovingEast(row, col, goback);
				return row, col;}
			cout << "Unable to go West:" << CheckTrapped << endl;
			return row, col;}}
	col = col + 1;
	col = colStack.top();
	row = rowStack.top();
	return row, col;}
////// END MovingWest ////// 

/***************************************************************************************************
*
*   Function Name     :		sol
*
*   Purpose           :		Creates the solution to the maze
*
*   Input Parameters  :		row, col, goback
*
*	Output parameters :		row, col, goback
*
*   Return Value      :		row, col
*
***************************************************************************************************/
char maze::sol(int& row, int& col, int& goback){
	while (Floor[row][col] != 'X' && col !=99){

		maze::MovingEast(row, col, goback);
		maze::PrintMaze();
		if (col > 98) { return col;}
		else
		maze::MovingSouth(row, col, goback);
		maze::PrintMaze();
		if (col > 98) { return col; }
		else
		maze::MovingWest(row, col, goback);
		maze::PrintMaze();
		if (col > 98) { return col; }
		else
		maze::MovingNorth(row, col, goback);
		maze::PrintMaze();
	};
	return row, col;}
////// END sol //////