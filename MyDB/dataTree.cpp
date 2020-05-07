#include "dataTree.h"

dataTree::dataTree() {
    root = new treeNode();
}

dataTree::~dataTree() {
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