#include <iostream>

#include "Node.h"

Node::Node() : next(nullptr)
{
}

Node::Node(std::string data){
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}


Node::Node(std::string data, Node *next, Node *prev){
  this->data = data;
  this->next = next;
  this->prev = prev;
}

void Node::setData(std::string data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

void Node::setPrev(Node *prev)
{
    this->prev = prev;
}
std::string Node::getData(){
  return data;
}

Node* Node::getNext(){
  return next;
}

Node* Node::getPrev(){
    return prev;
}

std::string &Node::getRef()
{
    return data;
}
