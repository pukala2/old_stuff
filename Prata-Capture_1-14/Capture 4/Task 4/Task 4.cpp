#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string imie;
	string nazwisko;
	string przerwa = ", ";

	cout << "Podaj imie:"; cin >> imie;
	cout << "Podaj nazwisko:"; cin >> nazwisko;

	string suma = imie + przerwa + nazwisko;

	cout <<"O to informacje zestawione w jeden napis:"<< suma << endl;



	system("PAUSE");
    return 0;
}

