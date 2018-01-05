/**************************
Jeffrey Marron
CS 121 Mr.MacKay
Lab 6
October 22, 2014
**************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void showChoices();

int main()
{
char accountType;
int choice;
double checking, savings, deposit, withdraw, transfer;

ifstream inFile;
inFile.open("F:\\Lab 6\\Lab6Data.txt");
inFile >> savings;
inFile.ignore(100, '\n');
inFile >> checking;
inFile.close();

do
{
	showChoices();
	cin >> choice;
	cout << endl;

	switch (choice)
		{
	case 1:
		cout << "Checking (C) or Savings (S)?";
		cin >> accountType;
		cout << endl;

		switch (accountType)
		{
		case 'C':
			cout << "How much are you depositing?" << endl;
			cin >> deposit;
			while (deposit < 0)
			{
				cin.clear();
				cout << "Invalid Input" << endl << '\n';
				cout << "How much are you depositing?" << endl;
				cin >> deposit;
			}
			checking = checking + deposit;
			cout << "Your checking account balance is now: " << '$' << checking << endl << '\n';
			break;

		case 'S':
			cout << "How much are you depositing?" << endl;
			cin >> deposit;
			while (deposit < 0)
			{
				cin.clear();
				cout << "Invalid Input" << endl << '\n';
				cout << "How much are you depositing?" << endl;
				cin >> deposit;
			}
			savings = savings + deposit;
			cout << "Your savings account balance is now: " << '$' << savings << endl << '\n';
			break;

		default:
			cout << "Invalid Input" << endl << '\n';
		}
	break;

	case 2:
		cout << "Checking (C) or Savings (S)?";
		cin >> accountType;
		cout << endl;

		switch (accountType)
		{
		case 'C':
			cout << "How much are you withdrawing?" << endl;
			cin >> withdraw;
			while ((withdraw < 0) || (withdraw > checking))
			{
				cin.clear();
				cout << "Invalid Input" << endl << '\n';
				cout << "How much are you withdrawing?" << endl;
				cin >> withdraw;
			}
			checking = checking - withdraw;
			cout << "Your checking account balance is now: " << '$' << checking << endl << '\n';
			break;

		case 'S':
			cout << "How much are you withdrawing?" << endl;
			cin >> withdraw;
			while ((withdraw < 0) || (withdraw > savings))
			{
				cin.clear();
				cout << "Invalid Input" << endl << '\n';
				cout << "How much are you withdrawing?" << endl;
				cin >> deposit;
			}
			savings = savings - withdraw;
			cout << "Your savings account balance is now: " << '$' << savings << endl << '\n';
			break;

		default:
			cout << "Invalid Input" << endl << '\n';
		}
		break;

	
	break;

	case 3:
		cout << "Checking (C) or Savings (S)?";
		cin >> accountType;
		cout << endl;

		switch (accountType)
		{
		case 'C':
			cout << "Your checking account balance is: " << '$' << checking << endl << '\n';
			break;
		case 'S':
			cout << "Your savings account balance is: " << '$' << savings << endl << '\n';
			break;
		default:
			cout << "Invalid Input" << endl << '\n';
		}
		break;

	break;


	case 4:
	
		cout << "(C)Checking to Savings ? or" << endl;
		cout << "(S)  Savings to Checking ?";
		cin >> accountType;
		cout << endl;

		switch (accountType)
		{
		case 'C':
			cout << "How much to transfer?" << endl;
			cin >> transfer;
			while ((transfer < 0) || (transfer > checking))
			{
				cin.clear();
				cout << "Invalid Input" << endl << '\n';
				cout << "How much to transfer?" << endl;
				cin >> transfer;
			}
			checking = checking - transfer;
			savings = savings + transfer;
			cout << "Your checking account balance is now: " << '$' << checking << endl;
			cout << "Your savings account balance is now: " << '$' << savings << endl << '\n';
			break;

		case 'S':
			cout << "How much to transfer?" << endl;
			cin >> transfer;
			while ((transfer < 0) || (transfer > savings))
			{
				cin.clear();
				cout << "Invalid Input" << endl << '\n';
				cout << "How much to transfer?" << endl;
				cin >> transfer;
			}
			savings = savings - transfer;
			checking = checking + transfer;
			cout << "Your checking account balance is now: " << '$' << checking << endl;
			cout << "Your savings account balance is now: " << '$' << savings << endl << '\n';
			break;

		default:
			cout << "Invalid Input" << endl << '\n';
		}
		break;

	break;

	case 5:
	return 0;
	break;

	default:
	cout << "Invalid input" << endl;
	}
	}

	while (choice != 5);
	return 0;
	}

	void showChoices()
	{
	cout << "Please choose one of the following options" << endl;
	cout << "1 : Deposit" << endl;
	cout << "2 : Withdraw" << endl;
	cout << "3 : Balance Inquiry" << endl;
	cout << "4 : Transfer money" << endl;
	cout << "5 : Exit" << endl;
	}
