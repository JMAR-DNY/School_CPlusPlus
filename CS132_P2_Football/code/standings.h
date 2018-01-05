// FileName  : standings.h
// programmer : J. Marron
// definitions and implementations of the standings class
#ifndef STANDINGS_H
#define STANDINGS_H

#include <iostream>
#include "team.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stdio.h>
#include <time.h>

using namespace std;

ifstream inFile;
ofstream outFile;

class standings: public team
{
public:	
	list<team> teamlist;
	team data;
	string str, temp, twin, tloss, ttie;
	string inFilename;
	int i = 0;
	
	void getInfo();
	void print();
	void sortTeam();
	string getFileName(ifstream&, string & inFilename);
	void writeFile(ofstream& outfile);
	void addTeam();
	void AddAGame();
	void deleteTeam();
};

/***************************************************************************************************
*
*   Function Name     :		getInfo
*
*   Purpose           :		reads from the infile, places the data into a list node, pushes back listnode
*
*   Input Parameters  :		inFile
*
*	Output parameters :		teamName, win, loss, tie, pct, hwin, hloss, htie, rwin, rloss, rtie,
*						    dwin, dloss, dtie, div
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::getInfo(){
	//Evaluate whitelines/empty lines
	while (inFile.good()){

		//checks input for whitespaces and blank lines
		while (getline(inFile, str)){
			if (str.empty()){
				break;}
			else{		
				while (str[i] != '\0') {
					if (isspace(str[i])){
						i++;
						if (i = str.length()){
							getline(inFile, str);}}
					else{
						break;}}}

			//puts str into the stringstream iss
			stringstream iss(str);

			//Name
			getline(iss, temp, '\t');
			data.teamName = temp;

			//Win
			getline(iss, temp, '\t');
			while (temp[0] == 0){
				getline(iss, temp, '\t');}

			data.win = atoi(temp.c_str());

			//Loss
			getline(iss, temp, '\t');
			data.loss = atoi(temp.c_str());

			//Tie
			getline(iss, temp, '\t');
			data.tie = atoi(temp.c_str());

			//PCT
			getline(iss, temp, '\t');
			data.pct = atof(temp.c_str());

			//Home
			getline(iss, temp, '\t');
			stringstream jss(temp);
			getline(jss, twin, '-');

			data.hwin = atoi(twin.c_str());

			getline(jss, tloss, '-');
			data.hloss = atoi(tloss.c_str());

			getline(jss, ttie, '-');
			data.htie = atoi(ttie.c_str());

			//Road
			getline(iss, temp, '\t');
			stringstream kss(temp);
			getline(kss, twin, '-');

			data.rwin = atoi(twin.c_str());

			getline(kss, tloss, '-');
			data.rloss = atoi(tloss.c_str());

			getline(kss, ttie, '-');
			data.rtie = atoi(ttie.c_str());

			//Division
			getline(iss, temp, '\t');
			stringstream lss(temp);
			getline(lss, twin, '-');

			data.dwin = atoi(twin.c_str());

			getline(lss, tloss, '-');
			data.dloss = atoi(tloss.c_str());

			getline(lss, ttie, '-');
			data.dtie = atoi(ttie.c_str());

			//Div number
			getline(iss, temp, '\n');
			data.div = atoi(temp.c_str());

			/* debugging to read imput from infile into list
			cout.width(20); cout << left << data.teamName << '\t' << data.win << '\t' << data.loss
				<< '\t' << data.tie << '\t' << fixed << setprecision(3) << data.pct << '\t' <<
				data.hwin << '-' << data.hloss << '-' << data.htie << '\t' <<
				data.rwin << '-' << data.rloss << '-' << data.rtie << '\t' <<
				data.dwin << '-' << data.dloss << '-' << data.dtie <<
				//'\t' << data.div << 
				endl;*/
			teamlist.push_back(data);}}
}

/***************************************************************************************************
*
*   Function Name     :		print
*
*   Purpose           :		prints the list data to the console
*
*   Input Parameters  :		teamlist
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::print(){
	/*
	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout << ltm->tm_mday << '-' << 1 + ltm->tm_mon << '-' << 1900 + ltm->tm_year << endl<<endl;
	*/
	char dateStr[9];
	_strdate_s(dateStr);
	cout << dateStr << endl;


	cout << "American Football Conference"<<endl << endl;
	cout << "AFC EAST" << '\t'<< '\t' << "W"<< '\t' << "L"<< '\t' << "T"<< '\t' << "PCT"
		<< '\t' << "HOME"<< '\t' << "ROAD"<< '\t' << "DIV"<< '\n';

	list<team>::iterator it;
	int divCounter, check=2;
		for (it = teamlist.begin(); it != teamlist.end(); ++it)
		{
			divCounter = it->div;
			
			if (divCounter == 2 && check ==2){
				cout << endl;
				cout << "AFC North" << '\t'<< '\t' << "W"<< '\t' << "L"<< '\t' << "T"<< '\t' << "PCT"
					<< '\t' << "HOME"<< '\t' << "ROAD"<< '\t' << "DIV"<< '\n';
				check = 3;}
			else if (divCounter == 3 && check == 3){
				cout << endl;
				cout << "AFC South" << '\t' << '\t' << "W" << '\t' << "L" << '\t' << "T" << '\t' << "PCT"
					<< '\t' << "HOME" << '\t' << "ROAD" << '\t' << "DIV" << '\n';
				check = 4;}
			else if (divCounter == 4 && check == 4){
				cout << endl;
				cout << "AFC West" << '\t' << '\t' << "W" << '\t' << "L" << '\t' << "T" << '\t' << "PCT"
					<< '\t' << "HOME" << '\t' << "ROAD" << '\t' << "DIV" << '\n';
				check = 5;}
			else if (divCounter == 5 && check == 5){
				cout << endl<<endl;
				cout << "National Football Conference" << endl << endl;
				cout << "NFC East" << '\t' << '\t' << "W" << '\t' << "L" << '\t' << "T" << '\t' << "PCT"
					<< '\t' << "HOME" << '\t' << "ROAD" << '\t' << "DIV" << '\n';
				check = 6;}
			else if (divCounter == 6 && check == 6){
				cout << endl;
				cout << "NFC North" << '\t' << '\t' << "W" << '\t' << "L" << '\t' << "T" << '\t' << "PCT"
					<< '\t' << "HOME" << '\t' << "ROAD" << '\t' << "DIV" << '\n';
				check = 7;}
			else if (divCounter == 7 && check == 7){
				cout << endl;
				cout << "NFC South" << '\t' << '\t' << "W" << '\t' << "L" << '\t' << "T" << '\t' << "PCT"
					<< '\t' << "HOME" << '\t' << "ROAD" << '\t' << "DIV" << '\n';
				check = 8;}
			else if (divCounter == 8 && check == 8){
				cout << endl;
				cout << "NFC West" << '\t' << '\t' << "W" << '\t' << "L" << '\t' << "T" << '\t' << "PCT"
					<< '\t' << "HOME" << '\t' << "ROAD" << '\t' << "DIV" << '\n';
				check = 0;}

			cout.width(20); cout << left << it->teamName << '\t' << it->win << '\t' << it->loss
				<< '\t' << it->tie << '\t' << fixed << setprecision(3) << it->pct << '\t' <<
				it->hwin << '-' << it->hloss << '-' << it->htie << '\t' <<
				it->rwin << '-' << it->rloss << '-' << it->rtie << '\t' <<
				it->dwin << '-' << it->dloss << '-' << it->dtie <<
				endl;}

		cout << endl << 
		"    Glossary:" << '\n' <<"    W : Wins" << '\n' <<"    L : Losses" << '\n' <<"    T : Ties" 
		<< '\n' <<"    PCT : Win Percentage" << '\n' << '\n' <<"    HOME : Home Record" << '\n' <<
		"    ROAD : Road Record" << '\n' <<"    DIV : Division Record" << '\n';
}

//Overload sort() to evaluate division in ascending order
bool compareDiv(const team& first, const team& second){
	return first.div < second.div;
}

//Overload sort() to evaluate pct in descending order
bool comparePct(const team& first, const team& second){
	if (first.div == second.div){
		return first.pct > second.pct;
	}
	else{
		return 0;
	}
}

//Overload sort() to evaluate the teamName in alphabetical order
bool compareName(const team& first, const team& second){
	unsigned int j = 0;
	if ((first.div == second.div) && (first.pct == second.pct)){
		while ((j < first.teamName.length()) && (j < second.teamName.length())){
			if (tolower(first.teamName[j]) < tolower(second.teamName[j])) return true;
			else if (tolower(first.teamName[j]) > tolower(second.teamName[j])) return false;
			++j;
		}
		return (first.teamName.length() > second.teamName.length());
	}
	else{ return 0; }
}
/***************************************************************************************************
*
*   Function Name     :		sortTeam
*
*   Purpose           :		sorts the list nodes by their division, percentage, and names
*
*   Input Parameters  :		teamlist
*
*	Output parameters :		teamlist
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::sortTeam(){	
	teamlist.sort(compareDiv);
	teamlist.sort(comparePct);
	teamlist.sort(compareName);
}

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
string getFileName(ifstream& inFile, string & inFilename)
{
	cout << "Please enter the input file name: " << flush;
	getline(cin, inFilename);
	do
	{
		inFile.open(inFilename.c_str());
		if (inFile.is_open())
		{
			return inFilename;
		}
		else
		{
			cout << "Invalid file, Or File could not be Opened, Or Does Not Exist. " << endl << endl << " This Program Will Terminate" << endl;
			exit(0);
			return 0;
		}
	} while (inFile.is_open());
	return inFilename;
}

/***************************************************************************************************
*
*   Function Name     :		writeFile
*
*   Purpose           :		writes the contents of the list to an outfile
*
*   Input Parameters  :		inFilename
*
*	Output parameters :		ofstream &outFile
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::writeFile(ofstream& outFile){
	outFile.open("NFL_Display_output.txt");
	list<team>::iterator it;
	for (it = teamlist.begin(); it != teamlist.end(); ++it){
		it->pct = double(((double)it->win) / ((double)it->loss + (double)it->win + (double)it->tie));
		outFile.width(20); outFile << left << it->teamName << '\t' << it->win << '\t' << it->loss
			<< '\t' << it->tie << '\t' << fixed << setprecision(3) << it->pct << '\t' <<
			it->hwin << '-' << it->hloss << '-' << it->htie << '\t' <<
			it->rwin << '-' << it->rloss << '-' << it->rtie << '\t' <<
			it->dwin << '-' << it->dloss << '-' << it->dtie << '\t' << it->div <<
			endl;}
	outFile.close();
}

/***************************************************************************************************
*
*   Function Name     :		addTeam
*
*   Purpose           :		adds a new team to teamlist
*
*   Input Parameters  :		teamname, hwin, hloss, htie, rwin, rloss, rtie, dwin, dloss, dtie, div
*
*	Output parameters :		teamname, hwin, hloss, htie, rwin, rloss, rtie, dwin, dloss, dtie, div,
*							pct, win, loss, tie
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::addTeam(){
	int k;
	cout << "Enter a new team name: " << endl;
	cin.ignore();
	getline(cin, temp, '\n');

	k = temp.length();
	for (k; k < 20; k++){
		temp += ' ';}

	temp.resize(20);
	data.teamName = temp;

	cout << "Enter home wins: " << endl;
	cin >> data.hwin;
	cout << "Enter home losses: " << endl;
	cin >> data.hloss;
	cout << "Enter home ties: " << endl;
	cin >> data.htie;

	cout << "Enter road wins: " << endl;
	cin >> data.rwin;
	cout << "Enter road losses: " << endl;
	cin >> data.rloss;
	cout << "Enter road ties: " << endl;
	cin >> data.rtie;

	cout << "Enter division wins: " << endl;
	cin >> data.dwin;
	cout << "Enter division losses: " << endl;
	cin >> data.dloss;
	cout << "Enter division ties: " << endl;
	cin >> data.dtie;

	cout << "Enter division #:" << endl;
	cin >> data.div;

	data.win = data.hwin + data.rwin;
	data.loss = data.hloss+data.rloss;
	data.tie = data.htie+data.rtie;

	data.pct = double(((double)data.win) / ((double)data.loss + (double)data.win + (double)data.tie));

	teamlist.push_back(data);
}

/***************************************************************************************************
*
*   Function Name     :		AddAGame
*
*   Purpose           :		to add a played game into the list so that it modifies the appropriate 
*							list node values
*
*   Input Parameters  :		teamlist, TeamName1, TeamName2, choice
*
*	Output parameters :		teamlist
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::AddAGame()
{
	list<team>::iterator it;

	char choice;

	string TeamName1, TeamName2;

	int CurrentHomeTeam, CurrentRoadTeam, k;

	cout << "Adding a game." << '\n' << "Enter The Home Team : " << '\n';
	
	cin.ignore();
	getline(cin, TeamName1, '\n');

	k = TeamName1.length();
	for (k; k < 20; k++){
		TeamName1 += ' ';}
	
	for (it = teamlist.begin(); it != teamlist.end(); ++it)
	{

		if (TeamName1.compare(it->teamName) ==0)
		{
			cout << "The first team is in the list." << '\n';
			CurrentHomeTeam = it->div;}}

	cout << "Enter The Second Team : " << '\n';
	getline(cin, TeamName2, '\n');
	
	k = TeamName2.length();
	for (k; k < 20; k++){
		TeamName2 += ' ';}

	for (it = teamlist.begin(); it != teamlist.end(); ++it)
	{
		if (TeamName2.compare(it->teamName) == 0)
		{
			cout << "The second team is in the list." << '\n';
			CurrentRoadTeam = it->div;}}

	cout << "Did the home team win?  Yes (Y), No (N), or Tie (T)?" << endl;
	cin >> choice;
	choice = toupper(choice);
	switch (choice)
	{
	case 'Y':
	{
		for (it = teamlist.begin(); it != teamlist.end(); ++it)
		{
			if (TeamName1.compare(it->teamName) == 0)
			{
				it->win = it->win + 1;
				it->hwin = it->hwin + 1;
				if (CurrentHomeTeam == CurrentRoadTeam)
				{
					it->dwin = it->dwin + 1;}}}
		{
			for (it = teamlist.begin(); it != teamlist.end(); ++it)
			{
				if (TeamName2.compare(it->teamName) == 0)
				{
					it->loss = it->loss + 1;
					it->rloss = it->rloss + 1;
					if (CurrentHomeTeam == CurrentRoadTeam)
					{
						it->dloss = it->dloss + 1;
					}}}}}
		break;	

	case 'N':
	{
		for (it = teamlist.begin(); it != teamlist.end(); ++it)
		{
			if (TeamName2.compare(it->teamName) == 0)
			{
				it->win = it->win + 1;
				it->hwin = it->hwin + 1;
				if (CurrentHomeTeam == CurrentRoadTeam)
				{
					it->win = it->dwin + 1;}}}

		for (it = teamlist.begin(); it != teamlist.end(); ++it)
		{
			if (TeamName1.compare(it->teamName) == 0)
			{
				it->loss = it->loss + 1;
				it->rloss = it->rloss + 1;
				if (CurrentHomeTeam == CurrentRoadTeam)
				{
					it->dloss = it->dloss + 1;
				}}}}break;
		
	case 'T':
	{
		for (it = teamlist.begin(); it != teamlist.end(); ++it)
		{
			if (TeamName1.compare(it->teamName) == 0)
			{
				it->tie = it->tie + 1;
				it->htie = it->htie + 1;
				if (CurrentHomeTeam == CurrentRoadTeam)
				{
					it->dtie = it->dtie + 1;}}}

		for (it = teamlist.begin(); it != teamlist.end(); ++it)
		{
			if (TeamName2.compare(it->teamName) == 0)
			{
				it->tie = it->tie + 1;
				it->htie = it->htie + 1;
				if (CurrentHomeTeam == CurrentRoadTeam)
				{
					it->dtie = it->dtie + 1;}}
			}}
		break;

	default:
		{
		cout << "Please Enter Y,N or T" << endl;
		break;}}
}

/***************************************************************************************************
*
*   Function Name     :		deleteTeam
*
*   Purpose           :		removes a team from the list
*
*   Input Parameters  :		TeamName, teamlist
*
*	Output parameters :		teamlist
*
*   Return Value      :		none
*
***************************************************************************************************/
void standings::deleteTeam(){
	list<team>::iterator it;
	string TeamName;
	int k;

	cout << "Enter a team to be deleted from the standings: " << '\n';
	cin.ignore();
	getline(cin, TeamName);

	k = TeamName.length();
	for (k; k < 20; k++){
		TeamName += ' ';
	}

	cout << "Team name entered: " << TeamName << '\n';
	for (it = teamlist.begin(); it != teamlist.end(); ++it)
	{
		if (TeamName.compare(it->teamName) == 0)
		{
			it = teamlist.erase(it);
			cout << "Team removed from the standings: " << TeamName << endl;}}
}

#endif