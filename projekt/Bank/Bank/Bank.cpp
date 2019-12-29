#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"
#include "UsersList.h"

using namespace std;


int main()
{
	UserList list = readData();
	list.showUsers();
	//Account acc = readData();
	//user user1(acc);

	//user1.print();

	//cin.get();
   // _CrtDumpMemoryLeaks();
	return 0;
}
