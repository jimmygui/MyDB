// #include "AVLIndexTree.h"
#include "MyDB.h"

MyDB::MyDB()
    : size(0), CHARSIZE(DEFAULTSIZE) {
    // std::cout << "Construct a MyDB" << std::endl;
}

MyDB::MyDB(int maxL)
    : CHARSIZE(maxL) {
}

MyDB::~MyDB() {
    if (rows != nullptr)
        delete rows;
}

int MyDB::getSize() {
    return size;
}

int MyDB::getSize() const {
    return size;
}

void MyDB::setSize(int n) {
    size = n;
}

int MyDB::getCharSize() {
    return CHARSIZE;
}

int MyDB::getCharSize() const {
    return CHARSIZE;
}

void MyDB::createIndex() {
    for (int i=0; i<size; ++i) {
        rows->put(i);
    }
}

void MyDB::index() {
    isIndex = true;
    // rows = new AVLIndexTree(this);
    rows = new AVLIndexTree(&column);
    if (size > 0) {
        createIndex();
    }
}

void MyDB::printTree() {
    if (!isIndex)
        return ;
    // std::cout << "Called: printTree" << std::endl;
    rows->print();
}

void MyDB::put(const char * src) {
    // std::cout << "Constructing unique_ptr for: " << src << std::endl;
    std::unique_ptr<char[]> s(new char[CHARSIZE]);
    strcpy_s(s.get(), CHARSIZE, src);
    // std::cout << "Constructed: " << src << std::endl;
    column.push_back(std::move(s));
    // std::cout << "Pushed on vector: " << src << std::endl;
    if (isIndex) {
        // std::cout << "Pushing on Tree: " << src << std::endl;
        rows->put(size);
        // std::cout << "Pushed on tree: " << src << std::endl;
    }
    ++size;
}

std::list<int>* MyDB::getListByLinear(const char * target) {
    std::list<int> * tempList = new std::list<int>();
    for (int i=0; i<size; ++i) {
        if (strcmp(column.at(i).get(), target) == 0) {
            tempList->push_back(i);
        }
    }
    return tempList;
}

std::list<int>* MyDB::getListByIndex(const char * target) {
    return rows->lookUp(target);
}

void MyDB::printList(const std::list<int>* inList) {
    if (!inList->empty()) {
        std::cout << "Matched Items at index: " << std::endl;
        for (auto it=inList->cbegin(); it != inList->cend(); ++it) {
            std::cout << *it << ' ';
        }
    }
    else {
        std::cout << "No matched items found" << std::endl;
    }
    if (!isIndex) delete inList;
}

void MyDB::findAll(const char * target) {
    const std::list<int>* tempList = 
        (isIndex) ? getListByIndex(target) : getListByLinear(target);
    printList(tempList);
}
