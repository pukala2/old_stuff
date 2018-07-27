// zad 9 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

float liczby[4];
string imie[4];

int main()
{

	string linia;
	int nr_linii = 1;

	fstream plik;
	plik.open("pomiary.txt", ios::in);

	if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";

	int licznik = 0;
	int i = 0;

	while (!plik.eof())
	{
		if (licznik < 5) {
			getline(plik, linia);
			liczby[licznik] = atof(linia.c_str());
			licznik++;
		}
		else {
			getline(plik, linia);
			imie[i] = linia;
			i++;
		}
		licznik++;
	}
	
	
	
	plik.close();



	cout << "Ilosc pomiarow: " << licznik << endl << endl;

	for (int i = 0; i<licznik; i++)
	{
		cout << imie[i] << endl;
		cout << liczby[i] << endl;
	}

	system("PAUSE");
	return 0;
}



