#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <time.h>

#include "TransactionList.h"
#include "Transaction.h"

using namespace std;
struct Account
{
	long long accountNumber = 0;
	string name = "";
	string surname = "";
	double balance = 0;
	double debit = 1000;
	TransactionList* transactions;
	Account* nextA;

	Account(long long accountNumber, string name, string surname, double balance, double debit, TransactionList*& transactions);
	
	~Account();

	void accountInfo();

	void withdrawal();

	void deposit();

	void transfer(Account* receiver);

	void accountStatement();

	string getCurrentDate();

	double roundAmount(double amount);

	bool checkDatesOrder(string youngDate, string oldDate);

	bool checkDateInRange(string checkedDate, string startDate, string stopDate);
};
#endif 