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

void myDB::put(const char * src) {}

void myDB::search(const char * target) {}