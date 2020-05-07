#include <iostream>
#include <string.h>
#include <memory>

using namespace std;

int main() {
	char* s = new char[2];
	strcpy_s(s, 2, "ab");
	cout << s << endl;
	return 0;
}