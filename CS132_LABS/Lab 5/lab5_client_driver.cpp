////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : lab5_client_driver.cpp
//
// This program		 : takes an input list of data using the STL list class.  allows user to imput
//					   new values, then sorts the list by id number in ascending order.
//
// Programmer        : Jeffrey Marron
//
// Date created      : 10/05/15
//
// Date last revised : 10/06/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

struct student
{
	char firstnm[20], lastnm[20];
	int id, grade;

	bool operator < (const student& rhs)
	{
		return id < rhs.id;
	}
};

int main(){
	ifstream inFile;

	string fileName;

	cout << "Please enter your file name:";
	cin >> fileName;

	inFile.open(fileName.c_str());

	if (!inFile){
		cout << "cannot open the input file" << endl;
		return 1;
	}

	student data;
	std::list<student>l;

	inFile >> data.firstnm >> data.lastnm >> data.id >> data.grade;
	
	while (inFile){

		l.push_back(data);
		
		inFile >> data.firstnm >> data.lastnm >> data.id >> data.grade;
	}
	inFile.close();

	std::list<student>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
		cout << (*i).firstnm << " " << (*i).lastnm << " " << (*i).id << " " << (*i).grade << endl;
	
	cout << "enter a first name: " << endl;	
	cin >> data.firstnm;
	cout << "enter a last name: " << endl;
	cin >> data.lastnm;
	cout << "enter an id number: " << endl;
	cin >> data.id;
	cout << "enter a grade: " << endl;
	cin >> data.grade; 

	l.push_back(data);
	l.sort();

	cout << endl << "The sorted list by id number:" << endl;
	for (i = l.begin(); i != l.end(); ++i)
		cout << (*i).firstnm << " " << (*i).lastnm << " " << (*i).id << " " << (*i).grade << endl;
}
/*
Please enter your file name : disneyin2.txt
Hewey Duck 123 90
Daffy Duck 342 92
Wiley Coyote 432 89
Goofy Dog 654 95
Daisy Duck 145 92
Sylvester PuddyCat 775 86
Tweety Bird 221 87
enter a first name :
Jeffrey
enter a last name :
Marron
enter an id number :
707
enter a grade :
100

The sorted list by id number :
Hewey Duck 123 90
Daisy Duck 145 92
Tweety Bird 221 87
Daffy Duck 342 92
Wiley Coyote 432 89
Goofy Dog 654 95
Jeffrey Marron 707 100
Sylvester PuddyCat 775 86
Press any key to continue . . . */