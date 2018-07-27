// zad 2 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>


int main()
{
	std::array<double,10>x;
	double suma = 0;

	std::cout << "Prosze podac maksymalnie 10 wartosci:\n";
	std::cout << "Podaj 1:";
		int i = 0;
		while (i<10 && std::cin >> x[i]) {
			suma += x[i];
			if (++i < 10) {
				std::cout << "Podaj " << i + 1 << ":";
			}	
		}

	double srednia=suma/i;
		
	for (int k = 0; k < i; k++) {
			if (x[k] > srednia)
				std::cout << x[k]<<"\n";
		}


	system("PAUSE");
    return 0;
}

