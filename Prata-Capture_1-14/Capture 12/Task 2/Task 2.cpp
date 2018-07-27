// zad 2 rozdzial 12.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "String2.h"


int main()
{
	StringBad s1("i ucze sie C++");
	StringBad s2 = "Podaj swoje imie: ";
	StringBad s3;
	
	std::cout << s2;
	std::cin >> s3;

	s2 = "Mam na imie " + s3;
	std::cout << s2 << std::endl;
	s2 = s2 + s1;
	s2.StringUP();
	std::cout << "Ciag \n" << s2 << "\zawiera " << s2.Howchar('A') << " 'A'.\n";
	
	s1 = "czerwona";
	StringBad rgb[3] = { StringBad(s1),StringBad("zielona"),StringBad("niebieska") };
	
	std::cout << "Podaj nazwe barwy podstawowej: ";
	StringBad ans;

	bool succes = false;
	while (std::cin >> ans) {
		ans.StringLOW();
		for (int i = 0; i < 3; i++) {
			if (ans == rgb[i]) {
				std::cout << "Prawidlowo!\n";
				succes = true;
				break;
			}
		}
		if (succes)
			break;
		else
			std::cout << "Sprobuj ponownie!\n";
	}
	std::cout << "Zegnam\n";

	system("PAUSE");
    return 0;
}

