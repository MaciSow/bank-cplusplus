/** @file */

#ifndef TRANSACTIONLIST_H  
#define TRANSACTIONLIST_H  

#include <iostream>
#include <string>

#include "Transaction.h"

using namespace std;

/**
	Struktura listy transakcji.
*/
struct TransactionList
{
	Transaction* tHead;		///< wska�nik na g�ow� listy transakcji

	/** Konstruktor.
	*/
	TransactionList();

	/** Destruktor, usuwa liste transakcji wywo�any poleceniem delete.
	*/
	~TransactionList();

	/** Funkcja dodaje now� transakcj� do listy transakcji.
	*@param date data transakcji
	*@param amount kwota transakcji
	*/
	void addTransaction(string date, double amount);

	/** Funkcja wyszukuje transakcj� na podstawie daty i kwoty.
	*@param date data transakcji
	*@param amount kwota transakcji
	*@return wska�nik na znalezion� transakcj� o ile istnieje w przeciwnym przypadku NULL
	*/
	Transaction* findTransaction(string date, double amount);

	/** Funkcja usuwa transakcj� z listy transakcji.
	*@param transaction wska�nik na transakcj� przeznaczon� do usuni�cia
	*/
	void deleteTransaction(Transaction* transaction);

	/** Funkcja wy�wietla wszystkie transakcje z listy transakcji.
	*/
	void showTransactions();

	/** Funkcja sortuje list� transakcji rosn�co wed�ug daty metod� b�belkow�
	*/
	void dateSort();

	/** Funkcja zamienia kolejno�ci� dwie transakcj�
	*@param a wska�nik na pierwsz� transakcj� do zamiany
	*@param b wska�nik na drug� transakcj� do zamiany
	*/
	void swap(Transaction* a, Transaction* b);

	/** Funkcja sprawdza czy podane daty s� w odpowiedniej kolejno�ci m�odsza-starsza.
	*@param youngDate pierwsza data do sprawdzenia, kt�ra powinna by� m�odsza
	*@param oldDate druga data do sprawdzenia, kt�ra powinna by� starsza
	*@return prawda lub fa�sz w zale�no�ci od tego czy daty s� w odpowiedniej kolejno�ci
	*/
	bool checkDatesOrder(string youngDate, string oldDate);
};
#endif 
