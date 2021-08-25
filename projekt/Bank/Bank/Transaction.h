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
	Transaction* nextT;		///< wska�nik na nast�pny element listy transakcji

	/** Konstruktor.
	*/
	Transaction();

	/** Funkcja wy�wietla dat� i kwot� transakcji.
	*/
	void showTrans();

	/** Funkcja wy�wietla podpisan� dat� i kwot� transakcji.
	*/
	void showSignedTrans();

	/** Funkcja zwraca liczb� w odpowiednim formacie to znaczy:
	ze znakiem "+" lub "-" i dok�adno�ci� do dw�ch miejsc po przecinku.
	*@param amount liczba do sformatowania
	*@return odpowiednio sformatowana liczba jako ci�g znak�w
	*/
	string formatAmount();
};
#endif