#include "Node.h"
#include <iostream>

#ifndef SKEWHEAP_H
#define SKEWHEAP_H

class SkewHeap
{
    public:
        SkewHeap();
        ~SkewHeap();
      void insert(int x);
      void deletemin();
      void levelorder(Node *place);
      void preorder(Node *place);
      void inorder(Node *place);
      Node * merge(Node * a, Node * b);
      Node * m_root;
      int size;

};

#endif
