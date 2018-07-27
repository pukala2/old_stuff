// zad 8 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>


int main()
{
	char ch;

	std::ofstream outFile;
	outFile.open("zad 8.txt");

	std::cout << "Wprowadz zdanie a ja policze znaki, zdanie zakoncz '@':";
	
	int i = 0;

	while (std::cin.get(ch) && ch != '@') {
		outFile << ch;
		i++;
	}

	std::cout << "W pliku jest " << i << " znakow\n";
	system("PAUSE");
    return 0;
}

