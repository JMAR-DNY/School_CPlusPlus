////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_Lab9_driver.cpp
//
// This program		 : Delares a an array backed que of size 10 and attempts to enter in the entire 
//alphabet.  5 items are then dequeued and then the program attempts to enque the entire alphabet again.  
//
// Programmer        : Jeffrey Marron
//
// Date created      : 11/03/15
//
// Date last revised : 11/04/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include"array_v.h"
#include"q_array.h"

int main(){
	Queue<char> q;
	char temp = 97;
	int i = 0;

	for (i = 0; i < 26; i++){
		q.enQ(temp);
		cout << temp;
		temp = temp+1;}

	cout << endl <<"de-queuing: " << endl;
	for (i = 0; i < 5; i++){
		cout << q.front();
		q.deQ();}

	cout << endl;
	temp = 97;

	cout << "enquing: " << endl;
	for (i = 0; i < 26; i++){
		q.enQ(temp);
		cout << temp;
		temp = temp + 1;}

	cout << endl << "contents of q:" <<endl;
	for (i = 0; i < 10; i++){
		cout << q.front();
		q.deQ();}
	cout << endl;}

/*
q constr
abcdefghij full q!
k full q!
l full q!
m full q!
n full q!
o full q!
p full q!
q full q!
r full q!
s full q!
t full q!
u full q!
v full q!
w full q!
x full q!
y full q!
z
de-queuing:
abcde
enquing:
abcde full q!
f full q!
g full q!
h full q!
i full q!
j full q!
k full q!
l full q!
m full q!
n full q!
o full q!
p full q!
q full q!
r full q!
s full q!
t full q!
u full q!
v full q!
w full q!
x full q!
y full q!
z
contents of q:
fghijabcde
Press any key to continue . . .
*/