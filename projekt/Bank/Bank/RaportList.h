/** @file */

#ifndef RAPORTLIST_H
#define RAPORTLIST_H

#include <iostream>
#include <string>

#include "Raport.h"
#include "AccountList.h"
#include "Account.h"
#include "Transaction.h"

using namespace std;

/**
	Struktura listy raportu.
*/
struct RaportList
{
	Raport* rHead;		///< wska�nik na g�ow� listy raportu

	/** Konstruktor.
	*/
	RaportList();

	/** Dekonstruktor, usuwa list� raportu wywo�any poleceniem delete.
	*/
	~RaportList();

	/** Funkcja dodaje nowy element do listy raportu.
	*@param date data transakcji
	*@param amount kwota transakcji
	*/
	void addItem(Raport* item);

	/** Funkcja wy�wietla wszystkie elementy listy raportu w formie numer konta, data i kwota transakcji.
	*/
	void showRaportTransaction();

	/** Funkcja wy�wietla wszystkie elementy listy raportu w formie numer konta i nazwisko u�ytkownika.
	*/
	void showRaportDebit();

	/** Funkcja do obs�ugi raportu transakcji pyta o zakres dat i odno�nik do sortowania (data, kwota transakcji, numer konta).
	*@param list wska�nik na list� kont
	*/
	void raportTransactions(AccountList* list);

	/** Funkcja do obs�ugi raportu u�ytkownik�w pyta o odno�nik do sortowania (nazwisko, numer konta).
	*@param list wska�nik na list� kont
	*/
	void raportDebitUsers(AccountList* list);

	/** Funkcja do obs�ugi sortowania raportu transakcji.
	*@param sortType numer odno�nika do sortowania
	*/
	void sortRaportTransaction(int sortType);

	/** Funkcja do obs�ugi sortowania raportu u�ytkownik�w.
	*@param sortType numer odno�nika do sortowania
	*/
	void sortRaportDebit(int sortType);

	/** Funkcja sortuje list� raportu rosn�co wed�ug daty metod� b�belkow�.
	*/
	void sortByDate();

	/** Funkcja sortuje list� raportu rosn�co wed�ug kwot transakcji metod� b�belkow�.
	*/
	void sortByAmount();

	/** Funkcja sortuje list� raportu rosn�co wed�ug numer�w kont metod� b�belkow�.
	*/
	void sortByAccount();

	/** Funkcja sortuje list� raportu rosn�co wed�ug nazwisk metod� b�belkow�.
	*/
	void sortBySurname();

	/** Funkcja zamienia kolejno�ci� dwie transakcj�.
	*@param a wska�nik na pierwsz� transakcj� do zamiany
	*@param b wska�nik na drug� transakcj� do zamiany
	*/
	void swap(Raport* a, Raport* b);

	/** Funkcja zwraca liczb� w odpowiednim formacie to znaczy:
	ze znakiem "+" lub "-" i dok�adno�ci� do dw�ch miejsc po przecinku.
	*@param amount liczba do sformatowania
	*@return odpowiednio sformatowana liczba jako ci�g znak�w
	*/
	string formatAmount(double amount);

	/** Funkcja zamienia wszystkie du�e litery podanego s�owa na ma�e.
	*@param word s�owo do sformatowania
	*@return odpowienio sformatowan s�owo jako ci�g znak�w
	*/
	string strinfToLower(string word);

	/** Funkcja sprawdza czy podana data mie�ci si� w zakresie dw�ch podanych dat.
	*@param checkedDate sprawdzana data
	*@param startDate data otwieraj�ca zakres
	*@param stopDate data zamykaj�ca zakres
	*@return prawda gdy data znajduje si� w podanym zakresie w przeciwnym wypadku fa�sz
	*/
	bool checkDatesOrder(string youngDate, string oldDate);
};
#endif