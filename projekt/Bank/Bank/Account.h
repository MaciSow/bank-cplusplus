#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <time.h>

#include "TransactionList.h"


using namespace std;

struct Account
{
	long long accountNumber = 0;
	string name = "";
	string surname = "";
	double balance = 0;
	double debit = 1000;
	TransactionList* transactions;
	Account* nextA;

	Account(long long accountNumber, string name, string surname, double balance, double debit, TransactionList*& transactions) {
		this->accountNumber = accountNumber;
		this->name = name;
		this->surname = surname;
		this->balance = balance;
		this->debit = debit;
		this->transactions = transactions;
		nextA = 0;
	}
	
	~Account() {
		delete transactions;
	}

	void accountInfo() {
		cout << "Account Number: " << accountNumber << endl
			<< "User: " << name << " " << surname << endl
			<< "Balance: " << (balance + debit) << endl
			<< "Tranasctions:\n";
		transactions->showTransactions();
		cout << endl;
	}

	void withdrawal() {
		double amount;

		cout << "Kwota wyplaty: ";
		cin >> amount;

		amount = roundAmount(amount);

		if (amount <= 0) {
			cout << "\nPodana kwota jest za mala!!!\n";
		}
		else {
			if ((balance + debit) < amount) {
				cout << "\nBrak wystarczajacych srodkow na koncie\n";
			}
			else {
				balance -= amount;

				string currentDate = getCurrentDate();
				transactions->addTransaction(currentDate, -amount);
			}
		}
	}

	void deposit() {
		double amount;

		cout << "Kwota wplaty: ";
		cin >> amount;

		amount = roundAmount(amount);

		if (amount <= 0) {
			cout << "\nPodana kwota jest za mala!!!\n";
		}
		else {
			balance += amount;
			string currentDate = getCurrentDate();
			transactions->addTransaction(currentDate, amount);
		}
	}

	void transfer(Account* receiver) {
		double amount;

		cout << "Kwota wyplaty: ";
		cin >> amount;

		amount = roundAmount(amount);

		if (amount <= 0) {
			cout << "\nPodana kwota jest za mala!!!\n";
		}
		else {
			if ((balance + debit) < amount) {
				cout << "\nBrak wystarczajacych srodkow na koncie\n";
			}
			else {
				balance -= amount;

				string currentDate = getCurrentDate();
				transactions->addTransaction(currentDate, -amount);

				receiver->balance += amount;
				receiver->transactions->addTransaction(currentDate, amount);
			}
		}
	}

	void accountStatement() {
		string startDate, stopDate;

		cout << "Podaj date poczatkowa: ";
		cin >> startDate;
		cout << "Podaj date koncowa: ";
		cin >> stopDate;

		if (!checkDatesOrder(startDate, stopDate)) {
			cout << "\nNiepoprawny zakres dat!!!\n";
		}
		else {
			transactions->dateSort();
			double withdrawalSum = 0, depositSum = 0;
			Transaction* tmp = transactions->tHead;

			while (tmp)
			{
				if (checkDateInRange(tmp->date, startDate, stopDate)) {
					(tmp->amount < 0) ? withdrawalSum += tmp->amount : depositSum += tmp->amount;
					transactions->showOneTransaction(tmp);
				}
				tmp = tmp->nextT;
			}
			cout << "Laczna kwota przychodow: " << depositSum << endl
				<< "Laczna kwota obciazen: " << withdrawalSum << endl
				<< "Saldo: " << depositSum + withdrawalSum << endl;
		}
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

	double roundAmount(double amount) {
		return(floor(amount * 100) / 100);
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

		return true;
	}

	bool checkDateInRange(string checkedDate, string startDate, string stopDate) {
		if (checkDatesOrder(startDate, checkedDate) && checkDatesOrder(checkedDate, stopDate)) {
			return true;
		}
		return false;
	}
};
#endif 