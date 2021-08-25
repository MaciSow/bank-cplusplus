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
	Transaction* nextT;		///< wska�nik na nast�pny element listy transakcji

	/** Konstruktor.
	*/
	Transaction();

	/** Funkcja wy�wietla dat� i kwot� transakcji.
	*/
	void showTrans();
};
#endif