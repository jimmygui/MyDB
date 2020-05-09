#pragma once
#include <list>
#include <algorithm>
#include <iostream>

// Abandon IndexNdoe. Use std::list instead.

// struct IndexNode {
//     int index;
//     IndexNode * next;
//     IndexNode * prev;
//     IndexNode(int i, IndexNode * next = nullptr, IndexNode * prev = nullptr);
// };

class TreeNode {
private:
    // IndexNode * head;
    // IndexNode * tail;
    std::list<int> indexList;
    int height;
    TreeNode * left;
    TreeNode * right;

    // void initIndexList();
    // void deleteIndexList();
public:
    TreeNode();
    TreeNode(int index);
    ~TreeNode();

    bool hasLeft();
    bool hasRight();
    TreeNode * getLeft();
    TreeNode * getRight();
    void setLeft(TreeNode * node);
    void setRight(TreeNode * node);
    int getHeight();
    void setHeight(int h);
    void updateHeight();
    int front();
    void push_back(int x);
    void pop_back();
    std::list<int> getIndexList();
    void printList();
};