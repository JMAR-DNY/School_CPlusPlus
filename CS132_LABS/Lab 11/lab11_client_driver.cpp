////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : cs132_Lab11_driver.cpp
//
// This program		 : creates a binary search tree and inserts the letters "LTGSHXDEAIMUZJFVBP".
//					   it then prints out the tree in preorder, inorder, and postorder, removes 
//					   the letters "MULES" and reprints the tree.
//
// Programmer        : Jeffrey Marron
//
// Date created      : 11/14/15
//
// Date last revised : 11/14/15
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include "tree.h"

//char data;

using namespace std;
int main()
{
	tree<char> xmas;
	char data;

	data = 'L';
	xmas.insert(data);

	data = 'T';
	xmas.insert(data);

	data= 'G';
	xmas.insert(data);

	data = 'S';
	xmas.insert(data);

	data = 'H';
	xmas.insert(data);

	data = 'X';
	xmas.insert(data);

	data = 'D';
	xmas.insert(data);

	data  = 'E';
	xmas.insert(data);

	data = 'A';
	xmas.insert(data);

	data  = 'I';
	xmas.insert(data);

	data = 'M';
	xmas.insert(data);

	data = 'U';
	xmas.insert(data);

	data = 'Z';
	xmas.insert(data);

	data = 'J';
	xmas.insert(data);

	data = 'F';
	xmas.insert(data);

	data = 'V';
	xmas.insert(data);

	data = 'B';
	xmas.insert(data);

	data = 'P';
	xmas.insert(data);

	//Pre order
	xmas.writeTree(1);

	//In order
	xmas.writeTree(2);

	//post order
	xmas.writeTree(3);

	xmas.SearchAndDestroy(data = 'M');
	xmas.SearchAndDestroy(data = 'U');
	xmas.SearchAndDestroy(data = 'L');
	xmas.SearchAndDestroy(data = 'E');
	xmas.SearchAndDestroy(data = 'S');

	//Pre order
	xmas.writeTree(1);

	//In order
	xmas.writeTree(2);

	//post order
	xmas.writeTree(3);	

	return 0;
}

/*
Pre-Order : LGDABEFHIJTSMPXUVZ
In-Order : ABDEFGHIJLMPSTUVXZ
Post-Order : BAFEDJIHGPMSVUZXTL
Pre-Order : JGDABFHITPXVZ
In-Order : ABDFGHIJPTVXZ
Post-Order : BAFDIHGPVZXTJ
Press any key to continue . . .
*/