#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H  

#include <iostream>
#include <fstream>
#include <string>


struct AccountList
{
	Account* aHead;

	AccountList() {
		aHead = 0;
	}

	void addAccount(Account *account) {

		if (aHead == 0) {
			aHead = account;
		}
		else {
			Account* tmp = aHead;

			while (tmp->nextA)
			{
				tmp = tmp->nextA;
			}

			tmp->nextA = account;
			account->nextA = 0;
		}
	}

	void showAccounts() {
		Account* currentItem = aHead;

		while (currentItem)
		{
			currentItem->accountInfo();
			currentItem = currentItem->nextA;
		}

	}
	
	Account* findAccount(long long accountNumber) {

		Account* tmp = aHead;
		while (tmp)
		{
			if (tmp->accountNumber == accountNumber) {
				return tmp;
			}
			tmp = tmp->nextA;
		}
		cout << "Nie znaleziono podanego konta\n";
		return NULL;
	}
};

AccountList readData(string fileName) {

	AccountList list;

	long long accountNumber;
	string name, surname, stopTester;
	double balance = 0, debit = 1000;


	ifstream File;
	File.open(fileName, ios::in);

	if (!File.is_open()) {
		cout << "Nie ma pliku" << endl;
	}
	else {
		while (!File.eof())
		{
			TransactionList transactions;

			File >> accountNumber;
			File >> name;
			File >> surname;
			File >> balance;
			File >> debit;

			while (File >> stopTester and stopTester.find('#') != 0)
			{
				string date;
				double amount;
				date = stopTester; //#testschabowego
				File >> amount;
				transactions.addTransaction(date, amount);
			}

			Account *account = new Account(accountNumber, name, surname, balance, debit, transactions);
			list.addAccount(account);
		}

		File.close();
	}

	return list;

}
#endif