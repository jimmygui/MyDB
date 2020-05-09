#include "Manager.h"

Manager::Manager() {}

Manager::~Manager() {}

void Manager::readInputFile(const char * filename) {
    std::ifstream inputFile(filename);
    std::string data;
    while (std::getline(inputFile, data)) {
        db.put(data.c_str());
    }
}

void Manager::index() {
    db.index();
}

void Manager::insert(const char * src) {
    db.put(src);
}

void Manager::select(const char * target) {
    db.findAll(target);
}