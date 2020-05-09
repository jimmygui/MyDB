#pragma once
#include <queue>
#include <vector>
#include <memory>

#define DEFAULTSIZE 256

class AVLIndexTree;

class MyDB {
private:
    int size;
    int CHARSIZE;
    bool isIndex = false;
    
    std::vector<std::unique_ptr<char[]>> column;
    AVLIndexTree* rows;

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
    void printTree();
};

