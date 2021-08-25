/** @file */

#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H  

#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"
#include "TransactionList.h"

using namespace std;

/**
	Struktura listy kont u�ytkownik�w.
*/
struct AccountList
{
	Account* aHead;													///< wska�nik na g�ow� listy kont u�ytkownik�w
	string fileName = "";											///< nazwa pliku do odczytu
	string separator = "########################################";	///< separator

	/** Konstruktor,
	 *@return
	*/
	AccountList();

	/** Dekonstruktor, usuwa list� kont wywo�any poleceniem delete.
	 *@return usuni�ta lista kont
	*/
	~AccountList();

	/** Funkcja dodaje nowe konto do listy kont.
	*@param account wska�nik na konto
	*/
	void addAccount(Account* account);

	/** Funkcja wyszukuje konto w li�cie na podstawie jego numeru.
	*@param accountNumber numer szukanego konta
	*@return wska�nik na znalezione konto o ile istnieje w przeciwnym przypadku NULL
	*/
	Account* findAccount(long long accountNumber);

	/** Funkcja wy�wietla informacje o kontach z listy.
	*/
	void showAccounts();

	/** Funkcja odczytuje dane z pliku i na ich podstawie tworzy list� kont.
	*@param fileName nazwa odczytywanego pliku
	*/
	void readData(string fileName);

	/** Funkcja nadpisuje w wcze�niej odczytanym pliku dane z listy kont.
	*/
	void saveData();
};
#endif