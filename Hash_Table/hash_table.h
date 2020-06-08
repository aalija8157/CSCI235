#pragma once

class hash_table
{
  public:
    virtual ~hash_table();
    hash_table();
    hash_table(person p);
    hash_table(person arr[], int size);
    bool insert(person p);
    bool del(person p);
    person retrieve(person p);
    int hash (person p);
    Node* at(int i);
    bool insert(person p, int idx);
  private:
    Node* people[10000];
    int size;
};
