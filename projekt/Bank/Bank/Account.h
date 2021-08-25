/** @file */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <time.h>

#include "TransactionList.h"
#include "Transaction.h"

using namespace std;

/**
	Struktura konta u�ytkownika.
*/
struct Account
{
	long long accountNumber = 0;	///< numer konta u�ytkownika
	string name = "";				///< imi� u�ytkownika
	string surname = "";			///< nazwisko u�ytkownika
	double balance = 0;				///< stan konta u�ytkownika
	double debit = 1000;			///< debet posiadany przez u�ytkownika
	TransactionList* transactions;	///< wska�nik na list� transakcji
	Account* nextA;					///< wska�nik na nast�pny element listy kont u�ytkownik�w

	/** Konstruktor.
	*@param accountNumber numer konta u�ytkownika
	*@param name imi� u�ytkownika
	*@param surname nazwisko u�ytkownika
	*@param balance stan konta u�ytkownika
	*@param debit debet posiadany przez u�ytkownika
	*@param transactions wska�nik na list� transakcji
	*/
	Account(long long accountNumber, string name, string surname, double balance, double debit, TransactionList*& transactions);

	/** Dekonstruktor, usuwa konto wywo�any poleceniem delete.
	*/
	~Account();

	/** Funkcja wy�wietla informacje o koncie wraz z wyci�giem transakcji.
	*/
	void accountInfo();
	
	/** Funkcja pyta o kwot� i wyp�aca j� z konta o ile na to pozwalaj� �rodki posiadane przez danego u�ytkownika.
	*/
	void withdrawal();

	/** Funkcja pyta o kwot� i wp�aca j� na konto danego u�ytkownika.
	*/
	void deposit();

	/** Funkcja pyta o kwot� i przelewa j� na konto odbiorcy, o ile pozwalaj� na to �rodki danego u�ytkownika.
	*@param wska�nik na konto odbiorcy.
	*/
	void transfer(Account* receiver);

	/** Funkcja pyta o przedzia� dat i wy�wietla wyci�g z podsumowaniem danego konta 
	posortowany wed�ug daty z podanego przedzia�u.
	*/
	void accountStatement();

	/** Funkcja pobiera z systemu aktualn� dat� w spos�b polecany przez stron� Micorsoft.
	*@return aktualna data wraz z godzin� w formacie ISO 8601 (YYYY-MM-DDThh:mm)
	*/
	string getCurrentDate();

	/** Funkcja zaokr�gla podan� liczb� w d� do dw�ch miejsc po przecinku.
	*@param amount liczba do zaokr�glenia w formacie double
	*@return zaokr�glona liczba
	*/
	double roundAmount(double amount);

	/** Funkcja sprawdza czy podane daty s� w odpowiedniej kolejno�ci m�odsza-starsza.
	*@param youngDate pierwsza data do sprawdzenia, kt�ra powinna by� m�odsza
	*@param oldDate druga data do sprawdzenia, kt�ra powinna by� starsza
	*@return prawda gdy daty s� w odpowiedniej kolejno�ci w przeciwnym wypadku fa�sz
	*/
	bool checkDatesOrder(string youngDate, string oldDate);

	/** Funkcja sprawdza czy podana data mie�ci si� w zakresie dw�ch podanych dat.
	*@param checkedDate sprawdzana data
	*@param startDate data otwieraj�ca zakres
	*@param stopDate data zamykaj�ca zakres
	*@return prawda gdy data mie�ci si� w podanym zakresie w przeciwnym wypadku fa�sz
	*/
	bool checkDateInRange(string checkedDate, string startDate, string stopDate);
};
#endif 