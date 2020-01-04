#ifndef TRANSACTION_H  
#define TRANSACTION_H  

#include <iostream>

using namespace std;

struct Transaction
{
	string date = "";
	double amount = 0;
	Transaction* nextT;

	Transaction();
	void showTrans();
};
#endif