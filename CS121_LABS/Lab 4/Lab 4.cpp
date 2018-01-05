//***************************
//Jeffrey Marron
//CS - 121
//Mr. Mackay
//Lab 4
//10/15/2014
//***************************

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num, remainder;
	string x, y;

	cout << "Please input an integer: ";
	cin >> num;

	remainder = num % 2;

	if (num > 0)
	x = "positive";
	else if (num < 0)
	x = "negative";
	else
	x = "zero";

	if (remainder == 0)
	y = "even";
	else
	y = "odd";

	cout << "The number " << num << " is: " << x << " and " << y << endl << endl;



	return 0;
}