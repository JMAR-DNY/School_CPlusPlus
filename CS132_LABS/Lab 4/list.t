// FileName  : list.t
// programmer : J. Marron
// template implementations of the list class

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using std::cout;
using std::endl;

template <class BaseData>
List <BaseData>::List()
{
  previous = 0;
  currentNode = 0;
  head = 0;
  numNodes = 0;
  currentPos = 0;
}

template <class BaseData>
List <BaseData>::List(List<BaseData> &init)
{
  if (this == &init) return;
  ListNode *newList, *current, *newNode;
  current = init.head;
  newList = 0;
  head = 0;
  while (current)
    {
      newNode = new ListNode;
      newNode->listData = current->listData;
      newNode->link = 0;

      if (newList)
        {
          newList->link = newNode;
          newList = newList->link;
        }

      else newList = newNode;

      if (current == init.head)
        head = newNode;
      current = current->link;
    }

  numNodes = init.numNodes;
  currentPos = 0;
  previous = 0;
  currentNode = 0;
}

template <class BaseData>
void List <BaseData>::insertBefore(const BaseData &item)
{
  ListNode *p;
  p = new ListNode;
  p->listData = item;
  if (numNodes)
    {
      if (head == currentNode) head = p;
      p->link = currentNode;
      if (previous) previous ->link = p;
      ++numNodes;
      currentNode = p;
    }
  else
    {
      head = p;
      p->link = 0;
      previous = 0;
      ++numNodes;
      currentNode = p;
    }
}

template <class BaseData>
BaseData * List<BaseData>::examine()
{
  BaseData *temp;
  if (currentNode)
    {
      temp = new BaseData;
      *temp = currentNode->listData;
      return (temp);
    }
  else
    return 0;
}

template <class BaseData>
List <BaseData>::~List()
{
  destroy();
}

template <class BaseData>
void List<BaseData>::destroy()
{
  ListNode *temp;
  currentNode = head;
  while (currentNode)
    {
      temp = currentNode;
      currentNode = currentNode->link;
      delete temp;

    }

  previous = 0;
  currentNode = 0;
  head = 0;
  numNodes = 0;
  currentPos = 0;
}



template <class BaseData>
void List <BaseData>::first()
{
  if (numNodes)
    {
      previous = 0;
      currentNode = head;
      currentPos = 1;
    }
  else
    currentPos = 0;
}



template <class BaseData>
void List <BaseData>::last()
{
  while (currentNode->link)
    {
      previous = currentNode;
      currentNode = currentNode->link;
    }
  currentPos = numNodes;
}


template <class BaseData>
void List<BaseData>::makeCurrent (int position)
{
  if (( position < 1) || (position > numNodes))
    cout << "invalid position: "<< endl;
  else
    {
      first();
      for (int i = 1; i < position; i++)
        {
          previous = currentNode;
          currentNode = currentNode->link;
        }
      currentPos = position;
    }
}

template <class BaseData>
void List<BaseData>::prev()
{
  int tempCurrPos = currentPos;
  if (currentPos > 1)
    {
      ListNode *temp = previous;
      first();
      if (currentNode == temp)
        {
          previous = 0;
          currentNode = temp;
        }
      else
        {
          while (currentNode->link != temp)
            currentNode = currentNode->link;
          previous = currentNode;
          currentNode = temp;
        }
      currentPos = tempCurrPos -1;
    }
  else
    {
      cout << "walking over front of list";
      currentPos = 0;
    }

}

template <class BaseData>
void List<BaseData>::next()
{
  if (currentNode->link)
    {
      previous = currentNode;
      currentNode = currentNode->link;
      currentPos++;
    }
  else
    {
      cout << "walking over end of list";
      currentPos = 0;
    }
}

template <class BaseData>
int List<BaseData>::current()
{
  return (currentPos);
}

template <class BaseData>
int List<BaseData>::count()
{
  return (numNodes);
}

template <class BaseData>
void List<BaseData>::insertAfter(const BaseData &item)
{
  ListNode *p;
  p = new ListNode;
  p->listData = item;
  if (numNodes)
    {
      p->link = currentNode->link;
      currentNode->link = p;
      ++numNodes;
      previous = currentNode;
      currentNode = p;
      currentPos++;
    }
  else
    {
      head = p;
      p->link = 0;
      previous = 0;
      ++numNodes;
      currentNode = p;
      currentPos++;
    }
}

template <class BaseData>
void List<BaseData>::remove()
  {
    ListNode *p, *temp;
    p = currentNode;
    if (numNodes)	//there are nodes
      {if (previous)	//this is not the first node in the list
        {	//any other node in list but first
          previous->link = currentNode->link;
          if (currentNode->link != 0)
            currentNode = currentNode->link;
          else	//deleting last node in list
            {
              currentPos--;
              currentNode = previous;
              temp = head;
              if (temp == currentNode)
                previous = 0;
              else
                {
                  while (temp->link != currentNode && temp)
                    temp = temp->link;
                  previous = temp;
                }
            }
          delete p;
          --numNodes;
        }
        else
          {	//delete first node in list
            head = head->link;
            delete p;
            currentNode = head;
            --numNodes;

            //if first and last node in list
            if (!numNodes) currentPos = 0;
          }
      }
    else cout << "empty list" << endl;
  }


template <class  BaseData>
void List<BaseData>::replace(BaseData &item)
{
  if (currentNode)
    currentNode->listData = item;
}


template <class  BaseData>
List<BaseData>&  List<BaseData>:: operator = (List<BaseData> &init)
{
  if (this == &init) return *this;

  ListNode *temp, *newList, *current, *newNode;
  currentNode = head;
  while (currentNode) //delete existing left side list
    {
      temp = currentNode;
      currentNode = currentNode->link;
      delete temp;
    }

  current = init.head;
  newList = 0;
  while (current)              //copy list
    { newNode = new ListNode;
      newNode->listData = current->listData;
      newNode->link = 0;
      if (newList)
        {
          newList->link = newNode;
          newList = newList->link;
        }
      else newList = newNode;
      if (current == init.head)
        head = newNode;
      current = current->link;
    }

  numNodes = init.numNodes;
  currentPos = 0;
  previous = 0;
  currentNode = 0;
  return *this;
}

#endif
