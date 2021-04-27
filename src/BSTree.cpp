#include "BSTree.h"

NODE_PTR BST::_search(NODE_PTR const root, NODE_PTR &parent, const int &key)
{
    if (root == nullptr) {
        return nullptr;
    }
    NODE_PTR goalNode = root;
    while (goalNode)
    {
        parent = goalNode;
        if (goalNode->m_value == key) {
            return goalNode;
        }
        else if(goalNode->m_value < key) {
            goalNode = goalNode->m_rChild;
        }
        else {
            goalNode = goalNode->m_lChild;
        }
    }
    return nullptr;
}

NODE_PTR BST::_min(NODE_PTR const root)
{
    if (root == nullptr) {
        return nullptr;
    }
    auto minNode = root;
    while(minNode->m_lChild){
        minNode = minNode->m_lChild;
    }

    return minNode;
}

NODE_PTR BST::_max(NODE_PTR const root)
{
    if (root == nullptr) {
        return nullptr;
    }
    auto minNode = root;
    while(minNode->m_rChild){
        minNode = minNode->m_rChild;
    }
    return minNode;
}

bool BST::_insert(const int &key)
{
    auto newNode = std::make_shared<Node *>(key);
    if (m_bstRoot == nullptr) {
        m_bstRoot = newNode;
        return true;
    }
    auto parentPtr = m_bstRoot;
    while(parentPtr) {
        if (parentPtr->m_value == key) {
            return false;
        }
        else if(parentPtr->m_value < key) {
            if (parentPtr->m_rChild == nullptr ){
                parentPtr->m_rChild = newNode;
                return true;
            }
            else {
                parentPtr = parentPtr->m_rChild;
            }
        }
        else {
            if (parentPtr->m_lChild == nullptr ){
                parentPtr->m_lChild = newNode;
                return true;
            }
            else {
                parentPtr = parentPtr->m_lChild;
            }
        }
    }
    return false;
}

bool BST::_delete(const int &key)
{
    NODE_PTR parent = nullptr;
    NODE_PTR goalNode = _search(m_bstRoot, parent, key);
    if (goalNode == nullptr) {
        return false;
    }

    if (_isLeaf(goalNode)) {
        if (parent == goalNode) {
            m_bstRoot = nullptr;
        }
        else {
            if (parent->m_lChild == goalNode) {
                parent->m_lChild = nullptr;
            }
            else {
                parent->m_rChild = nullptr;
            }
        }
    }
    else if (_isNodeWithTwoChild(goalNode)) {

    }
    else {
        
    }
}

bool BST::_isLeaf(NODE_PTR &curPtr)
{
    return curPtr->m_lChild == nullptr && curPtr->m_rChild == nullptr;
}

bool BST::_isNodeWithTwoChild(NODE_PTR &curPtr)
{
    return curPtr->m_lChild != nullptr && curPtr->m_rChild != nullptr;
}

void BST::_inOrderTravel(NODE_PTR root, std::vector<int> &result)
{
    if (root == nullptr) {
        return;
    }
    _inOrderTravel(root->m_lChild, result);
    result.push_back(root->m_value);
    _inOrderTravel(root->m_rChild, result);
}

void BST::_deleteAllNodes(NODE_PTR root)
{
    
}