#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct osoba
{
	string imie;
	string nazwisko;
	int ocena;
	int wiek;

	void podaj_dane()
	{
		cout << "Podaj imie:";
		getline(cin, imie);
		cout << "Podaj nazwisko:";
		cin >> nazwisko;
		cout << "Podaj ocene:";
		cin >> ocena;
		cout << "Podaj wiek:";
		cin >> wiek;
		cout << endl << endl;
	}

};

int main()
{
	osoba *baba = new osoba;

	baba->podaj_dane();
	baba->ocena += -1;

	cout << "Nazwisko:" << baba->nazwisko << ", " << baba->imie<<endl;
	cout << "Ocena:" << baba->ocena<<endl;
	cout << "wiek:" << baba->wiek<<endl<<endl;
	

	


	system("PAUSE");
    return 0;
}

