#ifndef USERSLIST_H
#define USERSLIST_H  

#include <iostream>
#include <string>
#include <fstream>

struct User
{
	Account account;
	User* nextU;

	User() {
		nextU = 0;
	}

	User(Account acc) {
		account = acc;
		nextU = 0;
	}
};

struct UserList
{

	User* uHead;

	UserList() {
		uHead = 0;
	}

	void addUser(Account account) {
		User* newUser = new User;

		newUser->account = account;

		if (uHead == 0) {
			uHead = newUser;
		}
		else {
			User* tmp = uHead;

			while (tmp->nextU)
			{
				tmp = tmp->nextU;
			}

			tmp->nextU = newUser;
			newUser->nextU = 0;
		}
	}

	void showUsers() {
		User* currentItem = uHead;

		while (currentItem)
		{
			currentItem->account.accountInfo();
			currentItem = currentItem->nextU;
		}

	}
	Account findUser(long long accountNumber) {

		User* tmp = uHead;
		while (tmp)
		{
			if (tmp->account.getAccountNumber() == accountNumber) {
				return tmp->account;
			}
			tmp = tmp->nextU;
		}

		Account emptyAccount;
		return emptyAccount;
	}
};

UserList readData(string fileName) {

	UserList list;

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

			Account user(accountNumber, name, surname, balance, debit, transactions);
			list.addUser(user);
		}

		File.close();
	}

	return list;

}
#endif