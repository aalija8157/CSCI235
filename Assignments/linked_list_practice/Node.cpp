#include <iostream>

#include "Node.h"

Node::Node()
{
    next = nullptr;
}

Node::Node(int data){
  this->data = data;
  this->next = nullptr;
}


Node::Node(int data, Node *next){
  this->data = data;
  this->next = next;
}

void Node::setData(int data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

int Node::getData(){
  return data;
}

Node* Node::getNext(){
  return next;
}

Node *reverse(Node *l)
{
    Node *t = l;
    Node *m = l;
    int sz = 0;
    while (t != nullptr)
    {
        sz++;
        t = t->getNext();
    }
    t = l;
    for (int i = 0; i < sz - 1; i++)
    {
        m = m->getNext();
        l = m;
        for (int j = 0; j < sz - 1 - i; j++)
        {
            l = t->getNext();
            t->setNext(l->getNext());
            l->setNext(t);
        }
    }
    return l;
}

Node *merge(Node* a, Node *b)
{
    int ai=0;
    int bi=0;
    Node* t = a;
    int as=0;
    int bs=0;
    Node* nl = new Node(-1);
    while (t != nullptr)
    {
        as++;
        t = t->getNext();
    }
    t = b;
    while (t != nullptr)
    {
        bs++;
        t = t->getNext();
    }

    t = nl;
    while (ai < as && bi < bs)
    {
        if (a->getData() < b->getData())
        {
            t->setNext(a);
            ai++;
            a = a->getNext();
        }
        else
        {
            t->setNext(b);
            bi++;
            b = b->getNext();
        }
        t = t->getNext();
    }

    while (ai < as)
    {
        t->setNext(a);
        ai++;
        a = a->getNext();
        t = t->getNext();
    }

    while (bi < bs)
    {
        t->setNext(b);
        bi++;
        b = b->getNext();
        t = t->getNext();
    }
    return nl;
}
