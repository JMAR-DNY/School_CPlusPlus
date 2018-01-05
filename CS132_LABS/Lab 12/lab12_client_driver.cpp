#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "sort_algorithms.t"


using namespace std;

ifstream inFile1, inFile2;
ofstream outFile1, outFile2;
int run1[10];
int run2[10];
int temp;

int *p1, *p2;

bool outFileChoice = true;
bool * ofc;



int main() {

	ofc = &outFileChoice;
	p1 = run1;
	p2 = run2;

	inFile1.open("infile1.txt");
	inFile2.open("infile2.txt");
	outFile1.open("outfile1.txt");
	outFile2.open("outfile2.txt");

	while (inFile1) {//while loop to parse data from infile

		for (int i = 0; i < 10;) {
			inFile1 >> temp;
			if (temp != 1) {
				run1[i] = temp;
				i++;}
			else {
				i++;}}

		//FIND CORRECT SYNTAX FOR BUBBLESORT
		bubbleSort *(p1, 10, <(run1, run1));


		if (outFileChoice) {
			for (int i = 0; i < 10; i++) {
				outFile1 << run1[i] << ' ';}}
		else
			for (int i = 0; i < 10; i++) {
				outFile2 << run1[i] << ' ';}

		outFileChoice = !outFileChoice;
		
	}//end while loop to read infile and parse data


}
