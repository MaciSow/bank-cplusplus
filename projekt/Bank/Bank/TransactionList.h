#ifndef TRANSACTIONLIST_H  
#define TRANSACTIONLIST_H  

#include <string>
#include <iomanip>
using namespace std;

struct Transaction
{
	string date = "";
	double amount = 0;
	Transaction* nextT;

	Transaction() {
		nextT = 0;
	}

	void showTrans() {
		cout << date << endl << amount << endl;
	}

};

struct TransactionList
{
	Transaction* tHead;

	void addTransaction(string date, double amount)
	{
		Transaction* newTrans = new Transaction;    // tworzy nowy element listy

		// wype³niamy naszymi danymi
		newTrans->date = date;
		newTrans->amount = amount;

		if (tHead == 0) // sprawdzamy czy to pierwszy element listy
		{
			// je¿eli tak to nowy element jest teraz pocz¹tkiem listy
			tHead = newTrans;
		}

		else
		{
			// w przeciwnym wypadku wêdrujemy na koniec listy
			Transaction* tmp = tHead;

			while (tmp->nextT)
			{
				// znajdujemy wskaŸnik na ostatni element
				tmp = tmp->nextT;
			}

			tmp->nextT = newTrans;  // ostatni element wskazuje na nasz nowy
			newTrans->nextT = 0;     // ostatni nie wskazuje na nic
		}
	}

	Transaction* findTransaction(string date, double amount) {
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

	void deleteTransakcion(Transaction*& transaction) {
		// lista jednoelementowa
		if (transaction->nextT == 0 && transaction == tHead) {
			tHead = 0;
			delete transaction;
			return;
		}

		// jeœli jest pierwszym elementem na liœcie
		if (transaction == tHead) {
			tHead = transaction->nextT;
			delete transaction;
			return;
		}

		// jeœli jest ostatnim elementem na liœcie
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

	void showTransactions() {

		// wskaznik na pierszy element listy
		Transaction* temp = tHead;

		// przewijamy wskazniki na nastepne elementy
		while (temp)
		{
			cout << "\tdata: " << temp->date << " kwota: " << formatAmount(temp->amount) << endl;
			temp = temp->nextT;
		}

	}

	void showOneTransaction(Transaction* transasaction) {
		cout << "\tdata: " << transasaction->date << " kwota: " << formatAmount(transasaction->amount) << endl;
	}

	void deleteList() {

		while (tHead) {
			Transaction* tmpTrans;
			tmpTrans = tHead->nextT;
			delete tHead;
			tHead = tmpTrans;
		}
	}

	TransactionList() {
		tHead = 0;
	}

	string formatAmount(double amount) {

		string stringAmount;

		amount = (floor(amount * 100) / 100);

		stringAmount = to_string(amount);
		stringAmount = stringAmount.substr(0, stringAmount.find(".") + 3);

		return stringAmount;
	}



	/* Bubble sort the given linked list */
	void dateSort()
	{
		int swapped, i;
		struct Transaction* ptr1;
		struct Transaction* lptr = NULL;

		/* Checking for empty list */
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

	/* function to swap data of two nodes a and b*/
	void swap(struct Transaction* a, struct Transaction* b)
	{
		string tmpDate = a->date;
		a->date = b->date;
		b->date = tmpDate;

		double tmpAmount = a->amount;
		a->amount = b->amount;
		b->amount = tmpAmount;
	}

	bool checkDatesOrder(string youngDate, string oldDate) {
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
};

#endif 
