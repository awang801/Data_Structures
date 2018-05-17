#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
  
}

BinarySearchTree::BinarySearchTree(int size)
{
    a = new Node[size];
    b = new int[size];

    for(int i = 1; i < size; i++)
    {
        b[i] = i;
        a[i].setVertexNum(i);
        a[i].setDistFromTree(1000);
    }

    m_size = size;
    buildHeap();
}


BinarySearchTree::~BinarySearchTree()
{
    delete []a;
    delete []b;
}


void BinarySearchTree::buildHeap()
{
    for(int i = ((m_size-1)/2); i >= 0; i--)
    {
        heapify(i);
    }
}


void BinarySearchTree::heapify(int i)
{
    if(getChild(i,1) >= m_size)
        return;

    Node minVal = a[i];
    int minIndex = i;

    for(int j = 1; j <= 2; j++)
    {
        if((getChild(i,j) < m_size)
           && (a[minIndex].getDistFromTree() > a[getChild(i,j)].getDistFromTree()))
        {
            minVal = a[getChild(i,j)];
            minIndex = getChild(i,j);
        }
    }

    if(minIndex != i)
    {
        Node temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;

        b[a[i].getVertexNum()] = i;
        b[a[minIndex].getVertexNum()] = minIndex;
        heapify(minIndex);
    }
}


Node BinarySearchTree::deleteMin()
{
    Node temp = a[0];
    a[0] = a[m_size-1];
    b[a[0].getVertexNum()] = 0;
    m_size--;
    heapify(0);
    return temp;
}


void BinarySearchTree::decreaseKey(int i, int newKey, int newInsider)
{
    decreaseKeyHelper(b[i], newKey, newInsider);
}


void BinarySearchTree::decreaseKeyHelper(int i, int newKey, int newInsider)
{
    if (a[i].getDistFromTree() > newKey)
    {
        a[i].setDistFromTree(newKey);
        a[i].setNearestInsider(newInsider);

        while ((i != 0) && (a[getParent(i)].getDistFromTree() > newKey))
        {
            Node temp = a[i];
            a[i] = a[getParent(i)];
            a[getParent(i)] = temp;

            b[a[i].getVertexNum()] = i;
            b[a[getParent(i)].getVertexNum()] = getParent(i);

            i = getParent(i);
        }
    }
}

int BinarySearchTree::getParent(int i)
{
    return ((i-1)/2);
}

int BinarySearchTree::getChild(int i, int j)
{
    return (2*i + j);
}
