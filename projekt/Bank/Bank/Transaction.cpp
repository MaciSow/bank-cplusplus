/** @file */

#include "Transaction.h"

Transaction::Transaction() {
	nextT = 0;
}

void Transaction::showTrans() {
	cout << date << endl << amount << endl;
}