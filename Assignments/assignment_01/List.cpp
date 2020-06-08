#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
  len=0;
}

List::~List(){

  std::cout << "In the destructor\n";
  Node *t;
  while (head != nullptr){
    t = head;
    head=head->getNext();
    delete t;
    }
}
void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);
  
  // insert it into the list
  t->setNext(head);
  head = t;
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *t;
  t = head;
  std::string result="";
  while (t != nullptr){
    result = result + t->getData() + "-->";
    t = t->getNext();
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

std::string List::operator[](int idx) const
{
    if (idx >= len || idx < 0)
        return "";
    Node *t;
    t = head;
    int i = 0;
    while (i < idx)
    {
        t = t->getNext();
        i = i+1;
    }
    return t->getData();
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
    t = head;
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
    len++;
}

void List::remove(int i)
{
    // return if invalid usage
    if (len == 0)
        return;
    if (i < 0 || i >= len)
        return;
    
    Node *t;
    t = head;

    // if the removal is at the beginning
    if (i == 0)
    {
        delete t;
        head = head->getNext();
        len--;
        return;
    }

    int idx = 0;
    t = new Node();
    Node *r;
    t = head;
    // iterate until t is the element right before the index we want to remove
    while (idx < i - 1)
    {
        t = t->getNext();
    }
    // delete the index we want to remove(right after t)
    r = t->getNext();
    delete r;
    // and then set t's next to the element right after the removed element
    t->setNext(t->getNext()->getNext());
    len--;
}
