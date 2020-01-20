/** @file */

#ifndef TRANSACTION_H  
#define TRANSACTION_H  

#include <iostream>

using namespace std;

/**
	Struktura transakcji.
*/
struct Transaction
{
	string date = "";		///< data transakcji
	double amount = 0;		///< kwota transakcji
	Transaction* nextT;		///< wskaŸnik na nastêpny element listy transakcji

	/** Konstruktor.
	*/
	Transaction();

	/** Funkcja wyœwietla datê i kwotê transakcji.
	*/
	void showTrans();
};
#endif