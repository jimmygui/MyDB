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

myDB::dataTree::dataTree() {
    initTree();
}

myDB::dataTree::~dataTree() {
    deleteTree();
}

myDB::myDB()
    : size(0), CHARSIZE(DEFAULTSIZE) {
}

myDB::myDB(const myDB & db) 
    : size(db.getSize()), CHARSIZE(db.getCharSize()) {
}

myDB::myDB(int maxL)
    : CHARSIZE(maxL) {
}

myDB::~myDB() {
    if (rows != nullptr)
        delete rows;
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

void myDB::index() {
    rows = new dataTree();
}

void myDB::put(const char * src) {
    std::unique_ptr<char[]> s(new char[CHARSIZE]);
    strcpy_s(s.get(), CHARSIZE, src);
    column.push_back(std::move(s));
    // rows.put(size++);
}

void myDB::search(const char * target) {}