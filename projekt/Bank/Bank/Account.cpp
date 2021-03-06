/** @file */

#include "Account.h"

Account::Account(long long accountNumber, string name, string surname, double balance, double debit, TransactionList*& transactions) {
	this->accountNumber = accountNumber;
	this->name = name;
	this->surname = surname;
	this->balance = balance;
	this->debit = debit;
	this->transactions = transactions;
	nextA = 0;
}

Account::~Account() {
	delete transactions;
}

void Account::accountInfo() {
	cout << "Account Number: " << accountNumber << endl
		<< "User: " << name << " " << surname << endl
		<< "Balance: " << (balance + debit) << endl
		<< "Tranasctions:\n";
	transactions->showTransactions();
	cout << endl;
}

void Account::withdrawal(double amount) {
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

void Account::deposit(double amount) {
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

void Account::transfer(Account* receiver, double amount) {
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

void Account::accountStatement(string startDate, string stopDate) {
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
				tmp->showSignedTrans();
			}
			tmp = tmp->nextT;
		}
		cout << "Laczna kwota przychodow: " << depositSum << endl
			<< "Laczna kwota obciazen: " << withdrawalSum << endl
			<< "Saldo: " << depositSum + withdrawalSum << endl;
	}
}

string Account::getCurrentDate() {
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

string Account::formatBalance() {

	string stringAmount;

	string sign = balance > 0 ? "+" : "";

	stringAmount = to_string(balance);
	stringAmount = stringAmount.substr(0, stringAmount.find(".") + 3);

	return sign + stringAmount;
}

double Account::roundAmount(double amount) {
	return(floor(amount * 100) / 100);
}

bool Account::checkDatesOrder(string youngDate, string oldDate) {
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

bool Account::checkDateInRange(string checkedDate, string startDate, string stopDate) {
	if (checkDatesOrder(startDate, checkedDate) && checkDatesOrder(checkedDate, stopDate)) {
		return true;
	}
	return false;
}