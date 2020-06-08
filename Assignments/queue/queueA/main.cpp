#include <iostream>
#include "queueA.h"

int main()
{
    Queue* q = new Queue(2);
    q->enqueue(2);
    std::cout << q->dequeue();
    delete q;
    return 0;
}
