#pragma once

class BSTree
{
  private:
    Node* root;
  public:
    BSTree();
    void insert(int d);
    std::string get_debug_string();
    std::string get_debug_helper(Node*);
    void setup();
    Node* recursive_insert(Node*, int);
    Node* recursive_insertR(int);
    Node* recursive_remove(Node*, int);
    void recursive_removeR(int);
    int minValue(Node *l);
};
