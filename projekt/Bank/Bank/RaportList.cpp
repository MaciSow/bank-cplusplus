/** @file */

#include "RaportList.h"

RaportList::RaportList() {
	rHead = 0;
}

RaportList::~RaportList() {
	while (rHead)
	{
		Raport* tmpItem = rHead->nextR;
		delete rHead;
		rHead = tmpItem;
	}
}

void RaportList::addItem(Raport* item) {

	if (rHead == 0) {
		rHead = item;
	}
	else {
		Raport* tmp = rHead;

		while (tmp->nextR)
		{
			tmp = tmp->nextR;
		}

		tmp->nextR = item;
		item->nextR = 0;
	}
}

void RaportList::showRaportTransaction() {
	Raport* item = rHead;

	while (item)
	{
		cout << item->accountNumber << "\t" << item->date << "\t" << formatAmount(item->amount) << endl;
		item = item->nextR;
	}

}

void RaportList::showRaportDebit() {
	Raport* item = rHead;

	while (item)
	{
		cout << item->accountNumber << "\t" << item->surname << endl;
		item = item->nextR;
	}
}

void RaportList::raportTransactions(AccountList* list) {
	Account* currentAccount = list->aHead;
	string startDate, stopDate;


	cout << "Podaj date poczatkowa: ";
	cin >> startDate;
	cout << "Podaj date koncowa: ";
	cin >> stopDate;

	if (!currentAccount->checkDatesOrder(startDate, stopDate)) {
		cout << "\nNiepoprawny zakres dat!!!\n";
	}

	while (currentAccount) {
		Transaction* currentItem = currentAccount->transactions->tHead;

		while (currentItem) {
			string date = currentItem->date;

			if (currentAccount->checkDateInRange(date, startDate, stopDate)) {
				long long accountNumber = currentAccount->accountNumber;
				double amount = currentItem->amount;

				addItem(new Raport(accountNumber, date, amount));
			}
			currentItem = currentItem->nextT;
		}
		currentAccount = currentAccount->nextA;
	}

	int sortType;
	cout << "Wybierz typ sortowania wedlug:\n"
		<< "1 - daty\n" << "2 - kwot\n" << "3 - numerow kont\n";
	cin >> sortType;
	sortRaportTransaction(sortType);

	showRaportTransaction();
}

void RaportList::raportDebitUsers(AccountList* list) {
	Account* currentAccount = list->aHead;
	while (currentAccount) {
		if (currentAccount->balance < 0) {
			addItem(new Raport(currentAccount->accountNumber, currentAccount->surname));
		}
		currentAccount = currentAccount->nextA;
	}

	int sortType;
	cout << "Wybierz typ sortowania wedlug:\n"
		<< "1 - nazwisk\n" << "2 - numerow kont\n";
	cin >> sortType;
	sortRaportDebit(sortType);

	showRaportDebit();
}

void RaportList::sortRaportTransaction(int sortType) {

	if (rHead == NULL) {
		return;
	}

	switch (sortType) {
	case 1:
		sortByDate();
		break;
	case 2:
		sortByAmount();
		break;
	case 3:
		sortByAccount();
		break;
	default:
		cout << "Sortowanie nieaktywne\n";
		break;
	}
}

void RaportList::sortRaportDebit(int sortType) {

	if (rHead == NULL) {
		return;
	}

	switch (sortType) {
	case 1:
		sortBySurname();
		break;
	case 2:
		sortByAccount();
		break;
	default:
		cout << "Sortowanie nieaktywne\n";
		break;
	}
}

void RaportList::sortByDate() {
	int swapped;
	Raport* ptr1;
	Raport* lptr = NULL;

	do
	{
		swapped = 0;
		ptr1 = rHead;

		while (ptr1->nextR != lptr)
		{
			if (!checkDatesOrder(ptr1->date, ptr1->nextR->date)) {
				swap(ptr1, ptr1->nextR);
				swapped = 1;
			}

			ptr1 = ptr1->nextR;
		}
		lptr = ptr1;
	} while (swapped);
}

void RaportList::sortByAmount() {
	int swapped;
	Raport* ptr1;
	Raport* lptr = NULL;

	do
	{
		swapped = 0;
		ptr1 = rHead;

		while (ptr1->nextR != lptr)
		{
			if (ptr1->amount > ptr1->nextR->amount) {
				swap(ptr1, ptr1->nextR);
				swapped = 1;
			}

			ptr1 = ptr1->nextR;
		}

		lptr = ptr1;
	} while (swapped);
}

void RaportList::sortByAccount() {
	int swapped;
	Raport* ptr1;
	Raport* lptr = NULL;

	do
	{
		swapped = 0;
		ptr1 = rHead;

		while (ptr1->nextR != lptr)
		{
			if (ptr1->accountNumber > ptr1->nextR->accountNumber) {
				swap(ptr1, ptr1->nextR);
				swapped = 1;
			}

			ptr1 = ptr1->nextR;
		}

		lptr = ptr1;
	} while (swapped);
}

void RaportList::sortBySurname() {
	int swapped;
	Raport* ptr1;
	Raport* lptr = NULL;

	do
	{
		swapped = 0;
		ptr1 = rHead;

		while (ptr1->nextR != lptr)
		{
			if (strinfToLower(ptr1->surname) > strinfToLower(ptr1->nextR->surname)) {
				swap(ptr1, ptr1->nextR);
				swapped = 1;
			}

			ptr1 = ptr1->nextR;
		}

		lptr = ptr1;
	} while (swapped);
}

void RaportList::swap(Raport* a, Raport* b)
{
	long long tmpAccountNumber = a->accountNumber;
	a->accountNumber = b->accountNumber;
	b->accountNumber = tmpAccountNumber;

	string tmpSurname = a->surname;
	a->surname = b->surname;
	b->surname = tmpSurname;

	string tmpDate = a->date;
	a->date = b->date;
	b->date = tmpDate;

	double tmpAmount = a->amount;
	a->amount = b->amount;
	b->amount = tmpAmount;

}

string RaportList::formatAmount(double amount) {

	amount = (floor(amount * 100) / 100);

	string stringAmount;

	string sign = amount > 0 ? "+" : "";

	stringAmount = to_string(amount);
	stringAmount = stringAmount.substr(0, stringAmount.find(".") + 3);

	return sign + stringAmount;
}

string RaportList::strinfToLower(string word) {
	for (unsigned int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
	return word;
}

bool RaportList::checkDatesOrder(string youngDate, string oldDate) {
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