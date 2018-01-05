////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_P1_driver.cpp
//
// This program		 : Creates a turtle on a 20x20 floor.  The turtle can navigate the floor with guidance
//						from user input.  Furthermore, the turtle can draw shapes by leaving brushstrokes
//						behind him while he walks around the floor.
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 10/3/15
//
// Date last revised : 10/20/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

#include"turtle.h"
#include"pen.h"
#include"direction.h"
#include"position.h"

void showChoices();
void cclear();
void title();
int choice;

int main(){
	
	//Creates a turtle class object called leonardo
	turtle leonardo;

	//Displays the title &main menu
	title();
	showChoices();

	do{
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			//Change pen position
			leonardo.pen1.down = !leonardo.pen1.down;
			leonardo.pen1.penMsg();
			cclear();
			break;
		case 2:
			//Turn
			cin >> leonardo.direction1.tempDir;
			leonardo.direction1.directionValidation();
			cclear();
			break;
		case 3:
			//Move forwards
			cin >> leonardo.tempSpaces;
			leonardo.floor1.clearPosition(leonardo.pen1);
			leonardo.movement();
			cclear();
			break;
		case 4:
			//Print floor
			leonardo.placeTurtle();
			leonardo.floor1.printFloor();
			leonardo.status();
			cclear();
			break;
		case 5:
			//Change brush
			leonardo.pen1.changeBrush();
			cclear();
			break;
		case 6:
			//Start Over
			leonardo.floor1.setDefaultPosition();
			leonardo.floor1.clearFloor();
			leonardo.direction1.currentDir = ('E');
			leonardo.pen1.down = false;
			cclear();
			break;
		case 7:
			//Jump to floor coordinates
			cin >> leonardo.floor1.tempx >> leonardo.floor1.tempy;
			leonardo.floor1.clearPosition(leonardo.pen1);
			leonardo.jump();
			cclear();
			break;
		case 8:
			//Displays the main menu
			showChoices();
			cclear();
			break;
		case 9:
			//Exits the program
			break;
		default:
			cout << "Invalid input" << endl;
			cclear();
			break;}}

	while (choice != 9);
	return 0;}

//Displays the main menu
void showChoices(){
	cout <<"You must choose, but choose wisely:" << endl
		<< "#   command name        # of inputs"<<endl
		<< "1 : Change Pen Position (_)" << endl
		<< "2 : Turn                (_) (_)" << endl
		<< "3 : Move Forwards       (_) (_)" << endl
		<< "4 : Print               (_)" << endl
		<< "5 : Change Brush        (_)" << endl
		<< "6 : Start Over          (_)" << endl
		<< "7 : Jump                (_) (_) (_)" << endl
		<< "8 : See Menu Again      (_)" << endl
		<< "9 : End Program         (_)" << endl;}

//Clears the cin & choice
void cclear(){
	cin.clear();
	cin.ignore(100, '\n');
	choice = NULL;}

//The title screen
void title()
{cout 
<< "     ///////  //  //  //////  ///////  //     //////"<<endl
<< "       //     //  //  //  //    //     //     //	  "<<endl
<< "       //     //  //  ////      //     //     //////"<<endl
<< "       //     //  //  // //     //     //     //     "<<endl
<< "       //     //////  //  //    //     ////// ////// "<<endl <<endl

<< "///////  //////  //////  //  //  /////   //      //////  //"<<endl
<< "  //     //  //  //  //  //  //  //  //  //      //      //"<<endl
<< "  //     ////    //  //  //  //  /////   //      //////  //"<<endl
<< "  //     // //   //  //  //  //  //  //  //      //        "<<endl
<< "  //     //  //  //////  //////  ////    //////  //////  //"<<endl<< endl;}