/** @file */

#include "TransactionList.h"

TransactionList::TransactionList() {
	tHead = 0;
}

TransactionList::~TransactionList() {
	while (tHead) {
		Transaction* tmpTransaction = tHead->nextT;
		delete tHead;
		tHead = tmpTransaction;
	}
}

void TransactionList::addTransaction(string date, double amount)
{
	Transaction* newTrans = new Transaction;    // tworzy nowy element listy

	// wype?niamy naszymi danymi
	newTrans->date = date;
	newTrans->amount = amount;

	if (tHead == 0) // sprawdzamy czy to pierwszy element listy
	{
		// je?eli tak to nowy element jest teraz pocz?tkiem listy
		tHead = newTrans;
	}

	else
	{
		// w przeciwnym wypadku w?drujemy na koniec listy
		Transaction* tmp = tHead;

		while (tmp->nextT)
		{
			// znajdujemy wska?nik na ostatni element
			tmp = tmp->nextT;
		}

		tmp->nextT = newTrans;  // ostatni element wskazuje na nasz nowy
		newTrans->nextT = 0;     // ostatni nie wskazuje na nic
	}
}

Transaction* TransactionList::findTransaction(string date, double amount) {
	Transaction* tmp = tHead;

	while (tmp)
	{
		if (date.substr(0, 10) == tmp->date.substr(0, 10) && amount == tmp->amount) {
			return tmp;
		}
		tmp = tmp->nextT;
	}
	cout << "\nNie znaleziono transakcji\n";
	return NULL;
}

void TransactionList::deleteTransaction(Transaction* transaction) {
	if (transaction->nextT == 0 && transaction == tHead) {
		tHead = 0;
		delete transaction;
		return;
	}

	if (transaction == tHead) {
		tHead = transaction->nextT;
		delete transaction;
		return;
	}

	if (transaction->nextT == 0) {
		Transaction* tmp = tHead;

		while (tmp) {
			if (tmp->nextT == transaction)
			{
				tmp->nextT = 0;
				delete transaction;
				return;
			}
			tmp = tmp->nextT;
		}
	}

	Transaction* tmp = tHead;

	while (tmp) {
		if (tmp->nextT == transaction)
		{
			tmp->nextT = transaction->nextT;
			delete transaction;
			return;
		}
		tmp = tmp->nextT;
	}
}

void TransactionList::showTransactions() {
	Transaction* temp = tHead;

	while (temp)
	{
		temp->showSignedTrans();
		temp = temp->nextT;
	}
}

void TransactionList::dateSort()
{
	int swapped;
	Transaction* ptr1;
	Transaction* lptr = NULL;

	if (tHead == NULL) {
		return;
	}

	do
	{
		swapped = 0;
		ptr1 = tHead;

		while (ptr1->nextT != lptr)
		{
			if (!checkDatesOrder(ptr1->date, ptr1->nextT->date))
			{
				swap(ptr1, ptr1->nextT);
				swapped = 1;
			}
			ptr1 = ptr1->nextT;
		}
		lptr = ptr1;
	} while (swapped);
}

void TransactionList::swap(Transaction* a, Transaction* b)
{
		Transaction* nextA = a->nextT;
		Transaction* nextB = b->nextT;
		Transaction tmp = *a;

		*a = *b;
		*b = tmp;

		a->nextT = nextA;
		b->nextT = nextB;
}

bool TransactionList::checkDatesOrder(string youngDate, string oldDate) {
	unsigned youngYear = stoi(youngDate.substr(0, 4));
	unsigned oldYear = stoi(oldDate.substr(0, 4));

	if (youngYear > oldYear) {
		return false;
	}

	if (youngYear < oldYear) {
		return true;
	}

	unsigned youngMonth = stoi(youngDate.substr(5, 2));
	unsigned oldMonth = stoi(oldDate.substr(5, 2));

	if (youngMonth > oldMonth) {
		return false;
	}

	if (youngMonth < oldMonth) {
		return true;
	}

	unsigned youngDay = stoi(youngDate.substr(8, 2));
	unsigned oldDay = stoi(oldDate.substr(8, 2));

	if (youngDay > oldDay) {
		return false;
	}

	if (youngDay < oldDay) {
		return true;
	}

	unsigned youngHour = stoi(youngDate.substr(11, 2));
	unsigned oldHour = stoi(oldDate.substr(11, 2));

	if (youngHour > oldHour) {
		return false;
	}

	if (youngHour < oldHour) {
		return true;
	}

	unsigned youngMinute = stoi(youngDate.substr(14, 2));
	unsigned oldMinute = stoi(oldDate.substr(14, 2));

	if (youngMinute > oldMinute) {
		return false;
	}
	return true;
}