// zad 5 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

long double sil(int n);

int main()
{
	long double value = sil(5);
	std::cout << value << std::endl;
    
	
	system("PAUSE");
	return 0;
}

long double sil(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return n*sil(n - 1);
}