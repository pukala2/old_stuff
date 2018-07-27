// zad 7 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


bool samogloskla(char x) {
	if (x == 'a' || x == 'e' || x == 'y' || x == 'o' || x == 'i' || x == 'u'||
		x == 'A' || x == 'E' || x == 'Y' || x == 'O' || x == 'I' || x == 'U')
		return true;
	else
		return false;
}

bool spolgloskla(char k) {
	if (k == 'w' || k == 'r' || k == 't' || k == 'p' || k == 's' || k == 'd' ||
		k == 'f' || k == 'g' || k == 'h' || k == 'j' || k == 'k' || k == 'l' ||
		k == 'x' || k == 'z' || k == 'c' || k == 'v' || k == 'b' || k == 'n' ||
		k == 'm' || 
		k == 'W' || k == 'R' || k == 'T' || k == 'P' || k == 'S' || k == 'D' ||
		k == 'F' || k == 'G' || k == 'H' || k == 'J' || k == 'K' || k == 'L' ||
		k == 'X' || k == 'Z' || k == 'C' || k == 'V' || k == 'B' || k == 'N' ||
		k == 'M')	
		return true;
	else
		return false;
}

int main()
{
	int samo = 0;
	int spol = 0;
	int reszta = 0;

	std::string str;
	std::cout << "Napisz zdanie i zakoncz je znakiem 'q':";
	std::getline(std::cin,str);

	char ch;

	ch = str[0];
	
	if (samogloskla(ch) == true)
		samo++;

	int i = 1;
	while (str[i] != 'q') {
		
		char temp=str[i];
		
		if ((samogloskla(temp) == true) && (str[i - 1] == ' '))
			samo++;

		else if ((spolgloskla(temp) == true) && (str[i - 1] == ' '))
			spol++;

		else if ((samogloskla(temp) != true) && (samogloskla(temp) != true)&&(str[i - 1] == ' '))
			reszta++;

			i++;		
	}

	std::cout <<"Slow zaczynajacych sie od samogloski:"<< samo<<"\n";
	std::cout << "Slow zaczynajacych sie od spolgloski:" << spol<<"\n";
	std::cout << "Slow zaczynajacych sie od innego znaku:" << reszta<<"\n";

	system("PAUSE");
	return 0;
}


