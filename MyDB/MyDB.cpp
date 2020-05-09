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
    rows = new AVLIndexTree(this);
    if (size > 0) {
        createIndex();
    }
}

int MyDB::compare(const int left, const int right) {
    return compareChar(column.at(left).get(), column.at(right).get());
}

int MyDB::compare(const int dest, const char * target) {
    return compareChar(column.at(dest).get(), target);
}

int MyDB::compareChar(const char* left, const char* right) {
    // Manual Compare
    // int i = 0, j = 0;
    // while (left[i] != '\0' && right[j] != '\0') {
    //     if (left[i] != right[j])
    //         return left[i] - right[j];
    //     ++i;
    //     ++j;
    // }
    // if (left[i] != '\0')
    //     return 1;
    // if (right[j] != '\0')
    //     return -1;
    // return 0;

    // Build-in compare
    // std::cout << "Comparing: " << left << ", " << right << std::endl;
    return strcmp(left, right);
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

void MyDB::findAll(const char * target) {
    std::list<int> tempList;
    if (isIndex) {
        tempList = rows->lookUp(target);
    }
    if (!tempList.empty()) {
        std::cout << "Matched Items at index: " << std::endl;
        for (auto it=tempList.cbegin(); it != tempList.cend(); ++it) {
            std::cout << *it << ' ';
        }
    }

}