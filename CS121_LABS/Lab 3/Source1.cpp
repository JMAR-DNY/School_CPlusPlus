//**********************
//Jeffrey Marron
//CS121
//Mr.Mackay
//lab 3
//9/24/14
//**********************

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	string first_name;
	string last_name;

	double loan_ammount;
	double air;
	int years;
	double mir;
	double number_of_payments;
	
	cout << "This progam is for calculating the monthly payment, total ammount paid," << endl;
	cout << "and total interest ammount for your loan.  Enter the following inputs"<< endl;
	cout << "without any special characters or symbols." << endl << endl;

	cout << "Enter your first name and then press Enter: " << endl;
	cin >> first_name;
	
	cout << "Enter your last name and then press Enter: " << endl;
	cin >> last_name;

	cout << "Enter the loan ammount and then press Enter: " << endl;
	cin >> loan_ammount;

	cout << "Enter the annual interest rate and then press Enter: " << endl;
	cin >> air;

	cout << "Enter the number of years of the loan and then press Enter" << endl;
	cin >> years;

	mir = air / 12;
	number_of_payments = years * 12;

	cout << endl;
	cout << left << setw(40) << "Name:" << first_name << " " << last_name << endl;
	cout << setw(40) << "Loan Ammount:" << left << "$ " << loan_ammount << endl;
	cout << setw(40) << "Monthly Interest Rate:" << left << setprecision(2) << fixed << mir << " %" << endl;
	cout << setw(40) << "Number of Payments:" << left << number_of_payments << endl;
	
	mir = mir / 100;
	double monthly_payment = loan_ammount * ((mir * ((pow(1 + mir, number_of_payments) / (pow(1 + mir, number_of_payments) - 1)))));
	
	
	double total_ammount_paid = monthly_payment * number_of_payments;
	double interest_ammount = total_ammount_paid - loan_ammount;
	
	cout << setw(40) << "Monthly Payment:" << left << setprecision(2) << fixed << "$ " << monthly_payment << endl;
	cout << setw(40) << "Total Ammount Paid:" << left << setprecision(2) << fixed << "$ " << total_ammount_paid << endl;
	cout << setw(40) << "Interest Ammount:" << left << setprecision(2) << fixed << "$ " << interest_ammount << endl;



	return 0;
}


