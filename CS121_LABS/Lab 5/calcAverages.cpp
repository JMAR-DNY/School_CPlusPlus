//*******************************************************************
//Jeffrey Marron
//Mr.MacKay
//lab5
//October 15, 2014
//*******************************************************************

#include <iostream>

using namespace std;

  
int main()
{
	char answer; 
	int numscores, counter; 
	double score, total, average; 

	cout << "Do you want to calculate an average (Y or N)?";
 	cin >> answer; 
	cin.ignore(100,'\n');

	while( answer == 'Y' || answer == 'y')
	{
		cout << "How many scores are there to add together?";
		cin >> numscores;				
		counter = 1;  //gives the counter variable the value of 1

		total = 0;				
		while (counter <= numscores)
		{
			cout << "Score number " << counter << ":";
			cin  >> score;
			total += score;
			counter++; //increases the value of the counter variable each time the code is run
		}

		average = total/numscores;	

		cout << "The average is: " << average << "\n";

		cout << "Do you want to calculate another average (Y or N)?";
		cin >> answer; //gives the answer variable a char value.

	}
	
	cout << "See you  later!\n";
	return 0;
}
