// zad 2 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

float *load(float a[], int size);
void show(float *a);
double sr(float *a);

static int x = 0;

const int MAX = 10;

int main()
{
	float ar[MAX];

	load(ar, MAX);
	show(ar);
	float srednia = sr(ar);
	std::cout <<"Srednia wynosi :"<< srednia << std::endl;
	
		
	system("PAUSE");
    return 0;
}

float *load(float a[],int size) {
	std::cout << "Podaj 1 wartosc:";
	while((std::cin >> a[x])&&(x<size-1)){
		x++;
		std::cout << "Podaj " << x + 1 << " wartosc:";
	}
	return a;
}

void show(float *a) {
	for (float *i = a; i != a + x+1; *i++) 
		std::cout << *i << std::endl;
}

double sr(float *a) {
	float count = 0;
	for (float *i = a; i != a + x; *i++) {
		count += *i;
	}
	return count / x;
}