#include "stdafx.h"
#include <iostream>
#include "sales.h"

/*
kopiuje najmniejszy z czterech lub n elementow tablicy ar
do skladowej sales struktury s i oblicza oraz zachowuje w odpowiednich
skladowych struktury sales wartosci: srednia,minimalna i maksymalna
zeruje pozostale elementy tablicy sales(jesli sa)
*/
void SALES::setSales(Sales &s, const double ar[], int n) {
	
	s.min =ar[0];
	s.max = ar[0];
	s.average =ar[0];
	
	for (int i = 1; i < n; i++) {
		if (s.min > ar[i])
			s.min = ar[i];
		if (s.max < ar[i])
			s.max = ar[i];
		s.average += ar[i];
	}
	s.average /= n;
	
	for (int i = 0; i < QUATERS; i++)
		s.sales[i] = 0;
}
/*pobiera interaktywnie informacje dla 4 kwartalow]
zachowuje je w skladowej sales struktury s i oblicza oraz zachowuje
w odpowiednich skladowych s wartosc srednia,minimalna i maaksymalna*/

void SALES::setSales(Sales &s) {
	s.average = 0;
	s.min = s.sales[0];
	for (int i = 1; i < QUATERS; i++) {
		if (s.min > s.sales[i])
			s.min = s.sales[i];
	}
	
	s.max = s.sales[0];
	for (int i = 1; i < QUATERS; i++) {
		if (s.max < s.sales[i])
			s.max = s.sales[i];
	}
	
	for (int i = 0; i < QUATERS; i++)
		s.average += s.sales[i];
	s.average /= QUATERS;
}

//wyswietla komplet informacji
void SALES::showSales(const Sales &s) {
	std::cout << "Najmniejsza wartosc = " << s.min << std::endl;
	std::cout << "Najwieksza wartosc = " << s.max << std::endl;
	std::cout << "Srednia wartosc = " << s.average << std::endl;
	std::cout << std::endl;
}