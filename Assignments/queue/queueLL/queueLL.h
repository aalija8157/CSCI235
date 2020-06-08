#pragma once
class Queue
{
  private:
    Node* front;
    Node* rear;
  public:
    Queue();
    ~Queue();
    void enqueue(int data);
    int dequeue();
    bool is_empty();
};
