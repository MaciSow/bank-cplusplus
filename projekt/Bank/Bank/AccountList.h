#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H  

#include <iostream>
#include <fstream>
#include <string>


struct AccountList
{
	Account* aHead;
	string fileName = "";
	string separator = "########################################";

	AccountList() {
		aHead = 0;
	}

	void addAccount(Account* account) {

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
		Account* currentAccount = aHead;

		while (currentAccount)
		{
			currentAccount->accountInfo();
			currentAccount = currentAccount->nextA;
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


	void readData(string fileName) {

		this->fileName = fileName;

		ifstream File;
		File.open(fileName, ios::in);

		if (!File.is_open()) {
			cout << "Nie ma pliku" << endl;
		}
		else {
			while (!File.eof())
			{
				long long accountNumber = 0;
				string name, surname, stopTester;
				double balance = 0, debit = 1000;
				TransactionList transactions;

				File >> accountNumber;
				File >> name;
				File >> surname;
				File >> balance;
				File >> debit;

				while (File >> stopTester and stopTester.find("#") != 0)
				{
					string date;
					double amount;
					date = stopTester; //#testschabowego
					File >> amount;
					transactions.addTransaction(date, amount);
				}
				
				if (accountNumber)
				{
					Account* account = new Account(accountNumber, name, surname, balance, debit, transactions);
					addAccount(account);
				}
			}
			File.close();
		}
	}

	void saveData() {
		ofstream File(fileName);
		if (File.is_open())
		{
			//File << "Kotlet\n";
			//File << "Schabowy\n";
			Account* currentAccount = aHead;

			while (currentAccount)
			{
				File << currentAccount->accountNumber << " ";
				File << currentAccount->name << " ";
				File << currentAccount->surname << " ";
				File << currentAccount->transactions.formatAmount(currentAccount->balance) << " ";
				File << currentAccount->debit << endl;

				Transaction* temp = currentAccount->transactions.tHead;

				while (temp)
				{
					File << temp->date << " " << currentAccount->transactions.formatAmount(temp->amount) << endl;
					temp = temp->nextT;
				}

				File << separator << endl;
				currentAccount = currentAccount->nextA;
			}

			File.close();
		}
		else {
			cout << "Blad zapisu pliku";
		}
	}
};
#endif