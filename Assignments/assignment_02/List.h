#pragma once

#include <string>
#include "Node.h"

class List{
  private:
    std::string dummy = "";
    Node *current;
    int len;
    int idx;
  public:
    List();
    ~List();
    void insert(std::string data);
    std::string getDebugString();
    int length();
    std::string &operator[](int);
    void pushback(std::string);
    void remove(int i);
    void changeidx(int i);
};
