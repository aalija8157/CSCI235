#include "myVector.h"

template <class T>
myVector<T>::myVector()
{
    arr = new T[1];
    capacity = 1;
    currsize = 0;
}

template<class T>
void myVector<T>::push(T data)
{
    if (currsize == capacity)
    {
        T* newarr = new T[capacity + 5];
        for (int i = 0; i < capacity; i++)
            newarr[i] = arr[1];
        delete[] arr;
        capacity = capacity * 2;
        newarr = arr;
    }
    arr[currsize] = data;
    currsize = currsize + 1;
}

template<class T>
T &myVector<T>::operator[](int idx)
{
    if (idx >= currsize)
    {
        std::cerr << "Index out of bounds" << '\n';
        exit(1);
    }
    return arr[idx];
}

template<class T>
void myVector<T>::pop()
{
    T* newarr = new T[currsize - 1];
    for (int i = 0; i < currsize - 1; i++)
        newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
    currsize = currsize - 1;
    capacity = currsize;
}

template<class T>
int myVector<T>::size()
{
    return currsize;
}
