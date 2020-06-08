#include <iostream>
#include "person.h"
#include "Node.h"

// code from linked_list_practice
Node::Node()
{
    next = nullptr;
}

Node::Node(person data)
{
    this->data = data;
    this->next = nullptr;
}


Node::Node(person data, Node *next)
{
    this->data = data;
    this->next = next;
}

void Node::setData(person data)
{
    this->data = data;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

person Node::getData()
{
    return data;
}

Node* Node::getNext()
{
    return next;
}
