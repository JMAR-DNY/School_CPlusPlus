/**************************
Jeffrey Marron
CS 121 Mr.MacKay
Lab8
November 12, 2014
**************************/

#include <iostream>
#include <cmath>

using namespace std;

void input(double&, double&, double&, double&, double&);
double findMean(double&, double&, double&, double&, double&);
void findStDev(double, double&, double, double, double, double, double);
void output(double, double);


int main()
{
	double x1, x2, x3, x4, x5;
	double mean, stDev;

	input(x1, x2, x3, x4, x5);
	mean = findMean(x1, x2, x3, x4, x5);
	findStDev(mean, stDev, x1, x2, x3, x4, x5);
	output(mean, stDev);

	return 0;
}



void input(double& x1, double& x2, double& x3, double& x4, double& x5)
{
	cout << "Please enter 5 numbers separated by spaces: " << endl;
	cin >> x1 >> x2 >> x3 >> x4 >> x5;
}

double findMean(double& x1, double& x2, double& x3, double& x4, double& x5)
{
	double mean;
	mean = (x1 + x2 + x3 + x4 + x5) / 5;
	return mean;
}


void findStDev(double mean, double& stDev, double x1, double x2, double x3, double x4, double x5)
{
	double getDev;
	getDev = sqrt((pow((x1 - mean), 2) + pow((x2 - mean), 2) + pow((x3 - mean), 2) + pow((x4 - mean), 2) + pow((x5 - mean), 2)) / 5);
	stDev = getDev;
}


void output(double mean, double stDev)
{
	cout <<"The mean of the 5 numbers is: " << mean << endl;
	cout <<"The standard deviation of the 5 numbers is: " << stDev << endl;
}