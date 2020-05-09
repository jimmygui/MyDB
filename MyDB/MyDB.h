#pragma once
#include <queue>
#include <vector>
#include <memory>

#include "AVLIndexTree.h"

#define DEFAULTSIZE 256

// class AVLIndexTree;

class MyDB {
private:
    int size;
    int CHARSIZE;
    bool isIndex = false;
    
    std::vector<std::unique_ptr<char[]>> column;
    AVLIndexTree* rows;

    void createIndex();
    std::list<int>* getListByLinear(const char * target);
    std::list<int>* getListByIndex(const char * target);
    void printList(const std::list<int>* inList);

public:
    MyDB();
    MyDB(int maxL);
    ~MyDB();

    void index();
    void put(const char * src);
    void findAll(const char * target);

    int getSize();
    int getSize() const;
    void setSize(int n);
    int getCharSize();
    int getCharSize() const;
    void printTree();
};

