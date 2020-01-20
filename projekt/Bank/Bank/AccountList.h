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
	Struktura listy kont u¿ytkowników.
*/
struct AccountList
{
	Account* aHead;													///< wskaŸnik na g³owê listy kont u¿ytkowników
	string fileName = "";											///< nazwa pliku do odczytu
	string separator = "########################################";	///< separator

	/** Konstruktor,
	 *@return
	*/
	AccountList();

	/** Dekonstruktor, usuwa listê kont wywo³any poleceniem delete.
	 *@return usuniêta lista kont
	*/
	~AccountList();

	/** Funkcja dodaje nowe konto do listy kont.
	*@param account wskaŸnik na konto
	*/
	void addAccount(Account* account);

	/** Funkcja wyszukuje konto w liœcie na podstawie jego numeru.
	*@param accountNumber numer szukanego konta
	*@return wskaŸnik na znalezione konto o ile istnieje w przeciwnym przypadku NULL
	*/
	Account* findAccount(long long accountNumber);

	/** Funkcja wyœwietla informacje o kontach z listy.
	*/
	void showAccounts();

	/** Funkcja odczytuje dane z pliku i na ich podstawie tworzy listê kont.
	*@param fileName nazwa odczytywanego pliku
	*/
	void readData(string fileName);

	/** Funkcja nadpisuje w wczeœniej odczytanym pliku dane z listy kont.
	*/
	void saveData();
};
#endif