// zad 4 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

long double lotto(unsigned int no, unsigned int ch, unsigned int k);


int main()
{
	long double lot = lotto(49, 6,27);
	std::cout << lot;


	system("PAUSE");
    return 0;
}

long double lotto(unsigned int no, unsigned int ch,unsigned int k) {
	long double result = 1.0;
	long double n;
	long double b;
	unsigned p;

	for (n = no, p = ch,b=k; p > 0; n--, p--,k--)
		result = result*n /p*(k);
	return result;
}

