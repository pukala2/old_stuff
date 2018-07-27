// zad 5 rozdzial 11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "stonewt.h"



int main()
{
	Stonewt incognito = 275;  //inicjalizacja konstruktorem
	Stonewt wolfe(285.7);  //rowowazne instrukcji: Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);
	Stonewt suma = incognito + wolfe;
	Stonewt roznica = incognito - wolfe;
	Stonewt iloraz= incognito / wolfe;
	Stonewt iloczyn = incognito*wolfe;


	std::cout << incognito;
	std::cout << wolfe;
	std::cout << taft;
	std::cout << suma;
	std::cout << roznica;
	std::cout << iloraz;
	std::cout << iloczyn;



	system("PAUSE");
	return 0;



}
