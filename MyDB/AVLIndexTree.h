#pragma once
#include <queue>
#include <vector>
#include <memory>
#include <string.h>

#include "TreeNode.h"

class AVLIndexTree {
private:
    bool collide = false;
    TreeNode * root;
    std::vector<std::unique_ptr<char[]>> * column;

    void initTree();
    void deleteTree();
    int height(TreeNode* node);
    int height_diff(TreeNode* node);
    int compare(const int left, const int right);
    int compare(const int dest, const char * target);
    int compareChar(const char* left, const char* right);

    TreeNode * RR_rotate(TreeNode* parent);
    TreeNode * RL_rotate(TreeNode* parent);
    TreeNode * LL_rotate(TreeNode* parent);
    TreeNode * LR_rotate(TreeNode* parent);
    TreeNode * insert(const int index, TreeNode* node);
    TreeNode * balance(TreeNode* node);

public:
    AVLIndexTree(std::vector<std::unique_ptr<char[]>> * v);
    ~AVLIndexTree();

    void put(const int index);
    std::list<int>* lookUp(const char * target);
    void print();
};