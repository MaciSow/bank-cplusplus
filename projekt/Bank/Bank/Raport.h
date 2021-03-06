/** @file */

#ifndef RAPORT_H
#define RAPORT_H

#include <string>

using namespace std;

/**
	Struktura elementu listy raportu.
*/
struct Raport
{
	long long accountNumber = 0;	///< numer konta użytkownika
	string surname = "";			///< nazwisko użytkownika
	string date;					///< data transakcji 
	double amount = 0;				///< kwota transakcji
	Raport* nextR;					///< wskaźnik na następny element listy raportu

	/** Konstruktor.
	*@param accountNumber numer konta użytkownika
	*@param date data transakcji
	*@param amount kwota transakcji
	*/
	Raport(long long accountNumber, string date, double amount);

	/** Konstruktor.
	*@param accountNumber numer konta użytkownika
	*@param surname nazwisko użytkownika
	*/
	Raport(long long accountNumber, string surname);
};

#endif