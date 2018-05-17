#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
#include <math.h>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    m_root = nullptr;
    int size;
}
BinarySearchTree::~BinarySearchTree()
{
    while(m_root != nullptr)
    {
        deletemin();
    }
}

void BinarySearchTree::insert(int x)
{
    Node * temp = new Node();
    temp->setvalue(x);

    if(m_root == nullptr)
    {
        m_root = temp;
    }
    else
    {
        merge(m_root, temp);
    }
    size ++;
}

void BinarySearchTree::deletemin()
{
    Node * left;
    Node * right;
    Node * min;

    if (m_root == nullptr)
    {
        return;
    }
    else
    {
        left = m_root->getleft();
        right = m_root->getright();
        min = m_root;
        m_root = nullptr;

        delete min;
        min = nullptr;

        m_root = merge(left, right);
    }
}

Node * BinarySearchTree::merge(Node *a, Node *b)
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
    else if (a->getvalue() > b->getvalue())
    {
        Node * temp = a;
        m_root = b;
        merge(b, temp);
    }
    else if (a->getvalue()<= b->getvalue())
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


}

void BinarySearchTree::levelorder(Node * place)
{
  if (m_root == nullptr)
  {
      return;
  }
  else
  {
      Node* myArray[size];
      for(int i = 0; i < size; i++)
      {
          myArray[i] = nullptr;
      }
      int index = 0;
      int insert = 1;
      myArray[index] = place;
      bool e = true;
      while (e)
      {
          Node* temp = nullptr;
          temp = myArray[index];
          std::cout << temp -> getvalue() << " ";
          index++;
          if(temp -> getleft() != nullptr)
          {
              myArray[insert] = temp -> getleft();
              insert++;
          }
          if(temp -> getright() != nullptr)
          {
              myArray[insert] = temp -> getright();
              insert++;
          }
          if(index == size)
          {
              e = false;
          }
          else if (myArray[index] == nullptr)
          {
              e = false;
          }


      }
  }
}

void BinarySearchTree::preorder(Node * place)
{
    if (place != nullptr)
    {
        std::cout << place -> getvalue() << " ";
        preorder(place -> getleft());
        preorder(place -> getright());
    }
}

void BinarySearchTree::inorder(Node *place)
{
    if (place != nullptr)
    {
        inorder(place -> getleft());
        std::cout << place -> getvalue() << " ";
        inorder(place -> getright());
    }
}
