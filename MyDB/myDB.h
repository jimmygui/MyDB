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
    bool isIndex = false;
    
    std::vector<std::unique_ptr<char[]>> column;

    class dataTree {
    private:
        myDB* parent;
        treeNode * root;
        bool collide = false;
        void initTree();
        void deleteTree();
    public:
        dataTree(myDB* p);
        ~dataTree();

        void put(const int index);
        treeNode * insert(const int index, treeNode* node);
        treeNode * balance(treeNode* node);
        int height(treeNode* node);
        int height_diff(treeNode* node);
        int compare(const int left, const int right);
        int compare(const int dest, const char * target);
        std::list<int> lookUp(const char * target);
        void print();

        treeNode * RR_rotate(treeNode* parent);
        treeNode * RL_rotate(treeNode* parent);
        treeNode * LL_rotate(treeNode* parent);
        treeNode * LR_rotate(treeNode* parent);
    };

    dataTree* rows;

    void createIndex();
public:
    myDB();
    myDB(const myDB & db);
    myDB(int maxL);
    ~myDB();

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

