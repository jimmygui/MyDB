#pragma once
#include <string>
#include <fstream>
#include "MyDB.h"

class Manager
{
private:
    MyDB db;
public:
    Manager();
    ~Manager();

    void readInputFile(const char * filename);
    void index();
    void insert(const char * src);
    void select(const char * target);
};