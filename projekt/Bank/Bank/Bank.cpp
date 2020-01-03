#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"
#include "AccountList.h"
#include "RaportList.h"

using namespace std;


int main(int argc, char* argv[])
{
	AccountList accountList;

	for (int i = 0; i < argc; i++)
	{
		string arg = argv[i];

		if (arg == "-fin") {
			string fileName;

			cout << "Podaj nazwe pliku wejsciowego: ";
			cin >> fileName;

			accountList = readData(fileName);
			//	userList.showUsers();
		}

		if (arg == "-wy") {
			string stringNumberAcc = argv[i + 1];
			long long numberAcc = stoll(stringNumberAcc);

			Account* account = accountList.findAccount(numberAcc);

			if (account) {
				account->withdrawal();
			}
			i++;
		}

		if (arg == "-we") {
			string stringAccountNumber = argv[i + 1];
			long long accountNumber = stoll(stringAccountNumber);

			Account* account = accountList.findAccount(accountNumber);

			if (account) {
				account->deposit();
			}
			i++;
		}

		if (arg == "-wyciag") {
			long long accountNumber;

			cout << "Podaj numer konta: ";
			cin >> accountNumber;

			Account* account = accountList.findAccount(accountNumber);

			if (account) {
				account->accountStatement();
			}
		}

		if (arg == "-undo") {
			string stringAccountNumber = argv[i + 1];
			string date = argv[i + 2];
			string stringAmount = argv[i + 3];
			long long accountNumber = stoll(stringAccountNumber);
			double amount = stod(stringAmount);

			Account* account = accountList.findAccount(accountNumber);

			if (account) {
				Transaction* transaction = account->getTransactions().findTransaction(date, amount);

				if (!transaction)
				{
					account->getTransactions().deleteTransakcion(transaction);
				}
			}
			i = +3;
			account->accountInfo();
		}

		if (arg == "-wywe") {
			long long accountNumber;

			cout << "Podaj nr konta z ktorego ma byc wyplacona gotowka: ";
			cin >> accountNumber;

			Account* sender = accountList.findAccount(accountNumber);

			if (sender) {
				cout << "Podaj nr konta odbiorcy: ";
				cin >> accountNumber;

				Account* receiver = accountList.findAccount(accountNumber);

				if (receiver) {
					sender->transfer(receiver);
				}

			}
			accountList.showAccounts();
		}

		if (arg == "-rT") {
			cout << "Raport wykonanych operacji\n";

			RaportList raportT;
			
			raportT.raportTransactions(accountList);			
		}

		if (arg == "-rD") {
			cout << "Raport uzytkownikow\n";
			
			RaportList raportD;
			
			raportD.raportDebitUsers(accountList);
		}
	}



	/*userlist list = readdata();
	list.showusers();*/
	//Account acc = readData();
	//user user1(acc);

	//user1.print();

	//cin.get();
   // _CrtDumpMemoryLeaks();
	return 0;
}
