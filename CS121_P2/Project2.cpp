/**************************
Jeffrey Marron
CS 121 Mr.MacKay
Project 2
November 12, 2014
**************************/

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

void showChoices(); //the shoChoices function definition used for the main menu
double inputvalidation(double& size); //the input validation loop function definition
string charactervalidation(string& fillChar); //the fill character input validation loop

int main() //main function
{
	//varialbe declarations
	string fillChar;
	int choice, x, y; 
	double size;


	do  //start of the do while loop to show the menu
	{
		showChoices(); //calls the showChoices function which displays the main menu
		cin >> choice; //user inputs a value into the varialbe choice
		
		while (cin.fail() == true || cin.peek() != '\n')
			//while loop to check if the entered choice is a non int character or longer than 1 digit
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Invalid choice.  Enter a number 1-5:" << endl;
			cin >> choice;
		}
		cout << endl;

		switch (choice) //the switch for the main menu choices
		{
		case 1:
			cout << "Pick a size, from 1 through 9:" << endl; //asks for user input
			cin >> size; // user inputs a value into the varialbe size
			cout << endl;
			inputvalidation(size); //calls the input validation function to check for valid input			
			cout << "Pick a fill character:" << endl; // asks for user input
			cin >> fillChar; //user inputs a value into the variable fillChar
			cout << endl;
			charactervalidation(fillChar); //calls the character validation function to check for valid input
			for (y = 0; y < size; y++) //declares y 0, runs the loop if y is less than size, increments y 1
			{

				for (x = 0; x < size; x++) //declares x 0, runs the loop if y is less than size, increments x 1
				{
					if (x == y) //if x and y are equal (row and column) it will output the number in size
						cout << size;
					else //otherwise it will output the fill character.
						cout << fillChar;

				}
				cout << endl;
			}
			cout << endl;
			
				break;
		case 2: //see above
			cout << "Pick a size, from 1 through 9:" << endl;
			cin >> size;
			cout << endl;
			inputvalidation(size);
			cout << "Pick a fill character:" << endl;
			cin >> fillChar;
			cout << endl;
			charactervalidation(fillChar);
			for (y = size; y > 0; y--)
			{

				for (x = 1; x <= size; x++)
				{
					if (x == y)
						cout << size;
					else
						cout << fillChar;

				}
				cout << endl;
			}
			cout << endl;
			break;
		case 3: //see above
			cout << "Pick a size, from 1 through 9:" << endl;
			cin >> size;
			cout << endl;
			inputvalidation(size);
			cout << "Pick a fill character:" << endl;
			cin >> fillChar;
			cout << endl;
			charactervalidation(fillChar);
			for (y = 0; y < size; y++)
			{

				for (x = 0; x < size; x++)
				{
					if (size - y <= size - x)
						cout << size;
					else
						cout << fillChar;

				}
				cout << endl;
			}
			cout << endl;
			break;

		case 4: //see above
			cout << "Pick a size, from 1 through 9:" << endl;
			cin >> size;
			cout << endl;
			inputvalidation(size);
			cout << "Pick a fill character:" << endl;
			cin >> fillChar;
			cout << endl;
			charactervalidation(fillChar);
			for (y = size; y > 0; y--)
			{

				for (x = 1; x <= size; x++)
				{
					if (size - y >= size - x)
						cout << size;
					else
						cout << fillChar;

				}
				cout << endl;
			}
			cout << endl;
			break;

		case 5: //this will return 0 and exit the program
			return 0;
			break;

		default: //If any input is entered that is not one of the defined case numbers then this code runs
			cout << "Invalid choice" << endl << '\n';
			break;
			
			}
		}
	
		while (choice != 5); // do while will run while the choice is not equal to the exit value
		return 0;
	}


void showChoices() //main menu function definition & parameter list
{
	cout << "Your options are: " << endl;
	cout << "1 : A square with a left to right diagonal" << endl;
	cout << "2 : A square with a right to left diagonal" << endl;
	cout << "3 : A square that fills left to right" << endl;
	cout << "4 : A square that fills right to left" << endl;
	cout << "5 : Exit" << endl << '\n';
	cout << "Enter a choice (1-5): " << endl;
}

double inputvalidation(double& size) //input validation loop function definition & parameter list
{
	
	while (cin.fail() == true || size<0 || size>9 || size != floor(size))
		/*checks if there is input failure such as a non number character input, if size is
		less than zero or greater than 9, and if size is not equal to the floor of itself
		i.e. if size is a decimal it would not be equal.		
		*/
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Not a valid size" << endl << '\n';
		cout << "Pick a size, from 1 through 9: " << endl;
		cin >> size;		
	}
	cout << endl;
	return size; //returns a value to the address of the size varialbe
}

string charactervalidation(string& fillChar) //fill character input validation loop
{
	while (fillChar.length() != 1) //if the length of the string fillChar is not equal to 1 the loop runs
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Must enter only one character." << endl << '\n';
		cout << "Enter a character: " << endl;
		cin >> fillChar;
	}
	cout << endl;
	return fillChar; //returns a value to the address of the fillChar variable
}

