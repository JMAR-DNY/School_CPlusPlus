////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_P3_driver.cpp
//
// This program		 : Reads an infile of maze data, asks user for a set of starting coordinates,
//						then determines whether or not there is a possible way out of the maze.
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 12/01/15
//
// Date last revised : 12/16/15
//
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <stack>
#include "maze.h"

using namespace std;
void title();

int main() {
	title();do {
		maze labyrinth;
		labyrinth.PrintMaze();
		labyrinth.start(labyrinth.row, labyrinth.col);
		labyrinth.sol(labyrinth.row, labyrinth.col, labyrinth.goback);
		labyrinth.~maze();
	} while (true);}
//////  END int main  //////

//title: This function displays the title screen
void title() {cout
		<< "---------------------------------------------------------------------------" << endl
		<< "                 ///       //   ///       //                               " << endl
		<< "                 ////      //   ////      //        Maze Mayhem            " << endl
		<< "                 // //   ////   // //   ////                               " << endl
		<< "                 //  ////  //   //  ////  //         By: JAM               " << endl
		<< "                 //   ///  //   //   ///  //                               " << endl
		<< "---------------------------------------------------------------------------" << endl << endl
		<< "                            Press Enter:                                   " << endl;}