#include "Node.h"
#include <iostream>

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        Node* search(int num, Node* subtree);
        /**@pre Pass in an int and node pointer
        @post None
        @return Pointer to the node containing the int if exists
        **/
        void insert(int num);
        /**@pre pass in an int
        @post Inserts the number into an empty tree
        @return None
        **/
        void insertHelper(int num, Node* subtree);
        /**@pre Pass in int and node pointer
        @post inserts number into the tree if not already there
        @return None
        **/
        void remove(int num);
        /**@pre Pass in an int
        @post Removes from tree in only one node
        @return None
        **/
        void removeHelper(int num, Node* subtree, Node* parent);
        /**@pre Pass in int and two node pointers
        @post Removes the int from the tree if it exists
        @return None
        **/

        void deletemin();
        /**@pre None
        @post Deletes the min number from the tree
        @return None
        **/
        void deletemax();
        /**@pre None
        @post Deletes the max number from the tree
        @return None
        **/

        void inorder(Node* subtree);
        /**@pre Pass in Node pointer
        @post Displays the values in the tree in order
        @return None
        **/
        
        void preorder(Node* subtree);
        /**@pre Pass in Node pointer
        @post Displays the values in the tree in preorder
        @return None
        **/

        void levelorder(Node* subtree);
        /**@pre Pass in Node pointer
        @post Displays the values in level order
        @return None
        **/
        Node* m_root;
        int size;

};

#endif
