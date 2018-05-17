#include "Node.h"
#include <iostream>

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
      void insert(int x);
      void deletemin();
      void levelorder(Node *place);
      void preorder(Node *place);
      void inorder(Node *place);
      Node * merge(Node * a, Node * b);
      Node * m_root;
      void setRank(Node *place);
      int size;

};

#endif
