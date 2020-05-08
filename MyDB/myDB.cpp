#include "myDB.h"

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
    isIndex = true;
    rows = new dataTree(this);
}

int myDB::compare(const int left, const int right) {
    return compareChar(column.at(left).get(), column.at(right).get());
}

int myDB::compareChar(const char* left, const char* right) {
    int i = 0, j = 0;
    while (left[i] != '\0' && right[j] != '\0') {
        if (left[i] != right[j])
            return left[i] - right[j];
        ++i;
        ++j;
    }
    if (left[i] != '\0')
        return 1;
    if (right[j] != '\0')
        return -1;
    return 0;
}

void myDB::put(const char * src) {
    std::unique_ptr<char[]> s(new char[CHARSIZE]);
    strcpy_s(s.get(), CHARSIZE, src);
    column.push_back(std::move(s));
    if (isIndex)
        rows->put(size);
    ++size;
}

void myDB::search(const char * target) {}