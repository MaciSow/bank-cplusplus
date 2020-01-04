#ifndef RAPORTLIST_H
#define RAPORTLIST_H

#include <iostream>
#include <string>

#include "Raport.h"
#include "AccountList.h"
#include "Account.h"
#include "Transaction.h"

using namespace std;

struct RaportList
{
	Raport* rHead;

	RaportList();

	~RaportList();

	void addItem(Raport* item);

	void showRaportTransaction();

	void showRaportDebit();

	void raportTransactions(AccountList* list);

	void raportDebitUsers(AccountList* list);

	void sortRaportTransaction(int sortType);

	void sortRaportDebit(int sortType);

	void sortByDate();

	void sortByAmount();

	void sortByAccount();

	void sortBySurname();

	void swap(Raport* a, Raport* b);

	string formatAmount(double amount);

	string strinfToLower(string word);

	bool checkDatesOrder(string youngDate, string oldDate);
};
#endif