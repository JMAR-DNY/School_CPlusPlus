// FileName  : list.h
// programmer : J. Marron
// template definitions of the list class

#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
using std::endl;



template <class BaseData>
class List
{
protected:
	struct ListNode
	{
	public:
		BaseData listData;
		ListNode *link;
	};

public:

	List();
	List(List &init);
	~List();
	void first();
	void last();
	void makeCurrent(int position);
	void prev();
	void next();
	int current();
	int count();
	void insertBefore(const BaseData &item);
	void insertAfter(const BaseData &item);
	void remove();
	void replace(BaseData &item);
	BaseData * examine();
	List<BaseData>& operator = (List<BaseData> &source);
	void destroy();

protected:

	ListNode *head, *currentNode, *previous;
	int numNodes;
	int currentPos;

};

#include "list.t"

#endif
