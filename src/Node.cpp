#include "Node.h"

Node::Node()
{
    m_value = 0;
    m_lChild = nullptr;
    m_rChild = nullptr;
}

Node::Node(int val)
{
    m_value = val;
    m_lChild = nullptr;
    m_rChild = nullptr;
}

Node::~Node()
{

}