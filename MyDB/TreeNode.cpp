#include "TreeNode.h"

// IndexNode::IndexNode(int i, IndexNode * next = nullptr, IndexNode * prev = nullptr) {
//     index = i;
//     this->next = next;
//     this->prev = prev;
// }

// void TreeNode::initIndexList() {
//     head = new IndexNode(-1);
//     tail = new IndexNode(-1);
//     head->next = tail;
//     tail->prev = head;
// }

// void TreeNode::deleteIndexList() {
//     IndexNode * curr = head;
//     while (curr != nullptr) {
//         IndexNode * temp = curr->next;
//         delete curr;
//         curr = temp;
//     }
// }

TreeNode::TreeNode(int index) 
    : height(1) {
    indexList.push_back(index);
}

TreeNode::~TreeNode() {
    // deleteIndexList();
}

bool TreeNode::hasLeft() {
    return left != nullptr;
}

bool TreeNode::hasRight() {
    return right != nullptr;
}

TreeNode* TreeNode::getLeft() {
    return left;
}

TreeNode* TreeNode::getRight() {
    return right;
}

void TreeNode::setLeft(TreeNode * node) {
    left = node;
}

void TreeNode::setRight(TreeNode * node) {
    right = node;
}

int TreeNode::getHeight() {
    return height;
}

void TreeNode::setHeight(int h) {
    height = h;
}

void TreeNode::updateHeight() {
    if (left != nullptr && right != nullptr)
        setHeight(1 + std::max(left->getHeight(), right->getHeight()));
    else if (left != nullptr)
        setHeight(1 + left->getHeight());
    else if (right != nullptr)
        setHeight(1 + right->getHeight());
    else
        setHeight(1);
}

int TreeNode::front() {
    return indexList.front();
}

void TreeNode::push_back(int x) {
    // IndexNode * pre = tail->prev;
    // IndexNode * node = new IndexNode(x, tail, pre);
    // pre->next = node;
    // tail->prev = node;

    indexList.push_back(x);
}

void TreeNode::pop_back() {
    // IndexNode * popped = tail->prev;
    // IndexNode * prev = popped->prev;
    // prev->next = tail;
    // tail->prev = prev;
    // delete popped;
    
    indexList.pop_back();
}

std::list<int>& TreeNode::getIndexList() {
    return indexList;
}

void TreeNode::printList() {
    for (auto it=indexList.cbegin(); it != indexList.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "| ";
}