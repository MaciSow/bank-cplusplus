#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>

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
	}


	void deleteTransactionList() {
		transactions.deleteList();
	}

};
#endif 