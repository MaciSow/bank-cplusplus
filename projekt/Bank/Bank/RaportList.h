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
	Raport* rHead;		///< wskaŸnik na g³owê listy raportu

	/** Konstruktor.
	*/
	RaportList();

	/** Dekonstruktor, usuwa listê raportu wywo³any poleceniem delete.
	*/
	~RaportList();

	/** Funkcja dodaje nowy element do listy raportu.
	*@param date data transakcji
	*@param amount kwota transakcji
	*/
	void addItem(Raport* item);

	/** Funkcja wyœwietla wszystkie elementy listy raportu w formie numer konta, data i kwota transakcji.
	*/
	void showRaportTransaction();

	/** Funkcja wyœwietla wszystkie elementy listy raportu w formie numer konta i nazwisko u¿ytkownika.
	*/
	void showRaportDebit();

	/** Funkcja do obs³ugi raportu transakcji pyta o zakres dat i odnoœnik do sortowania (data, kwota transakcji, numer konta).
	*@param list wskaŸnik na listê kont
	*/
	void raportTransactions(AccountList* list);

	/** Funkcja do obs³ugi raportu u¿ytkowników pyta o odnoœnik do sortowania (nazwisko, numer konta).
	*@param list wskaŸnik na listê kont
	*/
	void raportDebitUsers(AccountList* list);

	/** Funkcja do obs³ugi sortowania raportu transakcji.
	*@param sortType numer odnoœnika do sortowania
	*/
	void sortRaportTransaction(int sortType);

	/** Funkcja do obs³ugi sortowania raportu u¿ytkowników.
	*@param sortType numer odnoœnika do sortowania
	*/
	void sortRaportDebit(int sortType);

	/** Funkcja sortuje listê raportu rosn¹co wed³ug daty metod¹ b¹belkow¹.
	*/
	void sortByDate();

	/** Funkcja sortuje listê raportu rosn¹co wed³ug kwot transakcji metod¹ b¹belkow¹.
	*/
	void sortByAmount();

	/** Funkcja sortuje listê raportu rosn¹co wed³ug numerów kont metod¹ b¹belkow¹.
	*/
	void sortByAccount();

	/** Funkcja sortuje listê raportu rosn¹co wed³ug nazwisk metod¹ b¹belkow¹.
	*/
	void sortBySurname();

	/** Funkcja zamienia kolejnoœci¹ dwie transakcjê.
	*@param a wskaŸnik na pierwsz¹ transakcjê do zamiany
	*@param b wskaŸnik na drug¹ transakcjê do zamiany
	*/
	void swap(Raport* a, Raport* b);

	/** Funkcja zwraca liczbê w odpowiednim formacie to znaczy:
	ze znakiem "+" lub "-" i dok³adnoœci¹ do dwóch miejsc po przecinku.
	*@param amount liczba do sformatowania
	*@return odpowiednio sformatowana liczba jako ci¹g znaków
	*/
	string formatAmount(double amount);

	/** Funkcja zamienia wszystkie du¿e litery podanego s³owa na ma³e.
	*@param word s³owo do sformatowania
	*@return odpowienio sformatowan s³owo jako ci¹g znaków
	*/
	string strinfToLower(string word);

	/** Funkcja sprawdza czy podana data mieœci siê w zakresie dwóch podanych dat.
	*@param checkedDate sprawdzana data
	*@param startDate data otwieraj¹ca zakres
	*@param stopDate data zamykaj¹ca zakres
	*@return prawda gdy data znajduje siê w podanym zakresie w przeciwnym wypadku fa³sz
	*/
	bool checkDatesOrder(string youngDate, string oldDate);
};
#endif