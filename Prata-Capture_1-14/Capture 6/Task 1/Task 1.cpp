// zad 1 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>

int main()
{
	
	char ch;

	do{
		std::cin.get(ch);
		if (ch == '@')
			continue;
		if (ch >= '0'&&ch <= '9')
			continue;
		
		if (ch == toupper(ch))
			ch = tolower(ch);
		else
			ch = toupper(ch);
		
		std::cout << ch;
	} while (ch != '@');

	std::cout<<std::endl;

	system("PAUSE");
    return 0;
}

