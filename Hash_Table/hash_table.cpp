#include <iostream>
#include <vector>
#include "person.h"
#include "Node.h"
#include "hash_table.h"
#include <cmath>

hash_table::~hash_table()
{
    std::cout << "in destructor";
    for (int i = 0; i < size; i++)
    {
        Node* t = people[i];
        Node* l;
        while (t != nullptr)
        {
            l = t->getNext();
            delete t;
            t = l;
        }
        people[i] = nullptr;
    }
}
hash_table::hash_table()
{
    size = 10000;
    for (int i = 0; i < size; i++)
        people[i] = nullptr;
}
hash_table::hash_table(person p)
{
    size = 10000;
    for (int i = 0; i < size; i++)
        people[i] = nullptr;
    this->insert(p);
}
hash_table::hash_table(person arr[], int s)
{
    size = 10000;
    for (int i = 0; i < size; i++)
        people[i] = nullptr;
    for (int i = 0; i < s; i++)
        this->insert(arr[i]);
}
// returns 1 if s1 is longer or equal, 2 if s2 is longer
bool hash_table::insert(person p)
{
    int idx = hash(p);
    if (people[idx] != nullptr)
    {
        Node* t = people[idx];
        while (t != nullptr)
            t = t->getNext();
        t = new Node (p);
        return true;
    }
    people[idx] = new Node(p);
    return true;
}

// PURELY for testing if the linked list implementation is working correctly, in reality this function
// makes no sense in a hash_table because we want to insert it at a hash idx not our own.
bool hash_table::insert(person p, int i)
{
    if (people[i] != nullptr)
    {
        Node* t = people[i];
        while (t->getNext() != nullptr)
            t = t->getNext();
        t->setNext(new Node(p));
        return true;
    }
    people[i] = new Node(p);
    return true;
}

// djb2 algorithm using a different starting prime number than usual and dividing the resulting
// numbers by 100 for smaller range and easier testing. this is obviously not my algorithm but I
// started with a different prime to get smaller indicies.
int hash_table::hash(person p)
{
    std::string s = p.first + p.last;
    unsigned int h;
    int c;
    h = 1171;
    for (int i = 0; i < s.length(); i++)
    {
        c = s[i];
        // bitwise shift, adds 5 zeros
        h = ((h << 5) + h) + c;
    }
    return (h % this->size) % 100;
}

bool hash_table::del(person p)
{
    for (int i = 0; i < size; i++)
    {
        Node* t = people[i];
        if (t != nullptr && (t->getData() == p))
        {
            //case if the first element of the linked list is the person we want.
            delete t;
            people[i] = t->getNext();
            return true;
        }
        // if first ele of the list is not the person, check the rest of the entries
        while (t != nullptr)
        {
            // if the next ele is the person we want, set the next of the current ele to the next of the
            // next ele, and delete the next ele.
            if (t->getNext() != nullptr && t->getNext()->getData() == p)
            {
                delete t->getNext();
                t->setNext(t->getNext()->getNext());
                return true;
            }
            t = t->getNext();
        }
    }
    // if everything goes through, the person was not found.
    return false;
}

Node* hash_table::at(int i)
{
    return people[i];
}

person hash_table::retrieve(person p)
{
    for (int i = 0; i < size; i++)
    {
        Node* t = people[i];
        while (t != nullptr)
        {
            if (p.first == t->getData().first && p.last == t->getData().last)
                return t->getData();
            t = t->getNext();
        }
    }
    // returns empty person if person is not found.
    person p1;
    return p1;
}
