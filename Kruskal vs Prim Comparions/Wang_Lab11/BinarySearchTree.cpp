#include "BinarySearchTree.h"
#include <iostream>
#include <math.h>


BinarySearchTree::BinarySearchTree()
{
    m_root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    while(m_root != nullptr)
    {
        deletemin();
    }
}

void BinarySearchTree::insert(int v1, int v2, int e)
{
    Node * temp = new Node();
    temp->setvertex(v1, v2);
    temp->setedge(e);

    if(m_root == nullptr)
    {
        m_root = temp;
    }
    else
    {
        merge(m_root, temp);
    }
}

Node * BinarySearchTree::deletemin()
{
    Node * left;
    Node * right;
    Node * min;

    if (m_root == nullptr)
    {
        return(nullptr);
    }
    else
    {
        left = m_root->getleft();
        right = m_root->getright();
        min = m_root;
        m_root = merge(left, right);
        return (min);
    }
}

Node * BinarySearchTree::merge(Node * a, Node * b)
{
    if(a == nullptr && b == nullptr)
    {
        return(nullptr);
    }
    else if (a == nullptr)
    {
        return b;
    }
    else if (b == nullptr)
    {
        return a;
    }
    else if (a->getedge() > b->getedge())
    {
        if (m_root == a)
        {
            m_root = b;
        }

        merge(b, a);
    }
    else if (a->getedge() <= b->getedge())
    {
        Node * swap = a->getright();
        a->setright(a->getleft());
        a->setleft(swap);

        if (a->getleft() == nullptr)
        {
            a->setleft(b);
        }
        else
        {
            a->setleft(merge(a->getleft(), b));
        }

        return (a);
    }
    else
    {
      return(nullptr);
    }
}

void BinarySearchTree::levelorder(Node * place)
{
    if(m_root == nullptr)
    {
        return;
    }

    Node * arr[200];
    int index = 0;
    int end = 1;
    arr[0] = place;

    while(index < end)
    {
        Node * temp;
        temp = arr[index];

        if (temp->getleft()!= nullptr)
        {
            arr[end] = temp->getleft();
            end++;
        }
        if (temp->getright() != nullptr)
        {
            arr[end] = temp->getright();
            end++;
        }

        std::cout << arr[index]->getedge() << "  ";
        index++;
    }
}

void BinarySearchTree::preorder(Node *place)
{
    if (place != nullptr)
    {
        std::cout << place -> getedge() << " ";
        preorder(place -> getleft());
        preorder(place -> getright());
    }
}

void BinarySearchTree::inorder(Node *place)
{
    if (place != nullptr)
    {
        inorder(place -> getleft());
        std::cout << place -> getedge() << " ";
        inorder(place -> getright());
    }
}
