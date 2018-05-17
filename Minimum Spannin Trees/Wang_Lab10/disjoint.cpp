
#include "disjoint.h"
#include "Node.h"
#include <iostream>


disjoint::disjoint(int size)
{
    m_size = size;

    set = new Node*[size];
    for (int i = 0; i < size; i++)
    {
        Node* temp = new Node();
        temp->setedge(i);
        set[i] = temp;
    }
}
void disjoint::merge(int v1, int v2)
{
    Node* temp1 = set[findSetParent(v1)];
    Node* temp2 = set[findSetParent(v2)];

    if (v1 < v2)
    {
        temp2 -> setparent(temp1);
    }
    else
    {
        temp1 -> setparent(temp2);
    }
}


int disjoint::findSetParent(int v)
{
    Node * temp = nullptr;

    for (int i = 0; i < m_size; i++)
    {
        if (set[i] -> getedge() == v)
        {
            temp = set[i];
            break;
        }
    }

    return (findHelper(temp));
}

int disjoint::findHelper(Node* v)
{
    if(v->getparent() == nullptr)
    {
        return v->getedge();
    }
    else
    {
        return (findHelper(v->getparent()));
    }
}
