#include <iostream>
#include <memory>
#include "MyDB.h"
#include "Manager.h"

#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//在入口函数中包含 _CrtDumpMemoryLeaks();
//即可检测到内存泄露

//定义函数:
inline void EnableMemLeakCheck()
{
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

}

using namespace std;

int main() {
	EnableMemLeakCheck();
	// myDB db;
	// db.index();
	// db.put("a");
	// db.put("bc");
	// db.put("defg");
	// db.put("a");
	// db.put("ab");
	// db.put("ba");
	// db.put("bcdg");
	// db.put("bc");
	// db.put("defg");
	// db.put("bcdg");
	// db.put("a");
	// db.printTree();
	// cout << "----------------" << endl;
	// cout << "Search: a" << endl;
	// db.findAll("a");

	Manager dbms;
	// select * from Customers where Country = 'USA';
	// dbms.readInputFile("Country.txt");
	// dbms.index();
	// dbms.select("USA");

	// select * from Orders where OrderLineNumber = '2';
	dbms.readInputFile("OrderLineNumber.txt");
	dbms.index();
	dbms.select("2");
	return 0;
}