/** @file */

#include "AccountList.h"

AccountList::AccountList() {
	aHead = 0;
}

AccountList::~AccountList() {

	while (aHead) {
		Account* tmpAccount = aHead->nextA;
		delete aHead;
		aHead = tmpAccount;
	}
}

void AccountList::addAccount(Account* account)
{

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

Account* AccountList::findAccount(long long accountNumber) {
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

void AccountList::showAccounts() {
	Account* currentAccount = aHead;

	while (currentAccount)
	{
		currentAccount->accountInfo();
		currentAccount = currentAccount->nextA;
	}
}

void AccountList::readData(string fileName) {
	this->fileName = fileName;

	ifstream File;
	File.open(fileName, ios::in);

	if (!File.is_open()) {
		cout << "Nie znaleziono pliku " << fileName << endl;
	}
	else {
		while (!File.eof())
		{
			long long accountNumber = 0;
			string name, surname, stopTester;
			double balance = 0, debit = 1000;

			File >> accountNumber;

			if (accountNumber)
			{
				TransactionList* transactions = new TransactionList;
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
					transactions->addTransaction(date, amount);
				}

				Account* account = new Account(accountNumber, name, surname, balance, debit, transactions);
				addAccount(account);
			}
		}
		File.close();
	}
}

void AccountList::saveData() {
	ofstream File(fileName);
	if (File.is_open())
	{
		Account* currentAccount = aHead;

		while (currentAccount)
		{
			File << currentAccount->accountNumber << " ";
			File << currentAccount->name << " ";
			File << currentAccount->surname << " ";
			File << currentAccount->formatBalance() << " ";
			File << currentAccount->debit << endl;

			Transaction* temp = currentAccount->transactions->tHead;

			while (temp)
			{
				File << temp->date << " " << temp->formatAmount() << endl;
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
