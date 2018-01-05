////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs232_p3_client_driver.cpp
//
// This program		 : reads data from an infile into a weighted graph.  It then allows the user
//					   to manipulate the data in the graph and perform traversals
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 5/10/2016
//
// Date last revised : 5/10/2016
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "graph.h"

using namespace std;

string inFilename;
char choice;
void cclear();
void displayMenu();


Graph mainGraph;

int main() {

	mainGraph.SimplePrintGraph();

	displayMenu(); //Displays main menu.

	do {
		cin >> choice;
		choice = toupper(choice);
		cout << endl;

		switch (choice) {//Switch case operated menu.

		case 'L': {//Loads a graph from file into the program
			cclear();
			//cout << "Enter a file name: " << endl;
			mainGraph.getFileName(inFile, inFilename);
			mainGraph.GetGraph();
			break;

		case 'M': {//Displays the menu
			cclear();
			displayMenu();
			break; }

		case 'V': {//lookup vertex
			cclear();
			mainGraph.isVertex();
			break; }

		case 'U': {//lookup uni edge
			cclear();
			mainGraph.isUniEdge();
			break; }

		case 'B': {//lookup bi edge
			cclear();
			mainGraph.isBiDirEdge();
			break; }

		case 'A': {//adds a vertex
			cclear();
			mainGraph.AddVertex();
			break; }

		case 'Q': {//adds uni edge
			cclear();
			mainGraph.AddUniEdge();
			break; }

		case 'K': {//adds bi edge
			cclear();
			mainGraph.AddBiDirEdge();
			break; }

		case 'D': {//deletes a vertex
			cclear();
			mainGraph.DeleteVertex();
			break; }

		case 'W': {//deletes a uni edge
			cclear();
			mainGraph.DeleteUniEdge();
			break; }

		case 'G': {//deletes a bi edge
			cclear();
			mainGraph.DeleteBiDirEdge();
			break; }

		case 'P': {//prints the graph to the console
			mainGraph.SimplePrintGraph();
			cclear();
			break; }

		case 'J': {//performs MST
			mainGraph.mst();
			cclear();
			break; }

		case 'F': {//breadth first graph traversal
			mainGraph.BFTraversal();
			cclear();
			break; }

		case 'N': {//depth first graph traversal
			mainGraph.DFTraversal();
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

void displayMenu() {
	cout //DisplayMenu: Displays the main menu.
		<< "Choose one of the following options: " << '\n' << '\n' << '\t'
		<< "L: Load a new file" << '\n' << '\t'
		<< "V: Lookup Vertex" << '\n' << '\t'
		<< "A: Add a Vertex" << '\n' << '\t'
		<< "D: Delete Vertex" << '\n' << '\t'
		<< "U: Lookup uni-directional edge" << '\n' << '\t'
		<< "Q: Add a uni-edge" << '\n' << '\t'
		<< "W: Deletes a uni-edge" << '\n' << '\t'
		<< "B: Lookup bi-directional edge" << '\n' << '\t'		
		<< "K: Add a bi-edge" << '\n' << '\t'		
		<< "G: Deletes a Bi-edge" << '\n' << '\t'
		<< "J: Minimum Spanning Tree" << '\n' << '\t'
		<< "F: Breadth First Traversal" << '\n' << '\t'
		<< "N: Depth First Traversal" << '\n' << '\t'
		<< "M: Display the menu options" << '\n' << '\t'
		<< "P: Print" << '\n' << '\t'
		<< "X: Exit the program" << '\n';

}

void cclear() {//cclear: Clears the cin & choice.
	cin.clear();
	cin.ignore(100, '\n');
	choice = NULL;
}