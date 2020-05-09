#pragma once
#include <queue>
#include <vector>
#include <memory>

#include "AVLIndexTree.h"

#define DEFAULTSIZE 256

class MyDB {
private:
    int size;
    int CHARSIZE;
    bool isIndex = false;
    
    std::vector<std::unique_ptr<char[]>> column;
    AVLIndexTree* rows = nullptr;

    void createIndex();
public:
    MyDB();
    MyDB(int maxL);
    ~MyDB();

    void index();
    void put(const char * src);
    //void remove();
    //void update();
    void findAll(const char * src);

    int getSize();
    int getSize() const;
    void setSize(int n);
    int getCharSize();
    int getCharSize() const;
    int compare(const int left, const int right);
    int compare(const int dest, const char * target);
    int compareChar(const char* left, const char* right);
    void printTree();
};

