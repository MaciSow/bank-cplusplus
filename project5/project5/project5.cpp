
#include <iostream>

using namespace std;
void pow1(int *a)
{
	*a += 1;
}

void kwadrat(int* a)
{
	*a *= *a;
}

void set(int *a)
{
	cin >> *a;
}

void wykonaj(int *tablica[], int* a, int id)
{


}

void wpiszdotab(int tab[])
{
	for (int i = 0; i < 10; i++)
		cout << tab++ << endl;
}

void wypisztab(int tab[])
{
	for (int i = 0; i < 10; i++)
		cout << *tab++ << endl;
}

int main()
{
	
	
	int tabelka[10];
	for (int i = 0; i < 10; i++)
		tabelka[i] = i + 5;


	int b = 5;
	int *tab[3];
	//*tab[0] = pow1(&a);
	//*tab[1] = kwadrat(&a);
	//*tab[2] = set(&a);
	
	wpiszdotab(tabelka);
	wypisztab(tabelka);
	
	//cout << b << endl;
	set(&b);
	//cout << b;

}

