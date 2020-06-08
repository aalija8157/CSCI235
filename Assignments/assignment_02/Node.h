#pragma once

class Node{
  private:
    std::string data;
    Node *next;
    Node *prev;
  public:
    Node();
    Node(std::string data);
    Node(std::string,Node* next, Node* prev);

    void setData(std::string data);
    void setNext(Node *next);
    void setPrev(Node *prev);
    std::string getData();
    Node *getNext();
    Node *getPrev();
    std::string &getRef();
};
