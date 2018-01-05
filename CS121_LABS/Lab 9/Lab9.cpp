/**************************
Jeffrey Marron
CS 121 Mr.MacKay
Lab 9
December 2, 2014
**************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;



int main()
{
	ifstream inFile;
	inFile.open("S:\\Mackay\\Lab9Data.txt");

	char studentId[8];
	char studentAnswers[20];
	char correctAnswers[20];
	int i;
	double grade = 0;
	
	
		for (i = 0; i < 20; i++)
			inFile >> correctAnswers[i];

		inFile.ignore(100, '\n');

//code for loop

		while (!inFile.eof() && inFile)
		{
			
			for (i = 0; i < 8; i++)
				inFile >> studentId[i];

			inFile.ignore(100, ' ');

			for (i = 0; i < 20; i++)			
				studentAnswers[i] = inFile.get();
			

			for (i = 0; i < 8; i++)
				cout << studentId[i];

			cout << ' ';

			for (i = 0; i < 20; i++)
				cout << studentAnswers[i];

			cout << setw(5) << right;

			for (i = 0; i < 20; i++)
				if (studentAnswers[i] == ' ')
				{
				grade = grade;
				}
				else if (studentAnswers[i] == correctAnswers[i])
				{
					grade = grade + 2;
				}
				else
				{
					grade = grade - 1;
				}

				cout << grade << ' ';

				grade = grade * 2.5;

				if (grade < 60)
					cout << 'F';
				else if (grade < 70)
					cout << 'D';
				else if (grade < 80)
					cout << 'C';
				else if (grade < 90)
					cout << 'B';
				else
					cout << 'A';
				
				cout << endl;
				
				
				grade = 0;
				
				memset(studentId, 0, 8);
				memset(studentAnswers, 0, 20);
		
		}
		
	inFile.close();
	return 0;
}