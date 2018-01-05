// FileName  : table.t
// programmer: Jeffrey Marron
// template implementations of the table class

#ifndef  TABLE_H_
#define  TABLE_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>
#include "pair.h"
#include "table.h"

using std::cout;
using std::endl;
ifstream inFile;

enum inputAction { A, B, C, D, E }; //Used to simplify while inserting into different rows.
enum currentState { nke, ok1, ok2, ok3, fa1, fa2, fa3 };

/*************************************************************************************************
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
*************************************************************************************************/
template<class Key, typename T, typename J>
string Table<Key, T, J>::getFileName(ifstream &, string & inFilename)
{
	cout << "Enter the input file name: " << flush;
	getline(cin, inFilename);
	do {
		inFile.open(inFilename.c_str());
		if (inFile.is_open()) {
			cout << "'" << inFilename << "' open: success" << endl;
			return inFilename;
		}
		else {
			cout << "Invalid file, or file could not be opened, or does not exist. "
				<<endl;
			return inFilename;
		}
	} while (inFile.is_open());
	return inFilename;
}
//////  END getFileName  //////

/*************************************************************************************************
*
*   Function Name     :		getAtInfo
*
*   Purpose           :		parses data from a table file
*
*   Input Parameters  :		inFile
*
*	Output parameters :		none
*
*   Return Value      :		none
*
*************************************************************************************************/
template<class Key, typename T, typename J>
void Table<Key, T, J>::getAtInfo()
{
	Pair<Key, T, J> kvpair;
	int i = 0, j = 0, k =0, x = 0;

	while (inFile.good()) {

		//Checks input for whitespaces and blank lines.
		while (getline(inFile, str)) {
			if (str.empty() || str[0] == '\t') { //Evaluates if str is empty or if its a tab space
				break;}							 //to skip empty lines and the column header.
			else {

				stringstream iss(str);

				iss >> skipws >> iTemp;

				for (k = 0; k < 5; k++) {
					iss >> skipws >> iTemp;
					x = iTemp[0] + iTemp[1] + iTemp[2];
					kvpair.first = j, kvpair.second = k, kvpair.third = x;
					insert(kvpair);					
				}
				j++;
			}}}
	inFile.close();
}
//////  END getAtInfo  //////

/*************************************************************************************************
*
*   Function Name     :		print
*
*   Purpose           :		used for debugging purposes to print out the data at [i][j] coords
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
*************************************************************************************************/
template<class Key, typename T, typename J>
void Table<Key, T, J>::print()
{
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 5; j++) {
			cout << the_table[i][j].third << " ";}
		cout << endl;}}
//////  END print  //////

/*************************************************************************************************
*
*   Function Name     :		Table
*
*   Purpose           :		Table class consructor
*
*   Input Parameters  :		int(*map)(Key k)
*
*	Output parameters :		none
*
*   Return Value      :		none
*
*************************************************************************************************/
template < class Key, typename T, typename J >
Table<Key, T, J>::Table(int(*map)(Key k)){
	Mapping = map;

	Pair<Key, T, J> empty = Pair<Key, T, J>(); //Creates an empty pair instance.

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		the_table[i][j] = empty;}  //Fills the table with empty pairs.
}
//////  END Table  //////

/*************************************************************************************************
*
*   Function Name     :		Clear
*
*   Purpose           :		Resets table data to allow new data to be parsed in
*
*   Input Parameters  :		none
*
*	Output parameters :		none
*
*   Return Value      :		none
*
*************************************************************************************************/
template<class Key, typename T, typename J>
void Table<Key, T, J>::clear(){

	Pair<Key, T, J> empty = Pair<Key, T, J>(); //Creates an empty pair instance.

	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 5; j++)
			the_table[i][j]= empty;}} //Fills the table with empty pairs.
//////  END Clear  //////

/***************************************************************************************************
*
*   Function Name     :		insert
*
*   Purpose           :		to insert a pair into the table
*
*   Input Parameters  :		Pair<Key, T> kvpair
*
*	Output parameters :		none
*
*   Return Value      :		bool
*
***************************************************************************************************/
template<class Key, typename T, typename J>
bool Table<Key, T, J>::insert(Pair<Key, T, J> kvpair)
{
	int i = Mapping(kvpair.first); //Evaluates the proper insert coordinates based on the data
	int j = Mapping(kvpair.second);//stored inside of the pair itself.
	if (i < 7 && j < 5 && the_table[i][j].first == NULL)
		the_table[i][j] = kvpair;
	else
		cout << "invalid entry"<<endl;

	return true;
}
//////  END insert  //////

/***************************************************************************************************
*
*   Function Name     :		remove
*
*   Purpose           :		finds and removes a pair from the table
*
*   Input Parameters  :		const Key aKey
*
*	Output parameters :		none
*
*   Return Value      :		bool
*
***************************************************************************************************/
template<class Key, typename T, typename J>
bool Table<Key, T, J>::remove(const Key aKey){
	int i = Mapping(kvpair.first); 
	int j = Mapping(kvpair.second);
	if (the_table[i][j].third != NULL) {
		the_table[i][j].first  = NULL;
		the_table[i][j].second = NULL;
		the_table[i][j].third  = NULL;
		return true;}
	else
		return false;
}
//////  END remove  //////

/***************************************************************************************************
*
*   Function Name     :		lookup
*
*   Purpose           :		determines whether or not a value is in the table
*
*   Input Parameters  :		Pair<Key, T, J> kvpair, int &temp
*
*	Output parameters :		none
*
*   Return Value      :		temp
*
***************************************************************************************************/
template<class Key, typename T, typename J>
int Table<Key, T, J>::lookUp(Pair<Key, T, J> kvpair, int &temp)
{
	int i = Mapping(kvpair.first);
	int j = Mapping(kvpair.second);

	if (the_table[i][j].first == kvpair.first) { //If the transition value in the temp pair in 
											     //main has the same data as the row in the table, 
		temp = the_table[i][j].third;			 //assign the data (target transition) to temp.

		if (temp == 318) {temp = 0;}			 //Table used to assign new coordinates based on
		else if (temp == 267) {temp = 1;}	     //the stored ascii addition data created when
		else if (temp == 268) {temp = 2;}        //the input file was parsed.
		else if (temp == 269) {temp = 3;}
		else if (temp == 248) {temp = 4;}
		else if (temp == 249) {temp = 5;}
		else if (temp == 250) {temp = 6;}
		else if (temp == 302) {
			cout << '\a';						 //302 and 335 only evaluate on the action table 
			cout<< endl<<"alarm"<<endl; }        //as they represent the addition of ala and unl		
		else if (temp == 335) {                  //respectively.
			cout << endl<<"unlock" << endl;}

		return temp;}
	else {
		return temp;}}
//////  END lookup  //////

#endif