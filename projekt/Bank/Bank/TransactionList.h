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
	Transaction* tHead;		///< wskaŸnik na g³owê listy transakcji

	/** Konstruktor.
	*/
	TransactionList();

	/** Destruktor, usuwa liste transakcji wywo³any poleceniem delete.
	*/
	~TransactionList();

	/** Funkcja dodaje now¹ transakcjê do listy transakcji.
	*@param date data transakcji
	*@param amount kwota transakcji
	*/
	void addTransaction(string date, double amount);

	/** Funkcja wyszukuje transakcjê na podstawie daty i kwoty.
	*@param date data transakcji
	*@param amount kwota transakcji
	*@return wskaŸnik na znalezion¹ transakcjê o ile istnieje w przeciwnym przypadku NULL
	*/
	Transaction* findTransaction(string date, double amount);

	/** Funkcja usuwa transakcjê z listy transakcji.
	*@param transaction wskaŸnik na transakcjê przeznaczon¹ do usuniêcia
	*/
	void deleteTransaction(Transaction* transaction);

	/** Funkcja wyœwietla wszystkie transakcje z listy transakcji.
	*/
	void showTransactions();

	/** Funkcja sortuje listê transakcji rosn¹co wed³ug daty metod¹ b¹belkow¹
	*/
	void dateSort();

	/** Funkcja zamienia kolejnoœci¹ dwie transakcjê
	*@param a wskaŸnik na pierwsz¹ transakcjê do zamiany
	*@param b wskaŸnik na drug¹ transakcjê do zamiany
	*/
	void swap(Transaction* a, Transaction* b);

	/** Funkcja sprawdza czy podane daty s¹ w odpowiedniej kolejnoœci m³odsza-starsza.
	*@param youngDate pierwsza data do sprawdzenia, która powinna byæ m³odsza
	*@param oldDate druga data do sprawdzenia, która powinna byæ starsza
	*@return prawda lub fa³sz w zale¿noœci od tego czy daty s¹ w odpowiedniej kolejnoœci
	*/
	bool checkDatesOrder(string youngDate, string oldDate);
};
#endif 
