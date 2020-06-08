#include <iostream>
#include "queueA.h"


Queue::Queue(int c)
{
    front = 0;
    rear = 0;
    capacity = c;
    queue = new int[c];
}
Queue::~Queue()
{
    delete[] queue;
}
void Queue::enqueue(int data)
{
    if (rear == capacity)
        return;
    queue[rear] = data;
    rear++;
}

int Queue::dequeue()
{
    if (is_empty())
        exit(1);
    int ret = queue[0];
    for (int i = 0; i < rear - 1; i++)
        queue[i] = queue[i+1];
    rear--;
    return ret;
}

bool Queue::is_empty()
{
    if (front == rear)
        return true;
    return false;
}

