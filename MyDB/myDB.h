#pragma once
#include <queue>
#include <vector>
#include <memory>

#include "treeNode.h"

#define DEFAULTSIZE 256

class myDB {
private:
    int size;
    int CHARSIZE;
    treeNode * root;
    std::vector<std::unique_ptr<char[]>> column;

    void initTree();
    void deleteTree();
public:
    myDB();
    myDB(const myDB & db);
    myDB(int maxL);
    ~myDB();

    void put(const char * src);
    //void remove();
    //void update();
    void search(const char * src);

    int getSize();
    int getSize() const;
    void setSize(int n);
    int getCharSize();
    int getCharSize() const;
};

