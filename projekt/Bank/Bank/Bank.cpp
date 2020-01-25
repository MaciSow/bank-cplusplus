/** @file */

#include <iostream>
#include <fstream>
#include <string>

#include "AccountList.h"
#include "RaportList.h"

using namespace std;


int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	AccountList* accountList = new AccountList();

	bool correctSwitch = false;

	for (int i = 0; i < argc; i++)
	{
		string arg = argv[i];
		
		if (arg == "-h") {
			cout << "Dostêpne przelaczniki:\n"
				<< "-fin <nazwa_pliku>\n"
				<< "-wy <nr_konta> <kwota>\n" << "-we <nr_konta> <kwota>\n"
				<< "-wyciag <nr_konta> <data_otwieraj¹ca_zakres> <data_zamykaj¹ca_zakres>\n"
				<< "-undo <nr_konta> <data> <kwota>\n"
				<< "-wywe  <nr_konta_obci¹¿onego> <nr_konta_odbiorcy> <kwota>\n"
				<< "-rT <data_otwieraj¹ca_zakres> <data_zamykaj¹ca_zakres> <typ_sortowania>\n"
				<< "-rD <typ_sortowania>\n" << "-h Pomoc\n";
		}

		if (arg == "-fin") {
			string fileName = argv[i + 1];

			accountList->readData(fileName);

			for (int i = 0; i < argc; i++)
			{
				arg = argv[i];

				if (arg == "-wy") {
					string stringAccountNumber = argv[i + 1];
					long long accountNumber = stoll(stringAccountNumber);

					string stringAmount = argv[i + 2];
					double amount = stod(stringAmount);

					Account* account = accountList->findAccount(accountNumber);

					if (account) {
						account->withdrawal(amount);
					}
				}

				if (arg == "-we") {
					string stringAccountNumber = argv[i + 1];
					long long accountNumber = stoll(stringAccountNumber);

					string stringAmount = argv[i + 2];
					double amount = stod(stringAmount);

					Account* account = accountList->findAccount(accountNumber);

					if (account) {
						account->deposit(amount);
					}
				}

				if (arg == "-wyciag") {
					string stringAccountNumber = argv[i + 1];
					long long accountNumber = stoll(stringAccountNumber);

					string startDate = argv[i + 2];
					string stopDate = argv[i + 3];

					Account* account = accountList->findAccount(accountNumber);

					if (account) {
						account->accountStatement(startDate, stopDate);
					}
				}

				if (arg == "-undo") {
					string stringAccountNumber = argv[i + 1];
					string date = argv[i + 2];
					string stringAmount = argv[i + 3];
					long long accountNumber = stoll(stringAccountNumber);
					double amount = stod(stringAmount);

					Account* account = accountList->findAccount(accountNumber);

					if (account) {
						Transaction* transaction = account->transactions->findTransaction(date, amount);

						if (transaction != NULL)
						{
							account->transactions->deleteTransaction(transaction);
						}
					}
				}

				if (arg == "-wywe") {
					string stringAccountNumber = argv[i + 1];
					long long accountNumber = stoll(stringAccountNumber);

					Account* sender = accountList->findAccount(accountNumber);

					if (sender) {
						stringAccountNumber = argv[i + 2];
						accountNumber = stoll(stringAccountNumber);

						Account* receiver = accountList->findAccount(accountNumber);

						if (receiver) {
							string stringAmount = argv[i + 3];
							double amount = stod(stringAmount);

							sender->transfer(receiver, amount);
						}
					}
				}

				if (arg == "-rT") {
					cout << "Raport wykonanych operacji:\n";

					string startDate = argv[i + 1];
					string stopDate = argv[i + 2];

					string stringSortType = argv[i + 3];
					int sortType = stoi(stringSortType);

					RaportList* raportList = new RaportList();

					raportList->raportTransactions(accountList, startDate, stopDate, sortType);

					delete raportList;
				}

				if (arg == "-rD") {
					cout << "Raport uzytkownikow:\n";

					string stringSortType = argv[i + 1];
					int sortType = stoi(stringSortType);

					RaportList* raportList = new RaportList();

					raportList->raportDebitUsers(accountList, sortType);

					delete raportList;
				}
			}
			correctSwitch = true;
			break;
		}
	}
	if (correctSwitch) {
		accountList->saveData();
	}
	else
	{
		cout << "nie podano parametru -fin<plik>\n";
	}
	delete accountList;

	return 0;
}
