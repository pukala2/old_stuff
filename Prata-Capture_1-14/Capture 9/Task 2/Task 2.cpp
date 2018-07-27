// zad 2 rozdzial 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


void strcount(std::string str);

int main()
{
	
	std::string word;
	

	std::cout << "Wprowadz wiersz:\n";
	while (std::getline(std::cin, word)&&word[0]!=0) {
		strcount(word);
		std::cout << "Wprowadz wiersz (enter konczy funkcje) :\n";
	}
	std::cout << "Koniec\n";
	system("PAUSE");
	return 0;
}

void strcount(std::string str) {
	static int total = 0; //statyczna zmienna lokalna
	int count = 0; //automatyczna zmienna lokalna
		
	count = str.length();
		total += count;
		std::cout << count << " znakow\n";
		std::cout << "lacznie " << total << " znakow\n";

	}
