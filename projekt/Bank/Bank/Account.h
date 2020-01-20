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
	Struktura konta u¿ytkownika.
*/
struct Account
{
	long long accountNumber = 0;	///< numer konta u¿ytkownika
	string name = "";				///< imiê u¿ytkownika
	string surname = "";			///< nazwisko u¿ytkownika
	double balance = 0;				///< stan konta u¿ytkownika
	double debit = 1000;			///< debet posiadany przez u¿ytkownika
	TransactionList* transactions;	///< wskaŸnik na listê transakcji
	Account* nextA;					///< wskaŸnik na nastêpny element listy kont u¿ytkowników

	/** Konstruktor.
	*@param accountNumber numer konta u¿ytkownika
	*@param name imiê u¿ytkownika
	*@param surname nazwisko u¿ytkownika
	*@param balance stan konta u¿ytkownika
	*@param debit debet posiadany przez u¿ytkownika
	*@param transactions wskaŸnik na listê transakcji
	*/
	Account(long long accountNumber, string name, string surname, double balance, double debit, TransactionList*& transactions);

	/** Dekonstruktor, usuwa konto wywo³any poleceniem delete.
	*/
	~Account();

	/** Funkcja wyœwietla informacje o koncie wraz z wyci¹giem transakcji.
	*/
	void accountInfo();
	
	/** Funkcja pyta o kwotê i wyp³aca j¹ z konta o ile na to pozwalaj¹ œrodki posiadane przez danego u¿ytkownika.
	*/
	void withdrawal();

	/** Funkcja pyta o kwotê i wp³aca j¹ na konto danego u¿ytkownika.
	*/
	void deposit();

	/** Funkcja pyta o kwotê i przelewa j¹ na konto odbiorcy, o ile pozwalaj¹ na to œrodki danego u¿ytkownika.
	*@param wskaŸnik na konto odbiorcy.
	*/
	void transfer(Account* receiver);

	/** Funkcja pyta o przedzia³ dat i wyœwietla wyci¹g z podsumowaniem danego konta 
	posortowany wed³ug daty z podanego przedzia³u.
	*/
	void accountStatement();

	/** Funkcja pobiera z systemu aktualn¹ datê w sposób polecany przez stronê Micorsoft.
	*@return aktualna data wraz z godzin¹ w formacie ISO 8601 (YYYY-MM-DDThh:mm)
	*/
	string getCurrentDate();

	/** Funkcja zaokr¹gla podan¹ liczbê w dó³ do dwóch miejsc po przecinku.
	*@param amount liczba do zaokr¹glenia w formacie double
	*@return zaokr¹glona liczba
	*/
	double roundAmount(double amount);

	/** Funkcja sprawdza czy podane daty s¹ w odpowiedniej kolejnoœci m³odsza-starsza.
	*@param youngDate pierwsza data do sprawdzenia, która powinna byæ m³odsza
	*@param oldDate druga data do sprawdzenia, która powinna byæ starsza
	*@return prawda gdy daty s¹ w odpowiedniej kolejnoœci w przeciwnym wypadku fa³sz
	*/
	bool checkDatesOrder(string youngDate, string oldDate);

	/** Funkcja sprawdza czy podana data mieœci siê w zakresie dwóch podanych dat.
	*@param checkedDate sprawdzana data
	*@param startDate data otwieraj¹ca zakres
	*@param stopDate data zamykaj¹ca zakres
	*@return prawda gdy data mieœci siê w podanym zakresie w przeciwnym wypadku fa³sz
	*/
	bool checkDateInRange(string checkedDate, string startDate, string stopDate);
};
#endif 