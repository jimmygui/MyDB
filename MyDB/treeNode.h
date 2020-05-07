#pragma once
#include <list>

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
    treeNode * left;
    treeNode * right;

    // void initIndexList();
    // void deleteIndexList();
public:
    treeNode();
    treeNode(treeNode* left, treeNode* right);
    ~treeNode();

    bool hasLeft();
    bool hasRight();
    treeNode * getLeft();
    treeNode * getRight();
    int front();
    void push_back(int x);
    void pop_back();
};