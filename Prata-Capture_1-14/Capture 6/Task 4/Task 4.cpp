// zad 4 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct zpdw {
	std::string imie;
	std::string stanowisko;
	std::string pseudonim;
	int preferencje;

	zpdw() {
		std::cout << "Podaj imie:";
		std::cin >> imie.c_str;
	}

	

};



void menu();

int main()
{
	zpdw x[5];

	
	
	menu();


	system("PAUSE");
    return 0;
}

void menu() {
	std::cout << "a)Lista wg imion\n";
	std::cout << "b)Lista wg stanowisk\n";
	std::cout << "c)Lista wg pseudonimow\n";
	std::cout << "d)Lista wg preferencji\n";
	std::cout << "e)koniec";
}

