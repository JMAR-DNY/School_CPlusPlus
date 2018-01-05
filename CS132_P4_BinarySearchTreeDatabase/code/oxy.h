// FileName  : oxy.h
// programmer : J. Marron
// definitions and implementations of the oxy class
#ifndef OXY_H
#define OXY_H

#include <iostream>
#include "employee.h"
#include "tree.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream inFile;
ofstream outFile, saveFile;
char ochoice;

class oxy : public employee{
public:
	tree<employee> etree, ttree;
	employee peon;

	string inFilename, temp, stream;
	int i = 0, count = 0;
	char tTemp[20];

	void getInfo();										//gets info from infile
	string getFileName(ifstream&, string & inFilename); //gets the inFile name
	void addEmployee();									//adds an employee into the tree
	void modEmployee(ifstream&);						//modify an employee record
	void printEmployeeList(ifstream&);					//prints the employee records to the console
	void saveToFile(ifstream&, ofstream&);};			//prints the employee records to the savefile

void displayEmployeeMenu() {cout << endl//Displays the menu to modify a single employee
		<< "Choose one of the following attributes to modify: " << '\n' << '\n' << '\t'
		<< "F: First Name" << '\n' << '\t'
		<< "L: Last Name" << '\n' << '\t'
		<< "N: Social Security Number" << '\n' << '\t'
		<< "A: Age" << '\n' << '\t'
		<< "D: Dependents" << '\n' << '\t'
		<< "C: Employee Code" << '\n' << '\t'
		<< "S: Salary" << '\n' << '\t'
		<< "H: Hours" << '\n' << '\t'
		<< "M: Display Menu" << '\n' << '\t'
		<< "E: Done/Exit" << '\n' << '\n';}

void oclear() {//oclear: Clears the cin & choice
	cin.clear();
	cin.ignore(100, '\n');
	ochoice = NULL;}

/***************************************************************************************************
*
*   Function Name     :		getInfo
*
*   Purpose           :		parses the inFile and populates the binary tree of employees etree
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void oxy::getInfo() {
	//counts # of commas in the input file to determine # of records
	while (inFile.good()) {
		if (inFile.get() == ',') {count++;}}

	inFile.clear();	//resets input file to beginning
	inFile.seekg(0, ios::beg);

	//parse data from infile into appropriate records
	while (inFile.good() && i != count) {

		inFile.getline(tTemp, 20); stringstream iss(tTemp); getline(iss, temp, ',');
		peon.lastName = temp; iss >> skipws >> temp; peon.firstName = temp; //lastName & firstName

		inFile.getline(tTemp, 20); peon.ssn = tTemp;						//ssn

		inFile.getline(tTemp, 20); peon.age = atoi(tTemp);					//age

		inFile.getline(tTemp, 20); peon.dependents = atoi(tTemp);			//dependents

		inFile.getline(tTemp, 20); peon.eCode = tTemp[0];					//eCode

		inFile.getline(tTemp, 20); peon.salary = atof(tTemp);				//salary

		inFile.getline(tTemp, 20); peon.hours = atof(tTemp);				//hours

		etree.insert(peon); i++;}											//Insert into tree

	cout << "Load to database: success" << endl;}
//////  END getInfo  //////

/***************************************************************************************************
*
*   Function Name     :		getFileName
*
*   Purpose           :		gets the name of the imput file from the user
*
*   Input Parameters  :		ifstream &inFile
*
*	Output parameters :		inFilename
*
*   Return Value      :		inFilename
*
***************************************************************************************************/
string oxy::getFileName(ifstream& inFile, string & inFilename){
	cout << "Enter the input file name: " << flush;
	getline(cin, inFilename);
	do{
		inFile.open(inFilename.c_str());
		if (inFile.is_open()){
			cout << "'"<<inFilename << "' open: success" << endl;
			return inFilename;}
		else{			
				cout << "Invalid file, or file could not be opened, or does not exist. " 
				<< endl << endl << " This program will now terminate." << endl;
			exit(0); return 0;}
	} while (inFile.is_open());
	return inFilename;}
//////  END getFileName  //////

/***************************************************************************************************
*
*   Function Name     :		addEmployee
*
*   Purpose           :		adds a new employee to the binary tree of employees etree
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
inline void oxy::addEmployee(){
	cout << "Add a new employee to the database: " << endl;

	cout << "Enter First Name: " << endl;										//firstName
	cin.getline(tTemp, 50); tTemp[0] = toupper(tTemp[0]); peon.firstName = tTemp;//toupper first letter

	cout << "Enter Last Name: " << endl;										//lastName
	cin.getline(tTemp, 50); tTemp[0] = toupper(tTemp[0]); peon.lastName = tTemp;//toupper first letter

	cout << "Enter SSN: " << endl;
	cin.getline(tTemp, 50); peon.ssn = tTemp;									//ssn

	cout << "Enter Age: " << endl;
	cin.getline(tTemp, 50); peon.age = atoi(tTemp);								//age
	
	cout << "Enter # of Dependents: " << endl;
	cin.getline(tTemp, 50); peon.dependents = atoi(tTemp);						//dependents

	cout << "Enter Employee Code Letter: " << endl;
	cin.getline(tTemp, 50); peon.eCode = tTemp[0];								//eCode

	cout << "Enter Salary: " << endl;
	cin.getline(tTemp, 50); peon.salary = atof(tTemp);							//salary

	cout << "Enter Hours: " << endl;
	cin.getline(tTemp, 50); peon.hours = atof(tTemp);							//hours

	etree.insert(peon);															//insert node
	cout << "New employee '"<<peon.firstName<< ' ' <<peon.lastName<<"' successfully added to the database" 
		<< endl << "Returning to main database console"<<endl;}
//////  END addEmployee  //////

/***************************************************************************************************
*
*   Function Name     :		modEmployee
*
*   Purpose           :		Modifies an employee inside the binary tree of employees etree
*
*   Input Parameters  :		inFile
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
inline void oxy::modEmployee(ifstream & inFile){
	inFile.close();
	inFile.open("tempOut.txt");//opens and parses the one record printed to it to a temp
	inFile >> peon.firstName >> peon.lastName >> peon.ssn >> peon.age >> peon.dependents
		>> peon.eCode >> peon.salary >> peon.hours;
	
	inFile.close();//clean the tempfile
	inFile.open("tempOut.txt", std::ofstream::out | std::ofstream::trunc);
	inFile.close();

	cout << "Employee: " << peon.firstName << ' ' << peon.lastName<<endl;
	displayEmployeeMenu();//Shows the menu to modify an employee record

	do {cin >> ochoice;//switch case operated menu
		ochoice = toupper(ochoice);
		cout << endl;

		switch (ochoice) {
		case 'F': {
			oclear();
			cout << "Enter New First Name: " << endl;
			cin.getline(tTemp, 50); tTemp[0] = toupper(tTemp[0]);	//firstName
			peon.firstName = tTemp;
			break; }
		
		case 'L': {
			oclear();
			cout << "Enter New Last Name: " << endl;
			cin.getline(tTemp, 50); tTemp[0] = toupper(tTemp[0]);	//lastName
			peon.lastName = tTemp;
			break; }

		case 'N':{
			oclear();
			cout << "Enter New SSN: " << endl;
			cin.getline(tTemp, 50); peon.ssn = tTemp;				//ssn
			break; }

		case 'A':{
			oclear();
			cout << "Enter New Age: " << endl;
			cin.getline(tTemp, 50); peon.age = atoi(tTemp);			//age
			break; }
	
		case 'D':{
			oclear();
			cout << "Enter New # of Dependents: " << endl;
			cin.getline(tTemp, 50); peon.dependents = atoi(tTemp);	//dependents
			break; }

		case 'C':{
			oclear();
			cout << "Enter New Employee Code Letter: " << endl;
			cin.getline(tTemp, 50); peon.eCode = tTemp[0];			//eCode
			break; }
	
		case 'S':{
			oclear();
			cout << "Enter New Salary: " << endl;
			cin.getline(tTemp, 50); peon.salary = atof(tTemp);		//salary
			break; }

		case 'H':{
			oclear();
			cout << "Enter New Hours: " << endl;
			cin.getline(tTemp, 50);peon.hours = atof(tTemp);		//hours
			break; }
		
		case 'M': {
			oclear();
			displayEmployeeMenu();									//menu
			break;}

		case 'E': {cout << "Employee: " << peon.firstName << ' ' << peon.lastName //exit
			<< " has been modified" << endl << "Returning to main database console" << endl;		
			break; }
		default: {
			cout << "Invalid input.  Press M to display the Menu" << endl;//default
			oclear();
			break; }
		}
	} while (ochoice != 'E');

	etree.insert(peon);												//insert node
	ochoice = NULL;}												//reset ochoice
//////  END modEmployee  //////

/***************************************************************************************************
*
*   Function Name     :		printEmployeeList
*
*   Purpose           :		Prints the binary tree of employees etree to the console.  Can select what to
*							print out based on the employee code letter.
*
*   Input Parameters  :		inFile
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void oxy::printEmployeeList(ifstream &){
	inFile.close();//Closes current inFile
	inFile.open("tempOut.txt");//Opens copy of employee records from tempOut.txt 
	i = 0;
	count = 0;

	while (inFile.good()) {//Counts # of '-' in the input file to determine # of records
		if (inFile.get() == '-') {count++;}}
			count = (count / 2);//Each record has two '-' thus it determines count by dividing by 2

	inFile.clear();	
	inFile.seekg(0, ios::beg); //Resets input file to beginning

	cout<< "Choose one of the following options to display records: " << '\n' << '\n' << '\t'
		<< "A: All Employees" << '\n' << '\t'
		<< "O: Office Employees" << '\n' << '\t'
		<< "F: Factory Employees" << '\n' << '\t'
		<< "S: Salesmen" << '\n' << '\t'
		<< "E: Exit" << '\n' << '\n';

	do {cin >> ochoice;//switch case operated menu
		ochoice = toupper(ochoice);
		cout << endl;

		switch (ochoice) {
		case 'A': {//Inserts all employees into temporary tree ttree	
			while (inFile.good() && i != count) {
				inFile >> peon.firstName >> peon.lastName >> peon.ssn >> peon.age >> peon.dependents
					>> peon.eCode >> peon.salary >> peon.hours >> peon.pay; peon.ol = 666;
					ttree.insert(peon);  i++;}
			peon.ol = 0;
			ochoice = 'E';//Sets ochoice to exit value to automatically return to main console
			break;}
				  //
		case 'O': {//Inserts office employees into temporary tree ttree
			while (inFile.good() && i != count) {
				inFile >> peon.firstName >> peon.lastName >> peon.ssn >> peon.age >> peon.dependents
					>> peon.eCode >> peon.salary >> peon.hours >> peon.pay; peon.ol = 666;
				if (peon.eCode == 'O') {//Only inserts into tree if eCode is 'O'
					ttree.insert(peon); i++;}
				else i++;}
			peon.ol = 0;
			ochoice = 'E';//Sets ochoice to exit value to automatically return to main console
			break;}

		case 'F': {//Inserts factory employees into temporary tree ttree
			while (inFile.good() && i != count) {
				inFile >> peon.firstName >> peon.lastName >> peon.ssn >> peon.age >> peon.dependents
					>> peon.eCode >> peon.salary >> peon.hours >> peon.pay; peon.ol = 666;
				if (peon.eCode == 'F') {//only inserts into tree if eCode is 'F'
					ttree.insert(peon); i++;}
				else i++;}
			peon.ol = 0;
			ochoice = 'E';//Sets ochoice to exit value to automatically return to main console
			break;}

		case 'S': {//Inserts sales employees into temporary tree ttree
			while (inFile.good() && i != count) {
				inFile >> peon.firstName >> peon.lastName >> peon.ssn >> peon.age >> peon.dependents
					>> peon.eCode >> peon.salary >> peon.hours >> peon.pay; peon.ol = 666;
				if (peon.eCode == 'S') {//only inserts into tree if eCode is 'S'
					ttree.insert(peon); i++;}
				else i++;}
			peon.ol = 0;
			ochoice = 'E';//Sets ochoice to exit value to automatically return to main console
			break; }

		case 'E': {cout << "Returning to main database console" << endl;//exit to main
			break;}
		default: {//default
			cout << "Invalid input" << endl;
			oclear();
			break; }}
	} while (ochoice != 'E');

		inFile.close();//Clears the temporary file tempOut.txt
		inFile.open("tempOut.txt", std::ofstream::out | std::ofstream::trunc);
		inFile.close();
		ochoice = NULL;}
//////  END printEmployeeList  //////

/***************************************************************************************************
*
*   Function Name     :		saveToFile
*
*   Purpose           :		used to save a copy of the tree to file in a way that it can be read
*							back into the program
*
*   Input Parameters  :		inFile, saveFile
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void oxy::saveToFile(ifstream &, ofstream &){
	inFile.close();//Closes current inFile
	inFile.open("tempOut.txt");//Opens copy of employee records from tempOut.txt 
	i = 0;
	count = 0;

	while (inFile.good()) {//Counts # of '-' in the input file to determine # of records
		if (inFile.get() == '-') { count++; }
	}
	count = (count / 2);//Each record has two '-' thus it determines count by dividing by 2

	inFile.clear();
	inFile.seekg(0, ios::beg); //Resets input file to beginning

	saveFile.open("savefile.txt", std::ofstream::out | std::ofstream::trunc);


	while (inFile.good() && i != count) {//parse tempfile into format that can be reread into the program
		inFile >> peon.firstName >> peon.lastName >> peon.ssn >> peon.age >> peon.dependents
			>> peon.eCode >> peon.salary >> peon.hours >> peon.pay;

		saveFile << peon.lastName << ", " << peon.firstName << endl << peon.ssn << endl << peon.age 
			<< endl <<peon.dependents << endl << peon.eCode << endl << peon.salary << endl << 
			peon.hours << endl;	
		i++;}
	saveFile.close();
	cout << "Save: success" << endl;

	inFile.close();//Clears the temporary file tempOut.txt
	inFile.open("tempOut.txt", std::ofstream::out | std::ofstream::trunc);
	inFile.close();
}

#endif