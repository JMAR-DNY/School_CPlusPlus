//huffman.h
//programmer: Jeffrey Marron
//definitions and implementations of the huffman class
//and associated structs

#ifndef HUFFMAN_H__
#define HUFFMAN_H__

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <functional>
#include <vector>
#include <sstream>
#include "Tree.h"

using namespace std;

ifstream inFile;

struct characterType
{
	char character;
	unsigned int occurence;
	string code;
};

struct HuffTreeNode
{
	char data;                
	unsigned freq;            
	HuffTreeNode *left, *right; 
	string code;

	HuffTreeNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(HuffTreeNode* l, HuffTreeNode* r)
	{
		return (l->freq > r->freq);
	}
};

class Huffman
{
public:
	vector<characterType> encodeTable;

	priority_queue<HuffTreeNode*, vector<HuffTreeNode*>, compare> PQ;

	string getFileName(ifstream&, string & inFilename);
	Huffman();
	~Huffman();
	//main functions
	void encode(struct HuffTreeNode* root, string str);
	void countChars(ifstream& inFile, characterType array[], int size);
	void prioritize(characterType structArray[], int size);
	void createEncodeFile();
	void printConsole();
	void createCodedFile(ifstream& inFile);
	void decode(ifstream& inFile);
	void loadCodeTable(ifstream& inFile);
};

Huffman::Huffman(){}
Huffman::~Huffman(){}


/***************************************************************************************************
*
*   Function Name     :		print
*
*   Purpose           :		prints the data from the tree
*
*   Input Parameters  :		struct HuffTreeNode* root, string str
*
***************************************************************************************************/
void print(struct HuffTreeNode* root, string str)
{
	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << " " << str << "\n";


	print(root->left, str + "0");
	print(root->right, str + "1");
}
/// END print ///

/***************************************************************************************************
*
*   Function Name     :		getFileName
*
*   Purpose           :		gets the filename from the user
*
*   Input Parameters  :		inFilename
*
*	Output parameters  :	none
*
*   Return Value      :		inFilename
*
***************************************************************************************************/
string Huffman::getFileName(ifstream &, string & inFilename) {
	inFile.close();
	cout << "Enter the input file name: " << flush;
	getline(cin, inFilename);
	do {
		inFile.open(inFilename.c_str());
		if (inFile.is_open()) {
			cout << "'" << inFilename << "': opened" << endl;
			return inFilename;
		}
		else {
			cout << "Invalid file, or file could not be opened, or does not exist. "
				<< endl;
			return inFilename;
		}
	} while (inFile.is_open());
	return inFilename;
}
///END getFileName ///

/***************************************************************************************************
*
*   Function Name     :		encode
*
*   Purpose           :		encodes the values from the tree into binary
*
*   Input Parameters  :		struct HuffTreeNode* root, string str
*
***************************************************************************************************/
void Huffman::encode(struct HuffTreeNode* root, string str)
{
	characterType tempNode;
	if (!root)
		return;

	if (root->data != '$') {
		tempNode.code = str;
		tempNode.character = root->data;
		tempNode.occurence = root->freq;
		encodeTable.push_back(tempNode);
	}

	encode(root->left, str + "0");
	encode(root->right, str + "1");
}
/// END encode ///

/***************************************************************************************************
*
*   Function Name     :		countChars
*
*   Purpose           :		counts the occurence of each character
*
*   Input Parameters  :		ifstream& inFile, characterType array[], int size
*
***************************************************************************************************/
void Huffman::countChars(ifstream& inFile, characterType array[], int size) 
{
	string temp;
	double charCount = 0.0;
	inFile.clear(); //resets the infile
	inFile.seekg(0, ios::beg);
	for (int i = 0; i < size; i++){
		array[i].character = (char)i; //Fill the array of structs with all possible ascii characters
	}

	while (inFile >> temp)
	{
		for (int i = 0; i <= temp.size(); i++)
		{
			charCount += 1.0;
			for (int j = 0; j < size; j++)
			{
				temp[i] = static_cast<char>(toupper(temp[i])); //merges lower and uppercase values
				if (array[j].character == temp[i])
					array[j].occurence += 1;
			}
		}
	}
}
///END countChars ///

/***************************************************************************************************
*
*   Function Name     :		createEncodeFile
*
*   Purpose           :		creates the encode table file
*
*   Input Parameters  :		none
*
***************************************************************************************************/
void Huffman::createEncodeFile() {
	ofstream outFile;
	string temp;
	cout << "Saving Encode Table" << endl << "Enter a filename without an extension:" << endl;
	cin >> temp;
	outFile.open(temp + ".txt");

	for (int i = 0; i < encodeTable.size(); i++) {
		outFile << encodeTable[i].character << "  " << encodeTable[i].code << endl;
	}
	cout << "'" <<temp << ".txt': created" << endl;
	outFile.close();
}
///END createEncodeFile///

/***************************************************************************************************
*
*   Function Name     :		printConsole
*
*   Purpose           :		prints the code table to the console
*
*   Input Parameters  :		none
*
***************************************************************************************************/
void Huffman::printConsole() {
	cout << "Code table: " << endl;

	for (int i = 0; i < encodeTable.size(); i++) {
		cout << encodeTable[i].character << "  " << encodeTable[i].code << endl;
	}
}
///END printConsole///

/***************************************************************************************************
*
*   Function Name     :		prioritize
*
*   Purpose           :		creates a priority queue and then the huffman tree
*
*   Input Parameters  :		characterType structArray[], int size
*
***************************************************************************************************/
void Huffman::prioritize(characterType structArray[], int size) {

	struct HuffTreeNode *left, *right, *top;

	for (int i = 0; i < size; ++i) {
		if ((structArray[i].occurence != 0) && (isalpha(structArray[i].character))) {
			PQ.push(new HuffTreeNode(structArray[i].character, structArray[i].occurence));
		}
	}

	while (PQ.size() != 1)
	{
		left = PQ.top();
		PQ.pop();

		right = PQ.top();
		PQ.pop();

		top = new HuffTreeNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		PQ.push(top);
	}

	encode(PQ.top(), "");
	cout << "code table: created" << endl;
	//print(PQ.top(), "");
}
///END prioritize ///

/***************************************************************************************************
*
*   Function Name     :		createCodedFile
*
*   Purpose           :		creates a coded file
*
*   Input Parameters  :		ifstream& inFile
*
***************************************************************************************************/
void Huffman::createCodedFile(ifstream& inFile) {
	ofstream outFile;
	string temp, temp1;
	cout << "Saving coded File" << endl << "Enter a filename without an extension:" << endl;
	cin >> temp1;
	outFile.open(temp1 + ".txt");

	inFile.clear(); //resets the infile
	inFile.seekg(0, ios::beg);

	while (inFile >> temp)
	{
		for (int i = 0; i <= temp.size(); i++)
		{
			temp[i] = static_cast<char>(toupper(temp[i]));
			for (int j = 0; j < encodeTable.size(); j++) {
				if (encodeTable[j].character == temp[i]) {
					outFile << encodeTable[j].code;
				}
			}
		}
	}
	cout << "'" << temp1 << ".txt':created" << endl;
}
///END createCodedFile///

/***************************************************************************************************
*
*   Function Name     :		decode
*
*   Purpose           :		decodes a coded file
*
*   Input Parameters  :		ifstream& inFile
*
***************************************************************************************************/
void Huffman::decode(ifstream& inFile) {
	inFile.clear(); //resets the infile
	inFile.seekg(0, ios::beg);

	string temp, letter;

	while (inFile >> temp)
	{
		for (int i = 0; i <= temp.size(); i++)
		{
			letter.push_back(temp[i]);
			for (int j = 0; j < encodeTable.size(); j++) {
				if (encodeTable[j].code == letter) {
					cout << encodeTable[j].character;
					letter.clear();
				}
			}
		}
	}
}
///END decode///

/***************************************************************************************************
*
*   Function Name     :		loadCodeTable
*
*   Purpose           :		loads a code table
*
*   Input Parameters  :		ifstream& inFile
*
***************************************************************************************************/
void Huffman::loadCodeTable(ifstream& inFile) {
	inFile.clear(); //resets the infile
	inFile.seekg(0, ios::beg);
	encodeTable.clear();
	characterType tempNode;
	char letter;
	string code, temp;

	while (inFile.good()) {
		inFile >> letter >> code;
		if (isalpha(letter)) {
			tempNode.character = letter;
			tempNode.code = code;
			encodeTable.push_back(tempNode);
		}
	}
}
///END loadCodeTable///
#endif