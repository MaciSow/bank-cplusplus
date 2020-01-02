#ifndef RAPORTLIST_H
#define RAPORTLIST_H


struct RaportItem
{
	RaportItem* nextR;
	long long accountNumber = 0;
	double amount = 0;
	string date, surname = "";


	RaportItem(long long acc, string date, double amount) {
		accountNumber = acc;
		this->amount = amount;
		this->date = date;
		nextR = 0;
	}
};

struct RaportList
{
	RaportItem* rHead;

	RaportList() {
		rHead = 0;
	}

	void addItem(RaportItem* item) {

		if (rHead == 0) {
			rHead = item;
		}
		else {
			RaportItem* tmp = rHead;

			while (tmp->nextR)
			{
				tmp = tmp->nextR;
			}

			tmp->nextR = item;
			item->nextR = 0;
		}
	}

	void showRaport() {
		RaportItem* item = rHead;

		while (item)
		{
			cout << item->accountNumber << "\t" << item->date << "\t" << item->amount << endl;
			item = item->nextR;
		}

	}

	void raportTransactions(AccountList list) {
		Account* currentAccount = list.aHead;
		string startDate, stopDate;


		cout << "Podaj date poczatkowa: ";
		cin >> startDate;
		cout << "\nPodaj date koncowa: ";
		cin >> stopDate;

		if (!currentAccount->checkDatesOrder(startDate, stopDate)) {
			cout << "\nNiepoprawny zakres dat!!!\n";
		}

		while (currentAccount) {
			Transaction* currentItem = currentAccount->transactions.tHead;

			while (currentItem) {
				string date = currentItem->date;

				if (currentAccount->checkDateInRange(date, startDate, stopDate)) {
					long long accountNumber = currentAccount->accountNumber;
					double amount = currentItem->amount;

					addItem(new RaportItem(accountNumber, date, amount));
				}
				currentItem = currentItem->nextT;
			}
			currentAccount = currentAccount->nextA;
		}

		int sortType;
		cout << "Wybierz typ sortowania wedlug:\n"
			<< "1 - daty\n" << "2 - kwot\n" << "3 - numerow kont\n";
		cin >> sortType;
		sortRaport(sortType);
	}

	void sortRaport(int sortType) {

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


	void sortByDate() {
		int swapped;
		RaportItem* ptr1;
		RaportItem* lptr = NULL;

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

	void sortByAmount() {
		int swapped;
		RaportItem* ptr1;
		RaportItem* lptr = NULL;

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

	void sortByAccount() {
		int swapped;
		RaportItem* ptr1;
		RaportItem* lptr = NULL;

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



	void swap(RaportItem* a, RaportItem* b)
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