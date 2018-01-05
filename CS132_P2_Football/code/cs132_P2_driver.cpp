////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_P2_driver.cpp
//
// This program		 : Reads the NFL standings from an infile.  It then allows the user to manipulate
//					     and view the data while writing the changes to file.
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 10/26/15
//
// Date last revised : 11/08/15
//
////////////////////////////////////////////////////////////////////////////////////////////////
#include "team.h"
#include "standings.h"

int choice;
void displayMenu();
void title();
void cclear();
string inFilename;

int main(){

	standings standtemp, stand;
	title();
	getFileName(inFile, inFilename);
	standtemp.getInfo();
	standtemp.writeFile(outFile);
	inFile.close();
	inFile.open("NFL_Display_output.txt");
	stand.getInfo();
	displayMenu();

	do{
		cin >> choice;
		cout << endl;

		switch (choice){
			//Print current standings
		case 1:{
			stand.print();
			cclear();
			break; }

			//Add a Game
		case 2:{
			stand.AddAGame();
			stand.sortTeam();
			stand.writeFile(outFile);
			cclear();
			break; }

			//Add a Team
		case 3:{
			stand.addTeam();
			stand.sortTeam();
			stand.writeFile(outFile);
			cclear();
			break; }

			//Delete Team
		case 4:{
			stand.deleteTeam();
			stand.writeFile(outFile);
			cclear();
			break; }

			//Display Main Menu
		case 5:{
			displayMenu();
			cclear();
			break; }
			//Exit
		case 6:{
			return 0;
			break; }
		default:{
			cout << "Invalid input" << endl;
			cclear();
			break;}
		}
	}
	while (choice != 6);
	return 0;
}

//displayMenu: This function displays the menu options
void displayMenu(){cout <<endl
	<< "Choose one of the following options: "<< '\n' << '\n' << '\t'
	<< "1: Print Scores" << '\n' << '\t'
	<< "2: Add a Game" << '\n' << '\t'
	<< "3: Add a Team" << '\n' << '\t'
	<< "4: Delete a Team" << '\n' << '\t'
	<< "5: Display Menu" << '\n' << '\t'
	<< "6: Exit" << '\n' << '\n';}

//title: This function displays the title screen
void title(){cout
<< "---------------------------------------------------------------------------" <<endl
<< "              ///   //  //////  //                               " <<endl
<< "              ////  //  //      //          NFL Current Standings" <<endl
<< "              // // //  //////  //                               " <<endl
<< "              //  ////  //      //          By: JAM              " <<endl
<< "              //   ///  //      //////                           " <<endl
<< "---------------------------------------------------------------------------" <<endl<<endl;
}

//Clears the cin & choice
void cclear(){
	cin.clear();
	cin.ignore(100, '\n');
	choice = NULL;
}