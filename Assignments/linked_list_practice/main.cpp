#include <iostream>
#include "Node.h"
int main()
{
    Node* l1 = new Node(1);
    Node* l2 = new Node(3);
    Node* l3 = new Node(5);
    Node* l4 = new Node(6);

    Node* s1 = new Node(2);
    Node* s2 = new Node(4);
    Node* s3 = new Node(6);
    Node* s4 = new Node(8);
    Node *s5 = new Node(9);
    
    l4->setNext(nullptr);
    l3->setNext(l4);
    l2->setNext(l3);
    l1->setNext(l2);

    s5->setNext(nullptr);
    s4->setNext(s5);
    s3->setNext(s4);
    s2->setNext(s3);
    s1->setNext(s2);
    
    Node* ret = reverse(l1);
    ret = ret->getNext()->getNext();;
    std::cout << ret->getData();
}
