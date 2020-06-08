#include <iostream>
#include "Node.h"
#include "queueLL.h"
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}
Queue::~Queue()
{
    Node* t;
    while (front->getNext() != nullptr)
    {
        t = front;
        delete t;
        front = front->getNext();
    }
}
void Queue::enqueue(int data)
{
    Node* t = new Node(data);
    if (is_empty())
    {
        front = t;
        rear = t;
        return;
    }
    rear->setNext(t);
    rear = t;
}
int Queue::dequeue()
{
    if (is_empty())
        exit(1);
    Node *t = front;
    int r = front->getData();
    front = front->getNext();
    if (is_empty())
        rear = nullptr;
    delete t;
    return r;
}

bool Queue::is_empty()
{
    if (rear == nullptr && front == nullptr)
        return true;
    return false;
}
