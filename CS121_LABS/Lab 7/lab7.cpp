/**************************
Jeffrey Marron
CS 121 Mr.MacKay
Lab 7
October 29, 2014
**************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;



int main()
{
	double studentAverage, score, highScore = 0, numberOfGrades = 0, totalForClass=0, highScoreClass=0, 
		totalScore = 0.0, numberOfStudents = 0, avgForClass;
	
	string firstName, lastName;
	
	ifstream inFile;
	inFile.open("E:\\Lab7\\Lab7Data.txt");
	
	while (!inFile.eof() && inFile)
	{
	
	inFile >> firstName >> lastName;
	inFile >> score;

		while (score != -1)
			{
				totalScore = totalScore + score;
				numberOfGrades++;
				inFile >> score;
				if (score > highScore)
				highScore = score;
			}
	
	studentAverage = totalScore / numberOfGrades;
	cout << "The average for " << firstName << ' ' << lastName << " is: " << setprecision (4) << studentAverage << " and the high grade is: "<< highScore << endl;
	
	numberOfStudents++;
	totalForClass = studentAverage + totalForClass;
	
	if (highScore > highScoreClass)
			highScoreClass = highScore;	
	highScore = 0;
	studentAverage = 0;
	totalScore = 0;
	numberOfGrades = 0;
	
	}
	
	avgForClass = totalForClass/numberOfStudents;
	cout << '\n'<< "The average for the class is: " << avgForClass << " and the high grade for the class is: " << highScoreClass << '\n' << endl;

	inFile.close();
	return 0;
}