////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs232_p1_client_driver.cpp
//
// This program		 : reads in data from an action table and transition table files and stores
//					   them in tables.  It then uses that data to allow the user to test a
//					   4 digit lock in the form of a virtual finite state machine 
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 2/10/16
//
// Date last revised : 2/29/16
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
#include "table.h"
#include "pair.h"
#include <stdlib.h>

string inFilename;
int nState;
char tState, choice;
void cclear();
void displayMenu();

int f3(int e) {return e;}   //Mapping function.

Table<int, int, int> t(f3); //Initializes transition table.
Table<int, int, int> a(f3); //Initializes action table.

Pair<int, int, int> pTemp(nke, A, 0); //Initializes a temporary pair.

int main() {

	displayMenu(); //Displays main menu.

	do {
		cin >> choice;
		choice = toupper(choice);
		cout << endl;

		switch (choice) {//Switch case operated menu.

		case 'T': {//Loads a transition table from file into the program
			cclear();
			t.clear();
			cout << "Enter a transition table file name: " << endl;
			t.getFileName(inFile, inFilename);
			t.getAtInfo();
				  break;

		case 'A': {//Loads an action table from file into the program
			cclear();
			a.clear();
			cout << "Enter an action table file name: " << endl;
			a.getFileName(inFile, inFilename);
			a.getAtInfo();
			break; }
		
		case 'M': {//Displays the menu
			cclear();
			displayMenu();
			break; }

		case 'E': {//Enters the 4 digit access code
				cout << "Enter 4 letter code: " << endl;
				cin >> tState;
				pTemp.second = (tState % 97);//Converts entered character into numeric value.
				t.lookUp(pTemp, nState); 	 //Puts the data into the temp pair and searches 
				pTemp.first = nState;		 //the table for that pair.  Stores returned data
											 //into the temp pair to alter table coords.
				cin >> tState;
				pTemp.second = (tState % 97);
				t.lookUp(pTemp, nState);
				pTemp.first = nState;

				cin >> tState;
				pTemp.second = (tState % 97);
				t.lookUp(pTemp, nState);
				pTemp.first = nState;

				cin >> tState;
				pTemp.second = (tState % 97);//fourth digit entered.  now checks action table
				a.lookUp(pTemp, nState);	 //Looks up the current coords from the temp pair
				pTemp.first = nState;		 //inside the action table. 

				pTemp.first = nke, pTemp.second = A; //Resets the table coords in temp pair.
				
			cout << endl<<"Returning to main menu" << endl;
			cclear();
			break; }

		case 'X': {//Exits the program
			return 0; break; }
		default: {
			cout << "Invalid input" << endl; cclear(); break; }
		}
	} 
} while (choice != 'X');
return 0;
}

void displayMenu() {cout //DisplayMenu: Displays the main menu.
		<< "Choose one of the following options: " << '\n' << '\n' << '\t'
		<< "T: Load a new Transition Table" << '\n' << '\t'
		<< "A: Load a new Action Table" << '\n' << '\t'
		<< "M: Display the menu options" << '\n' << '\t'
		<< "E: Enter the 4 digit access code" << '\n' << '\t'
		<< "X: Exit the program" << '\n';}

void cclear() {//cclear: Clears the cin & choice.
	cin.clear();
	cin.ignore(100, '\n');
	choice = NULL;}