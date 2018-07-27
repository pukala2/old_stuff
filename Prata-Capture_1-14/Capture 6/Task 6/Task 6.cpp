// zad 6 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

const int size = 3;

struct Dobre_wplywy {
	std::string nazwisko;
	double kwota;
};

int main()
{
	Dobre_wplywy *ludzie;
	ludzie = new Dobre_wplywy[size];

	for (int i = 0; i < size; i++) {
		std::cout << "Podaj kwote:";
		std::cin >> ludzie[i].kwota;
		std::cout << "Podaj nazwe donatora:";
		std::cin >> ludzie[i].nazwisko;
	}

	
	for (int i = 0; i < size; i++) {
		if (ludzie[i].kwota >= 10000)
			std::cout << "Nasi wspaniali sponsorzy:" << ludzie[i].nazwisko << "\n";
		else
			std::cout << "Nasi sponsorzy:" << ludzie[i].nazwisko << "\n";
	}
	system("PAUSE");
    return 0;
}

