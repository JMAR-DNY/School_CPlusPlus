////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_P4_driver.cpp
//
// This program		 : Reads an infile of employee records into a binary search tree then allows 
//						the user to view, manipulate the data, and save to a separate file.
//						This program updates record with SSN input
// 
// Programmer        : Jeffrey Marron
//
// Date created      : 12/08/15
//
// Date last revised : 12/17/15
//
////////////////////////////////////////////////////////////////////////////////////////////////
#include "employee.h"
#include "tree.h"
#include "oxy.h"

using namespace std;
string inFilename;
char choice;

void displayMenu();
void title();
void cclear();
void printHeader();
void printFooter();
employee bob;

int main() {
	oxy gen;
	title();
	displayMenu();

	do {cin >> choice;
		choice = toupper(choice);
		cout << endl;

		switch (choice) {//switch case operated menu
			
		case 'G': {//Gets record from employee file and stores alpabetically
			cclear();
			gen.etree.~tree();//Clears tree data. Allows new tree to be created from a new file
			gen.getFileName(inFile, inFilename);//gets input file name
			gen.getInfo();//parses data from infile into the tree
				break;}
			  
		case 'I': {//Inserts record for new employee
			cclear();
			gen.addEmployee();
				break; }
				  
		case 'U': {//Update record of employee in tree
			cout << "Enter an employee's SSN to modify their record: " << endl;
			cin >> bob.ssn;
			cclear();
			gen.etree.tempOut(bob, outFile);//finds node in tree, creates temp, deletes node
			gen.modEmployee(inFile);//modify the temp and reinsert into the tree
			cclear();
				break; }
			  
		case 'R': {//Retrieve and display record of a specific employee
			cout << "Enter an employee's SSN to view their record: " << endl;
			cin >> bob.ssn;
			printHeader();
			gen.etree.DisplayNodeData(bob);//searches for and couts node data
			printFooter();
			cclear();			
				break; }
				  
		case 'L': {//Lists records in alphabetical order
			gen.etree.writeTree(3);
			gen.printEmployeeList(inFile);//Creates temporary tree
			printHeader();
			gen.ttree.writeTree(2); //Displays temporary tree
			printFooter();
			gen.ttree.~tree(); //Destroys temporary tree
			cclear();
				break; }
			 
		case 'S': {//Copy records into permanent file pre-order transversal
			gen.etree.writeTree(1);//creates temp in pre-order
			gen.saveToFile(inFile, saveFile);//parses appropriately to read-in format
			cclear();
				break; }
				  
		case 'D': {//Delete record of an employee from the tree
			cout << "Enter an employee's SSN to remove them from the database:" << endl;
			cin >> bob.ssn;
			gen.etree.SearchAndDestroy(bob);//search and remove node
			cout << "Returning to main database console" << endl;
			cclear();
				break; }
	  
		case 'M': {//Displays the main menu
			cclear();
			displayMenu();
				break; }
	  
		case 'E': {//Exit
			return 0;break; }
		default: {
			cout << "Invalid input" << endl; cclear(); break; }}} 
	while (choice != 'E');
	return 0;}
//////  END int main  //////

void displayMenu() {cout //displayMenu: Displays the main menu
		<< "Choose one of the following options: " << '\n' << '\n' << '\t'
		<< "G: Get employee file" << '\n' << '\t'
		<< "I: Insert new employee" << '\n' << '\t'
		<< "U: Update an employee record" << '\n' << '\t'
		<< "R: Retrieve an employee record" << '\n' << '\t'
		<< "L: List the records" << '\n' << '\t'
		<< "S: Save to file" << '\n' << '\t'
		<< "D: Delete a record" << '\n' << '\t'
		<< "M: Display Menu" << '\n' << '\t'
		<< "E: Exit" << '\n' << '\n';}

void cclear() {//cclear: Clears the cin & choice
	cin.clear();
	cin.ignore(100, '\n');
	choice = NULL;}

void printHeader() {//printHeader: Prints output Header
	cout << "First      Last            SSN           Age  Dep  Emp  Rate   Hours  $ Pay " << endl;
	cout << "----------------------------------------------------------------------------" << endl;}

void printFooter() {//printFooter: Prints output Footer
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "  (Dep:Dependents)  (Emp:Employee Type)  (F:Factory)  (O:Office)  (S:Sales)  " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Returning to main database console" << endl;}

void title() {cout //title: Displays the title screen
   << "---------------------------------------------------------------------------" << endl
   << "              //////  //       //   //////                                 " << endl
   << "              //      ////    ///  //         Employee Management System   " << endl
   << "              //////  // //  ////   /////                                  " << endl
   << "              //      //  //// //       //    By: JAM                      " << endl
   << "              //////  //   //  //  //////                                  " << endl
   << "---------------------------------------------------------------------------" << endl << endl;}