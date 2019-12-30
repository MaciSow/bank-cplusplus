#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <time.h>

#include "TransactionList.h"


using namespace std;

class Account
{
private:
	long long accountNumber = 0;
	string name = "";
	string surname = "";
	double balance = 0;
	double debit = 1000;
	TransactionList transactions;

public:
	Account() {
	};

	Account(long long accountNumber, string name, string surname, double balance, double debit, TransactionList transactions) {
		this->accountNumber = accountNumber;
		this->name = name;
		this->surname = surname;
		this->balance = balance;
		this->debit = debit;
		this->transactions = transactions;
	}

	void accountInfo() {
		cout << "Account Number: " << accountNumber << endl
			<< "User: " << name << " " << surname << endl
			<< "Balance: " << (balance + debit) << endl
			<< "Tranasctions:\n";
		transactions.showTransactions();
		cout << endl;
	}

	long long getAccountNumber() {
		return accountNumber;
	}

	void withdrawal() {
		double amount;

		cout << endl << "Kwota wyplaty: ";
		cin >> amount;

		if (amount <= 0) {
			cout << "\nPodana kwota jest za mala!!!\n";
		}
		else {
			if ((balance + debit) < amount) {
				cout << "\nBrak wystarczajacych srodkow na koncie\n";
			}
			else {
				if (balance > amount) {
					balance -= amount;
				}
				else
				{
					debit += (balance - amount);
					balance = 0;
				}
				string currentDate = getCurrentDate();
				transactions.addTransaction(currentDate, -amount);
			}
		}
	}

	void deposit() {
		double amount;

		cout << endl << "Kwota wplaty: ";
		cin >> amount;

		if (amount <= 0) {
			cout << "\nPodana kwota jest za mala!!!\n";
		}
		else {
			balance += amount;
			string currentDate = getCurrentDate();
			transactions.addTransaction(currentDate, amount);
		}
	}

	void deleteTransactionList() {
		transactions.deleteList();
	}

	string getCurrentDate() {
		//https://docs.microsoft.com/pl-pl/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=vs-2019

		struct tm newtime;
		__time64_t long_time;
		_time64(&long_time);
		_localtime64_s(&newtime, &long_time);

		string year = to_string(newtime.tm_year + 1900);
		string month = to_string(newtime.tm_mon + 1);
		string day = to_string(newtime.tm_mday);
		string hour = to_string(newtime.tm_hour);
		string minute = to_string(newtime.tm_min);

		if (newtime.tm_mon + 1 <= 9) {
			month = "0" + month;
		}
		if (newtime.tm_mday <= 9) {
			day = "0" + day;
		}
		if (newtime.tm_hour <= 9) {
			hour = "0" + hour;
		}
		if (newtime.tm_min <= 9) {
			minute = "0" + minute;
		}

		return year + "-" + month + "-" + day + "T" + hour + ":" + minute;
	}

};
#endif 