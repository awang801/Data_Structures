/**
*	@file : Node.hpp
*	@author : Alan Wang
*	@date : 4/15/15
*	Purpose: Node.hpp handles base methods for pointers and does the work for the clone method in binarysearchtree.
*/

#include <iostream>
#include "Node.h"

Node::Node()
{
    m_left = nullptr;
    m_right = nullptr;
    m_value = 0;
}

Node::Node(const Node& other)
{
    m_left = nullptr;
    m_right = nullptr;
    m_value = other.getvalue();

    if (other.getleft() != nullptr)
    {
        this->m_left = new Node(*(other.m_left));
    }

    else if (other.getright() != nullptr)
    {
        this->m_right = new Node(*(other.m_right));
    }
}

int Node::getvalue() const
{
    return(m_value);
}

void Node::setvalue(int val)
{
    m_value = val;
}

void Node::setleft(Node* left)
{
    m_left=left;
}

Node* Node::getright() const
{
    return(m_right);
}

Node* Node::getleft() const
{
    return(m_left);
}

void Node::setright(Node* right)
{
    m_right = right;
}
