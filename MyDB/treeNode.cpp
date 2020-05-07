#include "treeNode.h"

// IndexNode::IndexNode(int i, IndexNode * next = nullptr, IndexNode * prev = nullptr) {
//     index = i;
//     this->next = next;
//     this->prev = prev;
// }

// void treeNode::initIndexList() {
//     head = new IndexNode(-1);
//     tail = new IndexNode(-1);
//     head->next = tail;
//     tail->prev = head;
// }

// void treeNode::deleteIndexList() {
//     IndexNode * curr = head;
//     while (curr != nullptr) {
//         IndexNode * temp = curr->next;
//         delete curr;
//         curr = temp;
//     }
// }

treeNode::treeNode() {
    // initIndexList();
}

treeNode::treeNode(treeNode* left, treeNode* right) {
    // initIndexList();
    this->left = left;
    this->right = right;
}

treeNode::~treeNode() {
    // deleteIndexList();
}

void treeNode::push_back(int x) {
    // IndexNode * pre = tail->prev;
    // IndexNode * node = new IndexNode(x, tail, pre);
    // pre->next = node;
    // tail->prev = node;

    indexList.push_back(x);
}

void treeNode::pop_back() {
    // IndexNode * popped = tail->prev;
    // IndexNode * prev = popped->prev;
    // prev->next = tail;
    // tail->prev = prev;
    // delete popped;
    
    indexList.pop_back();
}