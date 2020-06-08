#pragma once
#include <iostream>

template <class T>
class myVector
{
  private:
    T* arr;
    int capacity;
    int currsize;
  public:
    myVector();
    void push(T data);
    void pop();
    int size();
    T &operator[] (int);
};
// i think this is ok?
#include "myVector.hxx"
