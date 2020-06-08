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
    Node* getRoot();
    int minValue(Node *l);
    int size(Node* l, int&);
    int sum(Node *l, int&);
    int num_leaves(Node* l);
    int height(Node* l);
    int sum_level(Node*l, int lvl);
    int root_leaf(Node*l);
};
