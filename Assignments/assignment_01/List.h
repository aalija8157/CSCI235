#pragma once

#include <string>
#include "Node.h"

class List{
  private:
    Node *head;
    int len;
  public:
    List();
    ~List();
    void insert(std::string data);
    std::string getDebugString();
    int length();
    std::string operator[](int) const;
    void pushback(std::string);
    void remove(int i);
};
