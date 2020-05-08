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
    //initTree();
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

int myDB::dataTree::compare(const int dest, const char * target) {
    return parent->compare(dest, target);
}

void myDB::dataTree::put(const int index) {
    collide = false;
    root = insert(index, root);
}

treeNode * myDB::dataTree::insert(const int index, treeNode* node) {
    if (node == nullptr)
        return new treeNode(index);
    int cmp = compare(index, node->front());
    if (cmp < 0) {
        node->setLeft(insert(index, node->getLeft()));
    }
    else if (cmp > 0) {
        node->setRight(insert(index, node->getRight()));
    }
    else {
        collide = true;
        node->push_back(index);
        return node;
    }
    if (!collide) {
        node->updateHeight();
        node = balance(node);
    }
    return node;
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
    //  y             
    //   |             x
    //    x     ->   /   |
    //     |        z    y   
    //      z
    treeNode* right = parent->getRight();
    parent->setRight(right->getLeft());
    right->setLeft(parent);
    //Update Height
    parent->updateHeight();
    right->updateHeight();
    return right;
}

treeNode * myDB::dataTree::RL_rotate(treeNode* parent) {
    //   y       
    //    |             z
    //     x    ->    /   |
    //    /          x    y   
    //  z
    treeNode* right = parent->getRight();
    parent->setRight(LL_rotate(right));
    return RR_rotate(parent);
}

treeNode * myDB::dataTree::LL_rotate(treeNode* parent) {
    //          y       
    //        /           x
    //      x      ->   /   |
    //    /            z    y   
    //  z
    treeNode* left = parent->getLeft();
    parent->setLeft(left->getRight());
    left->setRight(parent);
    // Update Height
    parent->updateHeight();
    left->updateHeight();
    return left;
}

treeNode * myDB::dataTree::LR_rotate(treeNode* parent) {
    //       y       
    //     /           z
    //   x      ->   /   |
    //    |         x    y   
    //     z
    treeNode* left = parent->getLeft();
    parent->setLeft(RR_rotate(left));
    return LL_rotate(parent);
}

std::list<int> myDB::dataTree::lookUp(const char * target) {
    treeNode* node = root;
    while (node != nullptr) {
        int cmp = compare(node->front(), target);
        if (cmp < 0)
            node = node->getRight();
        else if (cmp > 0)
            node = node->getLeft();
        else
            return node->getIndexList();
    }
    std::list<int> emptyList;
    return emptyList;
}

void myDB::dataTree::print() {
    // std::cout << "Called: dataTree::print()" << std::endl;
    std::queue<treeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        for (int i=0; i<size; ++i) {
            treeNode* node = queue.front();
            queue.pop();
            if (node->hasLeft())
                queue.push(node->getLeft());
            if (node->hasRight())
                queue.push(node->getRight());
            node->printList();
        }
        std::cout << std::endl;
    }
    // std::cout << "End dataTree::print()" << std::endl;
}