/** @file */

#ifndef TRANSACTION_H  
#define TRANSACTION_H  

#include <iostream>
#include <string>

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

	/** Funkcja wyœwietla podpisan¹ datê i kwotê transakcji.
	*/
	void showSignedTrans();

	/** Funkcja zwraca liczbê w odpowiednim formacie to znaczy:
	ze znakiem "+" lub "-" i dok³adnoœci¹ do dwóch miejsc po przecinku.
	*@param amount liczba do sformatowania
	*@return odpowiednio sformatowana liczba jako ci¹g znaków
	*/
	string formatAmount();
};
#endif