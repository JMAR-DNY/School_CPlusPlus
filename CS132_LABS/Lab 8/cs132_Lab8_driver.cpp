////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_Lab8_driver.cpp
//
// This program		 : Takes a text input and puts it into both a stack and a que.  It then evaluates 
//     the top of the stack vs front of the que and pops/deq until both are empty.  If the top/front values
//	   are equal in all cases then the text evaluates as a palindrome.
//
// Programmer        : Jeffrey Marron
//
// Date created      : 10/28/15
//
// Date last revised : 10/28/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include"stack.h"
#include"queue.h"
#include"list.h"

int main(){

	string str, temp;
	Stack<char> s;
	Queue<char> q;
	int i = 0;
	char ch;

	cout << "Enter text: ";

	do{
		getline(cin, str);
		temp = str;
		str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end()); 	cout << endl;

		for (i = 0; i < str.length(); i++){
			ch = str[i];
			q.enQ(ch);
			s.push(ch);}
		i = 0;

		do{
			if (*q.front() == *s.top()){
				i++;
				//cout << *q.front() << *s.top() << endl;
				q.deQ();
				s.pop();
			}
			else{
				cout << "The text " << temp << " is not a palindrome" << endl;
				return 0;
			}

		} while (i != str.length());

		cout << "The text " << temp << " is a palindrome" << endl;
	} 
	while (1 != 0);}
/*
Enter text: live not on evil

The text live not on evil is a palindrome
dad

The text dad is a palindrome
able was i ere i saw elba

The text able was i ere i saw elba is a palindrome
acrobats stab orca

The text acrobats stab orca is a palindrome
a santa dog lived as a devil god at nasa

The text a santa dog lived as a devil god at nasa is a palindrome
ah satan sees natasha

The text ah satan sees natasha is a palindrome
a nut for a jar of tuna

The text a nut for a jar of tuna is a palindrome
i like to eat fried chicken

The text i like to eat fried chicken is not a palindrome
Press any key to continue . . .
*/