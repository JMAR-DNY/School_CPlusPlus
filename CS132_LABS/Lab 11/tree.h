// FileName  : tree.h
// programmer Jeff Marron
// definitions of the tree and tree node classes

#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <tuple>

#ifndef TREE_H_
#define TREE_H_

//header file for a Binary tree with the ordering property
//BaseData class is assumed to have overloaded relational
//> < == !=  <= >=       operators if not a base type

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

	//TreeNode <char> data;

	tree();
	~tree();
	tree(tree<BaseData> &t);
	tree<BaseData> & operator = (const tree<BaseData> &t);
	void insert(BaseData &item);
	void SearchAndDestroy(BaseData target);
	void writeTree(int);
	int fullTree() const;
	int emptyTree() const;

protected:   //helping functions
	void remove(TreeNode<BaseData> * &current);
	void inOrder(TreeNode<BaseData> *);
	void preOrder(TreeNode<BaseData> *);
	void postOrder(TreeNode<BaseData> *);
	void destroy(TreeNode<BaseData> *p);
	void copyTreeNode(TreeNode <BaseData>** into,
		TreeNode<BaseData>* from);
	void insertNode(TreeNode<BaseData>** into,
		BaseData& item);
	TreeNode <BaseData>  *getnode(BaseData &item);

private:
	TreeNode<BaseData>  *root;

};

#include "tree.t"
#endif
