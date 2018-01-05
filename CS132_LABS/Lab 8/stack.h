#include "list.h"
#ifndef STACK_H__
#define STACK_H__



template <class BaseData>
class Stack  :  protected List<BaseData>
  {
  public:
    Stack();
    ~Stack();
    BaseData *top();
    int emptyS();
    int fullS();
    void push(BaseData item);
    void pop();
  };

template <class BaseData>
Stack<BaseData>::Stack() : List<BaseData>()
{}

template <class BaseData>
Stack<BaseData>::~Stack()
{  //cout << "stack destroy " << numNodes << endl;
}

template <class BaseData>
void Stack<BaseData>:: pop()
{
  if (!emptyS())
    {
      first();
      remove();
    }
  else  cout << "empty stack" << endl;
}

template <class BaseData>
void Stack<BaseData>::push(BaseData item)
{
  if (!fullS())
    {
      if (numNodes) first ();
      insertBefore(item);
    }
  else cout << "full Stack" << endl;
}

template <class BaseData>
int Stack<BaseData>::emptyS()
{
  return (numNodes == 0);
}

template <class BaseData>
int Stack<BaseData>::fullS()
{
  ListNode  *p;
  p = new ListNode;
  if (!p) return 1;
  delete p;
  return 0;
}

template <class BaseData>
BaseData *Stack<BaseData>::top()
{
  first();
  return (examine());
}

#endif