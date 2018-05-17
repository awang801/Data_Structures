#ifndef BINARYSEARCHTREE_h
#define BINARYSEARCHTREE_h

#include "Node.h"

class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(int size);
    ~BinarySearchTree();
    Node deleteMin();
    void buildHeap();
    void decreaseKey(int i, int newKey, int newInsider);


private:
    Node *a;
    int* b;
    int m_size = 0;
    int getParent(int i);
    int getChild(int i, int j);
    void heapify(int i);
    void decreaseKeyHelper(int i, int newKey, int newInsider);


};

#endif /* BinarySearchTree_h */
