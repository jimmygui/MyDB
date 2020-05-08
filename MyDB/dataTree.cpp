#include "myDB.h"

void myDB::dataTree::initTree() {
    root = new treeNode();
}

void myDB::dataTree::deleteTree() {
    std::queue<treeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        treeNode* t = queue.front();
        if (t->hasLeft())
            queue.push(t->getLeft());
        if (t->hasRight())
            queue.push(t->getRight());
        delete t;
        queue.pop();
    }
}

myDB::dataTree::dataTree(myDB* p)
    : parent(p) {
    initTree();
}

myDB::dataTree::~dataTree() {
    deleteTree();
}

int myDB::dataTree::height(treeNode* node) {
    if (node == nullptr)
        return 0;
    return node->getHeight();
}
int myDB::dataTree::height_diff(treeNode* node) {
    return height(node->getLeft()) - height(node->getRight());
}

int myDB::dataTree::compare(const int left, const int right) {
    return parent->compare(left, right);
}

void myDB::dataTree::put(const int index) {
    root = insert(index, root);
}

treeNode * myDB::dataTree::insert(const int index, treeNode* node) {
    if (node == nullptr)
        return new treeNode(index);
    return nullptr;
}

treeNode * myDB::dataTree::balance(treeNode* node) {
    int h_dif = height_diff(node);
    if (h_dif > 1) {
        if (height_diff(node->getLeft()) > 0)
            node = LL_rotate(node);
        else
            node = LR_rotate(node);
    }
    else if (h_dif < -1) {
        if (height_diff(node->getRight()) < 0)
            node = RR_rotate(node);
        else
            node = RL_rotate(node);
    }
    return node;
}

treeNode * myDB::dataTree::RR_rotate(treeNode* parent) {
    treeNode* right = parent->getRight();
    parent->setRight(right->getLeft());
    right->setLeft(parent);
    return right;
}

treeNode * myDB::dataTree::RL_rotate(treeNode* parent) {
    treeNode* right = parent->getRight();
    parent->setRight(LL_rotate(right));
    return RR_rotate(parent);
}

treeNode * myDB::dataTree::LL_rotate(treeNode* parent) {
    treeNode* left = parent->getLeft();
    parent->setLeft(left->getRight());
    left->setRight(parent);
    return left;
}

treeNode * myDB::dataTree::LR_rotate(treeNode* parent) {
    treeNode* left = parent->getLeft();
    parent->setLeft(RR_rotate(left));
    return LL_rotate(parent);
}