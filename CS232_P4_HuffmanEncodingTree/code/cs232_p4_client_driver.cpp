////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs232_p4_client_driver.cpp
//
// This program		 : does huffman encoding and decoding to encode txt files and decode binary
//						files using an appropriate code table
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 5/15/2016
//
// Date last revised : 5/16/2016
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "huffman.h"

using namespace std;
//used for main menu operation
string inFilename;
char choice;
//functions native to int main
void cclear();
void displayMenu();
//used to create character array
const int maxSize = 128;
characterType structArray[maxSize];
//declares instance of Huffman
Huffman HUFF;
//characterType tempCharType;

int main() {

	//mainGraph.SimplePrintGraph();

	displayMenu(); //Displays main menu.

	do {
		cin >> choice;
		choice = toupper(choice);
		cout << endl;
		switch (choice) {//Switch case operated menu.

		case 'L': {//Loads a plain text file
			cclear();
			HUFF.getFileName(inFile, inFilename);
			HUFF.encodeTable.clear();
			HUFF.countChars(inFile, structArray, maxSize);
			HUFF.prioritize(structArray, maxSize);
			break;

		case 'M': {//Displays the menu
			cclear();
			displayMenu();
			break; }
		
		case 'S': {//save table to encode file
			cclear();
			HUFF.createEncodeFile();
			break; }

		case 'C': {//create coded file
			cclear();
			HUFF.createCodedFile(inFile);
			break; }

		case 'D': {//decode coded file
			cclear();
			HUFF.getFileName(inFile, inFilename);
			HUFF.decode(inFile);
			break; }

		case 'G': {//load code table
			cclear();
			HUFF.encodeTable.clear();
			HUFF.getFileName(inFile, inFilename);
			HUFF.loadCodeTable(inFile);
			break; }

		case 'P': {//print code table to console
			cclear();
			HUFF.printConsole();
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

void displayMenu() {
	cout //DisplayMenu: Displays the main menu.
		<< "Choose one of the following options: " << '\n' << '\n' << '\t'
		<< "L: Load a plain text file" << '\n' << '\t'
		<< "S: Save Encode Table to file" << '\n' << '\t'
		<< "C: Encode message to file" << '\n' << '\t'
		<< "P: Display the code table" << '\n' << '\t'
		<< "D: Decode coded message from file" << '\n' << '\t'
		<< "G: Load code table" << '\n' << '\t'
		<< "M: Display the menu" << '\n' << '\t'
		<< "X: Exit the program" << '\n';
}

void cclear() {//cclear: Clears the cin & choice.
	cin.clear();
	cin.ignore(100, '\n');
	choice = NULL;
}