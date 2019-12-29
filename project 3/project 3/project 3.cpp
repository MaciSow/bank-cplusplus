#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;
/*int main()
{
	bool test = true;
	while (test){
		int i;
		cin >> i;
		if (!cin.good()) {
			cin.clear();
				cin.ignore(5000, '\n');
				cout << "to nie jest liczba";
		}
		else
			test = false;
		cout << "liczba: " << i << endl;
		}
	cin.get();
	return 0;
}
*/
/*int main()
{
	cout << "podaj co chcesz zrobic potega(1) wypisac(2)" << endl;
		bool test = true;
		int wybor;
		while (test) {
			cin >> wybor;
			if (wybor != 1 || wybor != 2)
			{
				cout << "zla liczba wpisz jeszcze raz\n";
				test = false;
			}
		}
			int i, liczba, wynik = 0, j, tab[20];
			switch (wybor) {
			case 1:

				cout << "podaj liczbe i potege " << endl;
				cin >> liczba >> i;
				wynik = liczba;
				for (i; i > 1; i--)
					wynik = wynik * liczba;
				cout << wynik;
				break;
			case 2:
				test = true;
				while (test) {
					cout << "podaj od ktorej ma byc odliczane \n";
					cin >> j;
					if (j > 0 && j < 21)
					{
						cout << "zla liczba wpisz jeszcze raz\n";
						test = false;
					}

					for (j; j > 1; j--)
						cout << j << endl;
				}
				break;
			}
			cin.get();
			return 0;
	}*/
/*int main()
{

	int tab[100], suma=0;
	srand (time NULL)
	for (int i=0; i<100;i++)
	{
		tab[i] = rand() % 100
		suma += tab[i];
	}
	cin.get();
	return 0;
}*/

int los(int max, int min)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> rozklad(min, max);
	return rozklad (silnik);
}

void init(int tabela[], int n)
{
	for (int i = 0; i < n; i++)
		tabela[i] = 0;
}
void wypisz(int tabela[], int n) 
{
		for (int i = 0; i < n; i++)
			cout << tabela[i] << " ";
}


void zamien(int & a, int & b) 
{
	int c;
	c = a;
	a = b;
	b = c;
}
void lostab(int tabela[], int n)
{
	for (int i = 0; i < n; i++)
		tabela[i] = los(400,0);
	
}
void sorttab(int tab[], int n) 
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (tab[j - 1] > tab[j])
				zamien(tab[j - 1], tab[j]);
}

void add2vec(int tabela[], int n, vector<int> &v, int p)
{
	for (int i = 0; i < n; i++)
	{
		if (tabela[i] > p)
			v.push_back(tabela[i]);
	}

}
void wypiszvec(vector<int>& v) 
{
	for (std::size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
}

int main()
{
	vector<int> v;
	cout << los(300, 30);
	
	const int N = 10;
	int tab[N];
	init(tab, N);
	int p = 200;
	return 0;

}