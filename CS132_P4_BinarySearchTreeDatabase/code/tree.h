// FileName  : tree.h
// programmer Jeff Marron with contributions from B.J. Streller
// Definition and implementations of the tree and tree node classes

#ifndef TREE_H
#define TREE_H

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

template <class BaseData>
struct  TreeNode
{
	BaseData TreeData;
	TreeNode *left, *right;
};

template <class BaseData>
class  tree
{      //friend class stated here;
public:
	tree();
	~tree();
	tree(tree<BaseData> &t);
	tree<BaseData> & operator = (const tree<BaseData> &t);
	void insert(BaseData &item);
	void SearchAndDestroy(BaseData target);
	void tempOut(BaseData target, ofstream & outFile);
	void DisplayNodeData(BaseData target);
	void writeTree(int);
	int fullTree() const;
	int emptyTree() const;
	void preOrder(TreeNode<BaseData> *, ofstream & outFile);
	void postOrder(TreeNode<BaseData> *, ofstream & outFile);
protected:   //helping functions
	void remove(TreeNode<BaseData> * &current);
	void inOrder(TreeNode<BaseData> *);
	
	void destroy(TreeNode<BaseData> *p);
	void copyTreeNode(TreeNode <BaseData>** into,
		TreeNode<BaseData>* from);
	void insertNode(TreeNode<BaseData>** into,
		BaseData& item);
	TreeNode <BaseData>  *getnode(BaseData &item);

private:
	TreeNode<BaseData>  *root;
};

//constructor
template <class BaseData>
tree<BaseData>::tree(){
	root = 0;}

//destructor
template <class BaseData>
tree<BaseData>::~tree(){
	if (root)
		destroy(root);
	root = 0;}

//helping function for destructor and copying functions
template <class BaseData>
void tree<BaseData>::destroy(TreeNode<BaseData> *p){
	if (p){
		destroy(p->left);
		destroy(p->right);
		delete p;}}

//copy constructor: uses helping function copyTreeNode
template <class BaseData>
tree<BaseData> ::tree(tree<BaseData> &t){
	root = 0;
	copyTreeNode(&root, t.root);}

//copy constructor: uses helping functions destroy and copyTreeNode
template <class BaseData>
tree<BaseData> &  tree<BaseData>:: operator = (const tree<BaseData> &t){
	if (this == &t) return *this;
	if (root)
		destroy(root);
	root = 0;
	copyTreeNode(&root, t.root);
	return *this;}

//helping function
template <class BaseData>
void tree<BaseData>::inOrder(TreeNode<BaseData> *p){
	if (p){
		inOrder(p->left);
		cout << p->TreeData;
		inOrder(p->right);}
}//END InOrder;

 /***************************************************************************************************
 *
 *   Function Name     :		preOrder
 *
 *   Purpose           :		Prints the tree in pre-order traversal to outFile
 *
 *   Input Parameters  :		TreeNode<BaseData> *p, outFile
 *
 *	Output parameters  :		outFile
 *
 *   Return Value      :		none
 *
 ***************************************************************************************************/
template <class BaseData>
void tree<BaseData>::preOrder(TreeNode<BaseData> *p, ofstream& outFile){
	if (p){
		outFile << p->TreeData;
		preOrder(p->left, outFile);
		preOrder(p->right, outFile);}
}//END PreOrder;

 /***************************************************************************************************
 *
 *   Function Name     :		postOrder
 *
 *   Purpose           :		Prints the tree in post-order traversal to outFile
 *
 *   Input Parameters  :		TreeNode<BaseData> *p, outFile
 *
 *	Output parameters  :		outFile
 *
 *   Return Value      :		none
 *
 ***************************************************************************************************/
template <class BaseData>
void tree<BaseData>::postOrder(TreeNode<BaseData> *p, ofstream & outFile){
	if (p){
		postOrder(p->left, outFile);
		postOrder(p->right, outFile);
		outFile << p->TreeData;}
}//END PostOrder; */

 //searches for target of the base data type and if found it removes it
 //uses helping function remove
template <class BaseData>
void tree<BaseData>::SearchAndDestroy(BaseData target){
	TreeNode<BaseData> *previous, *current;

	current = root;
	previous = 0;
	while (current && (current->TreeData != target)){
		previous = current;
		if (current->TreeData > target)
			current = current->left;
		else current = current->right;}  //(*while*)
	if (!current){ //target not found
		cout << "target not found " << endl;
		return;}

	//remove requires the actual node in the tree
	if (current == root)  remove(root); 
	else{
		if (previous->left == current) remove(previous->left);
		else remove(previous->right);}
	cout << "Remove: success" << endl;}
//END SearchAndDestroy;

/***************************************************************************************************
*
*   Function Name     :		tempOut
*
*   Purpose           :		Prints a temporary copy of the tree to the outFile
*
*   Input Parameters  :		BaseData target, outFile
*
*	Output parameters :		outFile
*
*   Return Value      :		none
*
***************************************************************************************************/
template <class BaseData>
void tree<BaseData>::tempOut(BaseData target, ofstream & outFile){
	outFile.open("tempOut.txt");
	TreeNode<BaseData> *previous, *current;

	current = root;
	previous = 0;
	while (current && (current->TreeData != target)){
		previous = current;
		if (current->TreeData > target)
			current = current->left;
		else current = current->right;} 
	if (!current) { //target not found
		cout << "target not found " << endl;
		return;}

	if (current == root) {
		outFile << current->TreeData;
		remove(root);}
	else{
		if (previous->left == current) {
			outFile << current->TreeData;
			remove(previous->left);}
		else {
			outFile << current->TreeData;
			remove(previous->right);}}
			outFile.close();}
////// END tempOut  //////

/***************************************************************************************************
*
*   Function Name     :		DisplayNodeData
*
*   Purpose           :		Searches for and prints out a single node to the console
*
*   Input Parameters  :		BaseData target
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
template <class BaseData>
void tree<BaseData>::DisplayNodeData(BaseData target){
	TreeNode<BaseData> *previous, *current;

	current = root;
	previous = 0;
	while (current && (current->TreeData != target)) {
		previous = current;
		if (current->TreeData > target) {
			current = current->left;}

		else {current = current->right;}}
	if (!current){//target not found
		cout << "target not found " << endl;
		return;}
	
	if (current == root) {
		cout << current->TreeData;}
	else{
		if (previous->left == current) {
			cout << current->TreeData;}
	else {
			cout << current->TreeData;}}

}
////// END displayNodeData  //////

//helping function to search and destroy
//important:  the input is the actual pointer inside the tree
template<class BaseData>
void tree<BaseData>::remove(TreeNode<BaseData>* &current){
	TreeNode<BaseData> *previous, *temp;
	// (*the pointer sent in is the parent (left or right) in the tree*)
	temp = current;
	if (current->left == 0 && current->right == 0)  //leaf node
		current = 0;                                //parent is null
	else{
		if (current->left == 0)       //  no left child
			current = current->right; //  replace with right child
		else {                         //  has left child
			temp = current->left;
			previous = current;
			while (temp->right != 0) {
				previous = temp;     // locate TreeNode that has the
				temp = temp->right;}  // largest value smaller than
			                          // the value of TreeNode to be deleted
			current->TreeData = temp->TreeData; // replace with
												//that TreeData
			if (previous == current)      //  replace is left child
				previous->left = temp->left;
			else
				previous->right = temp->left;}}// replace is down rt
										   	   // subtree of left child	
			delete temp;}
//END Delete;

 //returns true if the tree is empty   otherwise false
template<class BaseData>
int tree<BaseData> ::emptyTree()  const{
	return !root;}

//returns true if the tree is full   otherwise false
template<class BaseData>
int tree<BaseData> ::fullTree()   const{
	TreeNode<BaseData> *temp = new TreeNode<BaseData>;

	if (!temp) return 1;
	delete temp;
	return 0;}

//inserts a data item of base data type into the tree
//uses helping function insertnode
template <class BaseData>
void tree<BaseData> ::insert(BaseData &item){
	insertNode(&root, item);}

//helping function for insert
//this takes the address of a pointer to a node and inserts
//item into the ordered binary tree headed
//by that node.  This assumes overloaded comparison operators
//for class BaseData.
template <class BaseData>
void tree<BaseData>::insertNode(TreeNode<BaseData>** into, BaseData& item){
	if (!(*into)){
		*into = getnode(item);
		return;}
	if (item < (*into)->TreeData &&  !((*into)->left))
		(*into)->left = tree<BaseData>::getnode(item);
	else if (item < (*into)->TreeData)
		insertNode(&((*into)->left), item);
	else if (item >= (*into)->TreeData && !((*into)->right))
		(*into)->right = tree<BaseData>::getnode(item);
	else insertNode(&((*into)->right), item);}

//gets storage for a new node to be inserted into the tree
template <class BaseData>
TreeNode <BaseData>*  tree<BaseData>::getnode(BaseData &item){
	TreeNode<BaseData> *temp = new TreeNode<BaseData>;
	if (temp){
		temp->TreeData = item;
		temp->left = 0;
		temp->right = 0;}
	return temp;}

//helping function for copy constructor and =operator
//it copies the ordered tree pointed to by "from" into
//another ordered binary tree whose root
//node has its address in the "into" pointer.

//helping function for copy constructor and =operator
template <class BaseData>
void tree<BaseData>::copyTreeNode(TreeNode <BaseData>** into,
	TreeNode<BaseData>* from){
	if (!from) return;
	insertNode(&(*into), from->TreeData);
	copyTreeNode(&(*into), from->left);
	copyTreeNode(&(*into), from->right);}

/***************************************************************************************************
*
*   Function Name     :		writeTree
*
*   Purpose           :		writes the tree in three different orders: pre,in, post and uses the 
*							helping functions. requires input of a choice 1-2-3 for the order desired.
*
*   Input Parameters  :		choice
*
*	Output parameters :		none
*
*   Return Value      :		none
*
***************************************************************************************************/
template <class BaseData>
void tree<BaseData>::writeTree(int choice){
	switch (choice){
	case 1:											//Saves the pre-order tree to the temp file
		outFile.open("tempOut.txt"); 
		tree<BaseData>::preOrder(root, outFile);
		outFile.close();
		break;
	case 2:											//Prints the in-order tree to the console
		tree<BaseData>::inOrder(root);
		cout << endl;
		break;
	case 3:											//Saves the post-order tree to the temp file
		outFile.open("tempOut.txt");
		tree<BaseData>::postOrder(root, outFile);
		outFile.close();
		cout << endl;
		break;
	default:
		cout << "tree not written" << endl;
	}//end switch
}//end write Tree
#endif