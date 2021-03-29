#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <memory>

class Node
{
public:
    Node();
    Node(int val);
    ~Node();
    int m_value;
    NODE_PTR m_lChild;
    NODE_PTR m_rChild;
};

typedef std::shared_ptr<Node> NODE_PTR;

#endif