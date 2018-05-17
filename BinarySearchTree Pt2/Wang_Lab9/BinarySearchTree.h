#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
    struct Node
    {
        int order;
        int key;
        Node* Child;
        Node* rightSibling;
        Node* leftSibling;

        Node(int k, int o, Node* r, Node* f, Node* l) :
        key(k), order(o), rightSibling(r), Child(f), leftSibling(l) {}
    };

    struct Queue
    {
        Queue *next;
        Node *node;

        Queue(Queue *q, Node *n) :
            next(q), node(n) {}
    };
    Node** queue;

    Node** merge(Node** queueOrig, Node** queueTemp);
    Node* mergehelper(Node* root1, Node* root2);
    void swap(Node* &node1, Node* &node2);
    void levelorderHelper(Node* root);


public:

    BinarySearchTree();
    virtual ~BinarySearchTree();
    void insert(int value);
    void levelorder();
    void deletemin();
};
#endif
