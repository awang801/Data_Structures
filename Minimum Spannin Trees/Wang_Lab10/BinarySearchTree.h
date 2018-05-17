#include "Node.h"
#include <iostream>

#include "Node.h"

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(int v1, int v2, int e);
        Node * deletemin();
        void levelorder(Node *place);
        void preorder(Node * place);
        void inorder(Node * place);
        Node * merge(Node * a, Node * b);
        Node * m_root;
};
#endif
