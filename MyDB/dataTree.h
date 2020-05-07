#pragma once
#include <queue>

#include "treeNode.h"

class dataTree {
private:
    treeNode * root;
public:
    dataTree();
    ~dataTree();

    void put(int e);
    void pop(int e);
};

