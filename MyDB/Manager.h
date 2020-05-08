#pragma once
#include <string>
#include <fstream>
#include "myDB.h"

class Manager
{
private:
    myDB db;
public:
    Manager();
    ~Manager();

    void readInputFile(const char * filename);
    void index();
    void select(const char * target);
};