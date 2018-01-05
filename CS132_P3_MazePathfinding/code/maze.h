// FileName  : maze.h
// programmer : J. Marron
// definitions of the maze class

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

class  maze
{
public:
	stack<int>rowStack;
	stack<int>colStack;
	maze();
	~maze();
	void PrintMaze();
	int row;
	int col;
	int goback = 0, marker, CheckTrapped = 0, TRAPPED;
	char start(int& row, int& col);
	char MovingEast(int& row, int& StaringColumn, int& goback);
	char MovingSouth(int& row, int& col, int& goback);
	char MovingWest(int& row, int& col, int& goback);
	char MovingNorth(int& row, int& col, int& goback);
	char sol(int& row, int& col, int& goback);

private:
	const unsigned char Wall = 178;
	const unsigned char Exit = 'X';
	const unsigned char tiles = 0;
	const unsigned char topLeftCorner = 201;
	const unsigned char topRightCorner = 187;
	const unsigned char bottomLeftCorner = 200;
	const unsigned char bottomRightCorner = 188;
	const unsigned char verticleWall = 186;
	const unsigned char horizontalWall = 205;
	const unsigned char guy = 42;
	const unsigned char movement = 248;
	char one[100];
	char Floor[12][12];};

#endif