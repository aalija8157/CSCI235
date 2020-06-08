#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree()
{
    root = nullptr;
}

Node* BSTree::recursive_insert(Node* l, int value)
{
    if (l == nullptr)
        return new Node(value);
    else if (value > l->getData())
        l->setRight(recursive_insert(l->getRight(), value));
    else
        l->setLeft(recursive_insert(l->getLeft(), value));

    return l;
}
Node* BSTree::recursive_insertR(int value)
{
    root = recursive_insert(this->root, value);
}
Node* BSTree::recursive_remove(Node *l, int value)
{
    if (l == nullptr)
        return l;

    if (l->getData() > value)
        l->setLeft(recursive_remove(l->getLeft(), value));
    else if (l->getData() < value)
        l->setRight(recursive_remove(l->getRight(), value));
    else
    {
        if (l->getRight() == nullptr)
        {
            Node* t = l->getLeft();
            delete(l);
            return t;
        }
        else if (l->getLeft() == nullptr)
        {
            Node *t = l->getRight();
            delete(l);
            return t;
        }

        l->setData(minValue(l->getRight()));
        l->setRight(recursive_remove(l->getRight(), l->getData()));
    }
    return l;
}

void BSTree::recursive_removeR(int value)
{
    recursive_remove(root, value);
}


int BSTree::minValue(Node *l)
{
    if (l->getLeft() == nullptr)
        return l->getData();
    else
        return minValue(l->getLeft());
}
std::string BSTree::get_debug_helper(Node *l)
{
    if (l == nullptr)
        return "";
    std::string s1 = std::to_string(l->getData()) + "-->" + get_debug_helper(l->getLeft());
    std::string s2 = std::to_string(l->getData()) + "-->" + get_debug_helper(l->getRight());

    return s1 + '\n' + s2;
}
std::string BSTree::get_debug_string()
{
    if (root == nullptr)
        return "";
    return get_debug_helper(root);
}

void BSTree::setup()
{
    root = new Node(10);
    root->setLeft(new Node(20));
    root->setRight(new Node(30));
    root->getLeft()->setLeft(new Node(40));
    root->getLeft()->setRight(new Node(50));
}

void BSTree::insert(int d)
{
}
