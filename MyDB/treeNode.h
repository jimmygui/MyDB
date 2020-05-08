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

class treeNode {
private:
    // IndexNode * head;
    // IndexNode * tail;
    std::list<int> indexList;
    int height;
    treeNode * left;
    treeNode * right;

    // void initIndexList();
    // void deleteIndexList();
public:
    treeNode();
    treeNode(int index);
    ~treeNode();

    bool hasLeft();
    bool hasRight();
    treeNode * getLeft();
    treeNode * getRight();
    void setLeft(treeNode * node);
    void setRight(treeNode * node);
    int getHeight();
    void setHeight(int h);
    void updateHeight();
    int front();
    void push_back(int x);
    void pop_back();
    std::list<int> getIndexList();
    void printList();
};