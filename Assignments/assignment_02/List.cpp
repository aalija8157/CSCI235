#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  current = nullptr;
  idx=0;
  len=0;
}

List::~List(){

  std::cout << "In the destructor\n";
  Node *t;
  while (current->getPrev() != nullptr){
      current = current->getPrev();
  }
  while (current != nullptr)
  {
      t = current;
      current = current->getNext();
      delete t;
  }
}
void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);
  Node *p = current;
  if (p != nullptr)
  {
      while (p->getPrev() != nullptr)
      {
          p = p->getPrev();
      }
      // insert it into the list
      t->setNext(p);
      t->setPrev(nullptr);
      p->setPrev(t);
  }
  t->setNext(p);
  t->setPrev(nullptr);
  current = t;
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *t;
  t = current;
  std::string result="";
  while (t->getPrev() != nullptr)
      t = t->getPrev();
  while (t != nullptr){
    result = result + t->getData() + "-->";
    t = t->getNext();
  }
  result = result + "null\n";
  while (t != nullptr)
  {
      result = result + t->getData() + "-->";
      t = t->getPrev();
  }
  result = result + "null";

  return result;
}


int List::length(){
  // Node *t = head;
  // int l = 0;
  // while (t!=nullptr){
  //   t=t->getNext();
  //   l++;
  // }
  // return l;
  return len;
}


void List::pushback(std::string s)
{
    //trivial case, size = 0 same as insert.
    if (len == 0)
    {
        this->insert(s);
        return;
    }
    Node *t;
    t = current;
    Node *data = new Node(s);
    // loop until we get to the last element
    while (t->getNext() != nullptr)
    {
        t = t->getNext();
    }
    // the last element's next is now the new node we created.
    t->setNext(data);
    // new last element
    data->setNext(nullptr);
    data->setPrev(t);
    current = data;
    len++;
}

std::string &List::operator[](int i){
  
    if (i>len-1)
        return dummy;
    Node *t = current;
    while (idx - i > 0)
    {
        t = t->getPrev();
        idx--;
    }
    while (idx - i < 0)
    {
        t = t->getNext();
        idx++;
    }
    current = t;
    return t->getRef();
}

void List::remove(int i)
{
    // return if invalid usage
    if (len == 0)
        return;
    if (i < 0 || i >= len)
        return;
    Node *t;
    t = current;

    // iterate until t is the node we want to delete (neither loop goes through if the idx we want to
    // remove is the current idx)
    while (idx - i > 0)
    {
        t = t->getPrev();
        idx--;
    }
    while (idx - i < 0)
    {
        t = t->getNext();
        idx++;
    }

    // delete r (which is t)
    Node *r = t;
    delete r;
    // and then if the removed element was NOT the first element, set the previous element's next
    // element to the element after t.
    if (idx != 0)
        t->getPrev()->setNext(t->getNext());
    // set the next element's previous element to the element before t
    t->getNext()->setPrev(t->getPrev());
    // set current element to the element after t
    current = t->getNext();
    len--;
}
