// zad 7 rozdzial 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "complex0.h"


int main()
{
	Complex a(3.0, 4.0);
	Complex c;


	std::cout << "Podaj liczbe zespolona (k aby zakonczyc):\n";
	while (std::cin >> c) {
		std::cout << "c to " << c;
		std::cout << "sprzezona z c to " << -c;
		std::cout << "a to " << a;
		std::cout << "a + c wynosi " << a + c;
		std::cout << "a - c wynosi " << a - c;
		std::cout << "a * c wynosi " << a*c;
		std::cout << "2 * c wynosi " << 2 * c;
		std::cout << "Podaj liczbe zespolona (k aby zakonczyc):\n";
	}
	std::cout << "Gotowe";

	system("PAUSE");
    return 0;
}

