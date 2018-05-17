#include "Node.h"

Node::Node()
{}

Node::~Node()
{}

int Node::getVertexNum() const
{
    return m_number;
}

int Node::getDistFromTree() const
{
    return m_dist;
}

int Node::getNearestInsider() const
{
    return m_nearestInsider;
}

void Node::setVertexNum(int num)
{
    m_number = num;
}

void Node::setDistFromTree(int dist)
{
    m_dist = dist;
}

void Node::setNearestInsider(int insider)
{
    m_nearestInsider = insider;
}
