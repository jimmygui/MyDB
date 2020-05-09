#include "AVLIndexTree.h"

void AVLIndexTree::initTree() {
    root = new TreeNode();
}

void AVLIndexTree::deleteTree() {
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode* t = queue.front();
        if (t->hasLeft())
            queue.push(t->getLeft());
        if (t->hasRight())
            queue.push(t->getRight());
        delete t;
        queue.pop();
    }
}

AVLIndexTree::AVLIndexTree(MyDB* p)
    : parent(p) {
    //initTree();
}

AVLIndexTree::~AVLIndexTree() {
    deleteTree();
}

int AVLIndexTree::height(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->getHeight();
}
int AVLIndexTree::height_diff(TreeNode* node) {
    return height(node->getLeft()) - height(node->getRight());
}

int AVLIndexTree::compare(const int left, const int right) {
    return parent->compare(left, right);
}

int AVLIndexTree::compare(const int dest, const char * target) {
    return parent->compare(dest, target);
}

void AVLIndexTree::put(const int index) {
    collide = false;
    root = insert(index, root);
}

TreeNode * AVLIndexTree::insert(const int index, TreeNode* node) {
    if (node == nullptr)
        return new TreeNode(index);
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

TreeNode * AVLIndexTree::balance(TreeNode* node) {
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

TreeNode * AVLIndexTree::RR_rotate(TreeNode* parent) {
    //  y             
    //   |             x
    //    x     ->   /   |
    //     |        z    y   
    //      z
    TreeNode* right = parent->getRight();
    parent->setRight(right->getLeft());
    right->setLeft(parent);
    //Update Height
    parent->updateHeight();
    right->updateHeight();
    return right;
}

TreeNode * AVLIndexTree::RL_rotate(TreeNode* parent) {
    //   y       
    //    |             z
    //     x    ->    /   |
    //    /          x    y   
    //  z
    TreeNode* right = parent->getRight();
    parent->setRight(LL_rotate(right));
    return RR_rotate(parent);
}

TreeNode * AVLIndexTree::LL_rotate(TreeNode* parent) {
    //          y       
    //        /           x
    //      x      ->   /   |
    //    /            z    y   
    //  z
    TreeNode* left = parent->getLeft();
    parent->setLeft(left->getRight());
    left->setRight(parent);
    // Update Height
    parent->updateHeight();
    left->updateHeight();
    return left;
}

TreeNode * AVLIndexTree::LR_rotate(TreeNode* parent) {
    //       y       
    //     /           z
    //   x      ->   /   |
    //    |         x    y   
    //     z
    TreeNode* left = parent->getLeft();
    parent->setLeft(RR_rotate(left));
    return LL_rotate(parent);
}

std::list<int> AVLIndexTree::lookUp(const char * target) {
    TreeNode* node = root;
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

void AVLIndexTree::print() {
    // std::cout << "Called: AVLIndexTree::print()" << std::endl;
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        for (int i=0; i<size; ++i) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node->hasLeft())
                queue.push(node->getLeft());
            if (node->hasRight())
                queue.push(node->getRight());
            node->printList();
        }
        std::cout << std::endl;
    }
    // std::cout << "End AVLIndexTree::print()" << std::endl;
}