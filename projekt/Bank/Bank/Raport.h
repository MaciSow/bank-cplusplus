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
	long long accountNumber = 0;	///< numer konta u¿ytkownika
	string surname = "";			///< nazwisko u¿ytkownika
	string date;					///< data transakcji 
	double amount = 0;				///< kwota transakcji
	Raport* nextR;					///< wskaŸnik na nastêpny element listy raportu

	/** Konstruktor.
	*@param accountNumber numer konta u¿ytkownika
	*@param date data transakcji
	*@param amount kwota transakcji
	*/
	Raport(long long accountNumber, string date, double amount);

	/** Konstruktor.
	*@param accountNumber numer konta u¿ytkownika
	*@param surname nazwisko u¿ytkownika
	*/
	Raport(long long accountNumber, string surname);
};

#endif