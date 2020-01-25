/** @file */

#include "Transaction.h"

Transaction::Transaction() {
	nextT = 0;
}

void Transaction::showTrans() {
	cout << date << endl << amount << endl;
}

void Transaction::showSignedTrans() {
	cout << "\tdata: " << date << " kwota: " << formatAmount() << endl;
}

string Transaction::formatAmount() {

	string stringAmount;

	string sign = amount > 0 ? "+" : "";

	stringAmount = to_string(amount);
	stringAmount = stringAmount.substr(0, stringAmount.find(".") + 3);

	return sign + stringAmount;
}