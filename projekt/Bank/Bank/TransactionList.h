#ifndef TRANSACTIONLIST_H  
#define TRANSACTIONLIST_H  

#include <string>
using namespace std;

struct Transaction
{
	string date = "";
	double amount = 0;
	Transaction* nextT;

	Transaction() {
		nextT = 0;
	}

	void showTrans() {
		cout << date << endl << amount << endl;
	}

};

struct TransactionList
{
	Transaction* tHead;

	void addTransaction(string date, double amount)
    {
        Transaction* newTrans = new Transaction;    // tworzy nowy element listy

        // wype³niamy naszymi danymi
        newTrans->date = date;
        newTrans->amount= amount;

        if (tHead == 0) // sprawdzamy czy to pierwszy element listy
        {
            // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
            tHead = newTrans;
        }

        else
        {
            // w przeciwnym wypadku wêdrujemy na koniec listy
            Transaction* tmp = tHead;

            while (tmp->nextT)
            {
                // znajdujemy wskaŸnik na ostatni element
                tmp = tmp->nextT;
            }

            tmp->nextT = newTrans;  // ostatni element wskazuje na nasz nowy
            newTrans->nextT = 0;     // ostatni nie wskazuje na nic
        }
    }
	
    void showTransactions() {
        
           // wskaznik na pierszy element listy
            Transaction* temp = tHead;

            // przewijamy wskazniki na nastepne elementy
            while (temp)
            {
                cout << "data: " << temp->date << " kwota: " << temp->amount << endl;
                temp = temp->nextT;
            }
        
    }

    void deleteList() {
        
        while (tHead) {
            Transaction* tmpTrans;
                tmpTrans = tHead -> nextT;
                delete tHead;
                tHead = tmpTrans;
        }
    }
	
    TransactionList() {
		tHead = 0;
	}
};

#endif 
