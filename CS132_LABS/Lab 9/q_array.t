// FileName  : array_v.t
// programmer bj streller and general folklore
// template implementations of the Array_V class


#ifndef Q_ARRAY_H_
#define Q_ARRAY_H_

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <new>
using std::bad_alloc;

#include <cassert>  //for asset macro


template <class BaseData>
Queue<BaseData>::Queue()
{
	cout << "q constr " << endl;
	maxQ = 11;
	nodes = new Array_V<int, BaseData>(1, maxQ);
	frontI = 1;
	rearI = maxQ;
}

template <class BaseData>
Queue<BaseData>::Queue(int size)
{
	maxQ = size + 1;
	nodes = new Array<int, BaseData>(1, maxQ);
	frontI = 1;
	rearI = maxQ;
}

template <class BaseData>
Queue<BaseData>::Queue(Queue<BaseData> &initq)

{
	maxQ = initq.maxQ;
	frontI = initq.frontI;
	rearI = initq.rearI;
	nodes = new Array<int, BaseData>(1, maxQ);
	for (int i = 1; i <= maxQ; i++)
		(*nodes)[i] = (*initq.nodes)[i];
}
template <class BaseData>
Queue<BaseData>::~Queue()
{
	delete nodes;
}

template <class BaseData>
int Queue<BaseData>::emptyQ()
{
	return ((rearI % maxQ) + 1 == frontI);
}

template <class BaseData>
int Queue<BaseData>::fullQ()
{
	return (((rearI + 1) % maxQ + 1) == frontI);
}

template <class BaseData>
BaseData Queue<BaseData>::front()
{
	return ((*nodes)[frontI]);
}

template <class BaseData>
void Queue<BaseData>::enQ(BaseData item)
{
	if (!Queue<BaseData>::fullQ())
	{
		rearI = rearI % maxQ + 1;
		(*nodes)[rearI] = item;
	}
	else cout << " full q! " << endl;
}
template <class BaseData>
void Queue<BaseData>::deQ()
{
	if (!Queue<BaseData>::emptyQ())
		frontI = frontI % maxQ + 1;
	else cout << "empty Q " << endl;
}


#endif
