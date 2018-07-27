// zad 3 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void menu(void) {
	std::cout << "Wybierz jedna z opcji:\n";
	std::cout << "a) rosliny\n";
	std::cout << "b) zwierzeta\n";
	std::cout << "c) planety\n";
	std::cout << "d) samochody\n";
}

int main()
{

	menu();
	char ch;
	
	while (true){
		
		std::cin >> ch;

		if (ch == 'a') {
			std::cout << "Tulipan.\n";
			break;
		}
		else if (ch == 'b') {
			std::cout << "Pies.\n";
			break;
		}
		else if (ch == 'c') {
			std::cout << "Ziemia.\n";
			break;
		}

		else if (ch == 'd') {
			std::cout << "BMW.\n";
			break;
		}
		else {
			std::cout << "Wybierz prawidlowa opcje.\n";
			continue;
		}
	}
	system("PAUSE");
    return 0;
}

