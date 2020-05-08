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

treeNode::treeNode()
    : height(1) {
    // initIndexList();
}

treeNode::treeNode(int index) 
    : height(1) {
    indexList.push_back(index);
}

treeNode::~treeNode() {
    // deleteIndexList();
}

bool treeNode::hasLeft() {
    return left != nullptr;
}

bool treeNode::hasRight() {
    return right != nullptr;
}

treeNode* treeNode::getLeft() {
    return left;
}

treeNode* treeNode::getRight() {
    return right;
}

void treeNode::setLeft(treeNode * node) {
    left = node;
}

void treeNode::setRight(treeNode * node) {
    right = node;
}

int treeNode::getHeight() {
    return height;
}

void treeNode::setHeight(int h) {
    height = h;
}

void treeNode::updateHeight() {
    if (left != nullptr && right != nullptr)
        setHeight(1 + std::max(left->getHeight(), right->getHeight()));
    else if (left != nullptr)
        setHeight(1 + left->getHeight());
    else if (right != nullptr)
        setHeight(1 + right->getHeight());
    else
        setHeight(1);
}

int treeNode::front() {
    return indexList.front();
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

std::list<int> treeNode::getIndexList() {
    return indexList;
}

void treeNode::printList() {
    for (auto it=indexList.cbegin(); it != indexList.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "| ";
}