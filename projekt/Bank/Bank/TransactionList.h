#ifndef TRANSACTIONLIST_H  
#define TRANSACTIONLIST_H  

#include <iostream>
#include <string>

#include "Transaction.h"

using namespace std;

struct TransactionList
{
	Transaction* tHead;

	TransactionList();

	~TransactionList();

	void addTransaction(string date, double amount);

	Transaction* findTransaction(string date, double amount);

	void deleteTransaction(Transaction* transaction);

	void showTransactions();

	void showOneTransaction(Transaction* transasaction);

	void deleteList();

	string formatAmount(double amount);

	void dateSort();

	void swap(Transaction* a, Transaction* b);

	bool checkDatesOrder(string youngDate, string oldDate);
};
#endif 
