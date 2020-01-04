#ifndef RAPORT_H
#define RAPORT_H

#include <string>

using namespace std;

struct Raport
{
	Raport* nextR;
	long long accountNumber = 0;
	double amount = 0;
	string date, surname = "";


	Raport(long long accountNumber, string date, double amount);

	Raport(long long accountNumber, string surname);
}; 

#endif