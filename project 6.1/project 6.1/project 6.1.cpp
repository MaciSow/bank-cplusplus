#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int N = 10;

struct CZAS {
	int h;
	int m;
	CZAS() : h(0), m(0) {}
};

struct AUT
{
	int nr;
	CZAS czas[N];
	AUT* nast;

};

void dodajDoL(AUT*& g, AUT* nowy) {
	nowy->nast = g;
	g = nowy;
}

void wczytaj(AUT*& g, const char* nazwa)
{
	ifstream plik(nazwa);

	if (!plik || !plik.is_open())
	{
		cout << "Nie ma pliku" << endl;
	}
	string linia;
	int liczba = 0;
	char liniac[100];

	AUT* nowy;
	while (!plik.eof())
	{
		nowy = new AUT;
		plik.getline(liniac, 100);
		nowy->nr = stoi(liniac);
		int i = 0;
		while (!plik.eof())
		{
			plik.getline(liniac, 100);
			if (liniac[0] == 0)
				break;
			nowy->czas[i].h = stoi(liniac);
			int j = 0;
			for (; j < 100 && liniac[j] != ':'; ++j);
			nowy->czas[i].m = stoi(liniac + j + 1);
			++i;
		}
		dodajDoL(g, nowy);
	}
	plik.close();
}
void wypisz(AUT* a)
{
	if (a == NULL) return;
	cout << a->nr << endl;
	for (int i = 0; i < N; ++i)
	{
		if (a->czas[i].h == 0 && a->czas[i].m == 0) break;
		cout << a->czas[i].h << ":" << a->czas[i].m << ";";
	}
	cout << endl;
}

void wypiszL(AUT* g)
{
	while (g)
	{
		wypisz(g);
		g = g->nast;
	}
}

void usun(AUT*& g)
{
	AUT* tmp;
	while (g)
	{
		tmp = g->nast;
		delete g;
		g = tmp;
	}
	g = NULL;
}



//void sort(avr*& g) {}

void ZnajdzNajw(AUT* g)
{
	AUT*pop
	int naj=0;
	while (g->nast)
	{
		if (naj < g->nr)  naj = g->nr;
			g = g->nast;
	}
	cout << naj << endl;
}



int main(int argc, char*argv[])
{
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}
	
	
	AUT* g = NULL;

	//ZnajdzNajw(g);
	wczytaj(g, "list.txt");
	/*wypiszL(g);

	usun(g);
	wypiszL(g);*/
	wypisz(g);


	cin.get();
	_CrtDumpMemoryLeaks();
	return 1;
}