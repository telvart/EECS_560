/**
*	@file: DoubleLinkedList.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: implementation of methods declared in DoubleLinkedList.h
*/

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
  m_size = 0;
  m_front = nullptr;
  m_rear = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
  Node* temp;
  while(m_front != nullptr)
  {
    temp = m_front->getNext();
    delete m_front;
    m_front = temp;
  }
}

void DoubleLinkedList::insert(int num)
{
  if(isEmpty())
  {
    Node* temp = new Node(num);
    m_front = temp;
    m_rear = temp;
    m_size++;
    return;
  }
  insertRec(num, m_front);
}

void DoubleLinkedList::insertRec(int num, Node* start)
{
  if(start->getData() == num)
  {
    return;
  }
  if(start == m_rear && start->getData() != num)
  {
    Node* temp = new Node(num);
    start->setNext(temp);
    temp->setPrev(start);
    m_rear = temp;
    m_size++;
    return;
  }
  insertRec(num,start->getNext());
}

void DoubleLinkedList::deletenode(int num)
{
  if(m_size == 1 && m_front->getData() == num)
  {
    delete m_front;
    m_size--;
    m_front=nullptr;
    m_rear=nullptr;
    return;
  }
  deleteRec(num, m_front);
}

void DoubleLinkedList::deleteRec(int num, Node* start)
{
  if(start==nullptr)
  {
    std::cout<<"That value was not in the list";
    return;
  }

  if(start->getData() == num)
  {
    if(start == m_front)
    {
      Node* temp = m_front;
      m_front = m_front->getNext();
      m_front->setPrev(nullptr);
      delete temp;
    }
    else if(start == m_rear)
    {
      Node* temp = m_rear;
      m_rear = m_rear->getPrev();
      m_rear->setNext(nullptr);
      delete temp;
    }
    else
    {
      start->getPrev()->setNext(start->getNext());
      start->getNext()->setPrev(start->getPrev());
      delete start;
    }
    m_size--;
    return;
  }
  deleteRec(num, start->getNext());

}

void DoubleLinkedList::print()
{
  Node* temp = m_front;
  std::cout<<"\n";
  while(temp != nullptr)
  {
    std::cout<<temp->getData()<<" ";
    temp = temp->getNext();
  }
  std::cout<<"\n";
  return;
}

void DoubleLinkedList::reverse()
{
  reverseRec(nullptr,m_front);
}


//TODO FIX POINTER MANIPULATION WITH PREV AND HEAD AND TAIL
void DoubleLinkedList::reverseRec(Node* prev, Node* curr)
{
  if(curr != nullptr)
  {
    reverseRec(curr, curr->getNext());
    curr->setPrev(curr->getNext());
    curr->setNext(prev);


  }
  else
  {
    m_front = prev;
  }
}

bool DoubleLinkedList::isEmpty()
{
  return m_front==nullptr;
}
