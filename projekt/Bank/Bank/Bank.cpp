#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"
#include "UsersList.h"

using namespace std;


int main(int argc, char* argv[])
{
	UserList userList;

	for (int i = 0; i < argc; i++)
	{
		string arg = argv[i];

		if (arg == "-fin") {
			string fileName;

			cout << "Podaj nazwe pliku wejsciowego: ";
			cin >> fileName;

			userList = readData(fileName);
			//	userList.showUsers();
		}

		if (arg == "-wy") {
			string stringNumberAcc = argv[i + 1];
			long long numberAcc = stoll(stringNumberAcc);

			Account user = userList.findUser(numberAcc);

			if (user.getAccountNumber() == 0) {
				cout << "Nie znaleziono podanego konta\n";
			}
			else {
				user.withdrawal();
			}
			i++;
		}

		if (arg == "-we") {
			string stringAccountNumber = argv[i + 1];
			long long accountNumber = stoll(stringAccountNumber);

			Account user = userList.findUser(accountNumber);

			if (user.getAccountNumber() == 0) {
				cout << "Nie znaleziono podanego konta\n";
			}
			else {
				user.deposit();
			}
			i++;
		}

		if (arg == "-wyciag") {
			long long accountNumber;

			cout << "Podaj numer konta: ";
			cin >> accountNumber;

			Account user = userList.findUser(accountNumber);

			if (user.getAccountNumber() == 0) {
				cout << "Nie znaleziono podanego konta\n";
			}
			else {
				user.accountStatement();
			}
		}

		if (arg == "-undo") {
			string stringAccountNumber = argv[i + 1];
			string date = argv[i + 2];
			string stringAmount = argv[i + 3];
			long long accountNumber = stoll(stringAccountNumber);
			double amount = stod(stringAmount);

			Account user = userList.findUser(accountNumber);

			if (user.getAccountNumber() == 0) {
				cout << "Nie znaleziono podanego konta\n";
			}
			else {
				Transaction* transaction = user.getTransactions().findTransaction(date,amount);
				
				if (transaction != NULL)
				{
					user.getTransactions().deleteTransakcion(transaction);
				}		
			}
			i = +3;;
			user.accountInfo();
		}

		if (arg == "-wywe") {
			cout << "Przelew z jednego konta na drugie" << endl;
		}

		if (arg == "-rT") {
			cout << "Raport wykonanych operacji" << endl;
		}

		if (arg == "-rD") {
			cout << "Raport uzytkownikow" << endl;
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
