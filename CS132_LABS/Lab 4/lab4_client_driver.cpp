////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : lab4_client_driver.cpp
//
// This program		 : takes an input list of data, deletes the fifth element,
//   allows the user to manipulate the list and then prints it out.
//
// Programmer        : Jeffrey Marron
//
// Date created      : 9/25/15
//
// Date last revised : 9/27/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "list.h"

struct Disney
{
	string name;
	int id;
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

	Disney data;
	List<string> name;
	List<int> id;

	string *nameP;
	int *idP;

	inFile >> data.name >> data.id;
	while (inFile){

		name.insertAfter(data.name);
		id.insertAfter(data.id);

		nameP = name.examine();
		idP = id.examine();
		cout << *nameP << " " << *idP << endl;

		inFile >> data.name >> data.id;
	}
	inFile.close();


	cout << endl;

	cout << "After deleting the fifth element:" << endl;

	inFile.open(fileName.c_str());

	if (inFile){
		name.makeCurrent(5);
		nameP = name.examine();
		name.remove();
		id.makeCurrent(5);
		idP = id.examine();
		id.remove();

	}

	name.first();
	id.first();
	inFile >> data.name >> data.id;
	while (inFile){
		nameP = name.examine();
		idP = id.examine();
		
		if (name.current() != name.count())
		{
			cout << *nameP << " " << *idP << endl;
			name.next();
			id.next();
		}

		else{
			cout << *nameP << " " << *idP << endl;
			break;
		}

		inFile >> data.name >> data.id;
	}
	inFile.close();

	cout << endl;

	cout << "Please enter the name and id: ";
	cin >> data.name >> data.id;

	inFile.open(fileName.c_str());

	if (inFile){
		name.last();
		name.insertAfter(data.name);
		id.last();
		id.insertAfter(data.id);
	}

	name.first();
	id.first();
	inFile >> data.name >> data.id;
	while (inFile){
		nameP = name.examine();
		idP = id.examine();
		cout << *nameP << " " << *idP << endl;
		if (name.current() != name.count()){
			name.next();
			id.next();
		}
		inFile >> data.name >> data.id;
	}
	inFile.close();

	return 0;
}
/*
Please enter your file name : disneyin.txt
daisy 123
donald 345
goofy 654
mickey 593
minnie 489
daffy 432
pluto 765
huey 321
dewey 987
lewey 554
porky 333
buggs 778

After deleting the fifth element :
daisy 123
donald 345
goofy 654
mickey 593
daffy 432
pluto 765
huey 321
dewey 987
lewey 554
porky 333
buggs 778

Please enter the name and id : chip 178
daisy 123
donald 345
goofy 654
mickey 593
daffy 432
pluto 765
huey 321
dewey 987
lewey 554
porky 333
buggs 778
chip 178
Press any key to continue . . .
*/