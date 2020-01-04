#include "Raport.h"

Raport::Raport(long long accountNumber, string date, double amount) {
	this->accountNumber = accountNumber;
	this->amount = amount;
	this->date = date;
	nextR = 0;
}

Raport::Raport(long long accountNumber, string surname) {
	this->accountNumber = accountNumber;
	this->surname = surname;
	nextR = 0;
}