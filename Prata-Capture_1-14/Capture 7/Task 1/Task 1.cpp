// zad 1 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void licz(void);

int main()
{
	licz();

	system("PAUSE");
    return 0;
}

void licz(void) {
	float x, y;
	std::cout << "Wprowadz pare liczb a ja policze srednia harmoniczna\n";
	std::cout<<"Wpisanie zera konczy wykonywanie programu : ";
	while (std::cin >> x >> y && x != 0 && y != 0) {
		std::cout << "Srednia harmoniczna wynosi :" << (2.0*x*y) / (x + y) << std::endl;
		std::cout << "Wprowadz kolejna pare liczb:";
	}
	std::cout << "Gotowe.\n";
}