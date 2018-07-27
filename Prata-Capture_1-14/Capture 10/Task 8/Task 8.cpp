#include "stdafx.h"
#include <iostream>
#include "header.h"
#include <cstdlib>

using namespace Client;



int main()
{
	Object tmp;
	Stack x;
	char ch;

	menu();
	while (std::cin >> ch && toupper(ch) != '5') {
		while (std::cin.get() != '\n')
			continue;
		switch (ch) {
		case '1':
			if (x.isfull())
				std::cout << "Stos pelen!\n";
			else
				x.push(tmp);
			break;
		case '2': if (x.isempty())
			std::cout << "Stos Pusty!\n";
				  else {
					  x.pop(tmp);
					  std::cout << "Deklaracja " << tmp.fullname << " zdjeta\n";
				  }
				  break;
		case '3':
			x.show();
			break;
		case '4':
			x.visit(funkcja);
			break;		
		}
		getchar();
		system("cls");
		menu();
	}
		std::cout << "Fajrant!\n";
	
	system("PAUSE");
	return 0;
}

