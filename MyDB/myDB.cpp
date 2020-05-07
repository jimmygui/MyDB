#include "myDB.h"

void myDB::initTree() {
    root = new treeNode();
}

void myDB::deleteTree() {
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

myDB::myDB()
    : size(0), CHARSIZE(DEFAULTSIZE) {
    initTree();
}

myDB::myDB(const myDB & db) 
    : size(db.getSize()), CHARSIZE(db.getCharSize()) {
    initTree();
}

myDB::myDB(int maxL)
    : CHARSIZE(maxL) {
    initTree();
}

myDB::~myDB() {
    deleteTree();
}

int myDB::getSize() {
    return size;
}

int myDB::getSize() const {
    return size;
}

void myDB::setSize(int n) {
    size = n;
}

int myDB::getCharSize() {
    return CHARSIZE;
}

int myDB::getCharSize() const {
    return CHARSIZE;
}

void myDB::put(const char * src) {
    std::unique_ptr<char[]> s(new char[CHARSIZE]);
    strcpy_s(s.get(), CHARSIZE, src);
    column.push_back(s);
    // rows.put(size++);
}

void myDB::search(const char * target) {}