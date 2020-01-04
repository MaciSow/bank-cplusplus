#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H  

#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"
#include "TransactionList.h"

using namespace std;

struct AccountList
{
	Account* aHead;
	string fileName = "";
	string separator = "########################################";

	AccountList();

	~AccountList();

	void addAccount(Account* account);

	Account* findAccount(long long accountNumber);

	void showAccounts();

	void readData(string fileName);

	void saveData();
};
#endif