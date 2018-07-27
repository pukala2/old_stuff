#include "stdafx.h"
#include <iostream>
#include "sales.h"

using namespace SALES;

Sales::Sales(const double ar[], int n) {
	min = ar[0];
	max = ar[0];
	average = ar[0];

	for (int i = 1; i < n; i++) {
		if (min > ar[i])
			min = ar[i];
		if (max < ar[i])
			max = ar[i];
		average += ar[i];
	}
	average /= n;

	for (int i = 0; i < QUATERS; i++)
		sales[i] = 0;
}

Sales::Sales() {
	for (int i = 0; i < QUATERS; i++) {
		std::cout << "Podaj wartosc " << i + 1 << " SALES : ";
		std::cin >> sales[i];
	}
	
	average = 0;
	min = sales[0];
	for (int i = 1; i < QUATERS; i++) {
		if (min > sales[i])
			min = sales[i];
	}

	max = sales[0];
	for (int i = 1; i < QUATERS; i++) {
		if (max < sales[i])
			max = sales[i];
	}

	for (int i = 0; i < QUATERS; i++)
		average += sales[i];
	average /= QUATERS;
}

void Sales::showSales()const {
	std::cout << "Najmniejsza wartosc = " << min << std::endl;
	std::cout << "Najwieksza wartosc = " << max << std::endl;
	std::cout << "Srednia wartosc = " << average << std::endl;
	std::cout << std::endl;
}