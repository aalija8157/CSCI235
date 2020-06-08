#pragma once

// code from linked_list_practice assignment, but changed the data with a person object and added
// a destructor.

class Node
{
  private:
    person data;
    Node *next;
  public:
    Node();
    Node(person data);
    Node(person data,Node* next);
    void setData(person data);
    void setNext(Node *next);
    person getData();
    Node *getNext();
};
