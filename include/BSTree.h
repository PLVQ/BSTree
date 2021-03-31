#ifndef _BSTREEE_H_
#define _BSTREEE_H_

#include <vector>
#include <iostream>


#include "Node.h"



class BST
{
private:
    NODE_PTR m_bstRoot;
    NODE_PTR _search(NODE_PTR const root, NODE_PTR &parent, const int &key);
    NODE_PTR _min(NODE_PTR const root);
    NODE_PTR _max(NODE_PTR const root);
    bool _insert(const int &key);
    bool _delete(const int &key);
    bool _isLeaf(NODE_PTR &);
    bool _isNodeWithTwoChild(NODE_PTR &);
    void _inOrderTravel(NODE_PTR root, std::vector<int> &result);
    void _deleteAllNodes(NODE_PTR root);
public:
    BST();
    BST(std::vector<int> arr);
    BST(int *arr, int len);
    ~BST();
    bool isEmpty() const;
    bool onSearch(const int &key);
    bool onInsert(const int &key);
    bool onDelete(const int &key);
    void onInorderTravel(std::vector<int> &);


};

#endif