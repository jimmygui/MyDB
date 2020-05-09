#pragma once
#include "TreeNode.h"
#include "MyDB.h"

class AVLIndexTree {
private:
    MyDB* parent;
    TreeNode * root;
    bool collide = false;
    void initTree();
    void deleteTree();
public:
    AVLIndexTree(MyDB* p);
    ~AVLIndexTree();

    void put(const int index);
    TreeNode * insert(const int index, TreeNode* node);
    TreeNode * balance(TreeNode* node);
    int height(TreeNode* node);
    int height_diff(TreeNode* node);
    int compare(const int left, const int right);
    int compare(const int dest, const char * target);
    std::list<int> lookUp(const char * target);
    void print();

    TreeNode * RR_rotate(TreeNode* parent);
    TreeNode * RL_rotate(TreeNode* parent);
    TreeNode * LL_rotate(TreeNode* parent);
    TreeNode * LR_rotate(TreeNode* parent);
};