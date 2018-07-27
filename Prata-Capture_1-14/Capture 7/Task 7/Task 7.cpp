#include "stdafx.h"
#include <iostream>

double *fill_array(double ar[], int limit);
void show_array(double arr[], double *n); //nie zmienia danych
void revalue(double r, double arr[], double *n);


int main()
{
	const int Max = 5;

	double properties[Max];



	double *size = fill_array(properties, Max);
	
	
	show_array(properties, size);

	

	if (size > 0) {
		std::cout << "Podaj czynnik zmiany wartosci: ";
		double factor;
		while (!(std::cin >> factor)) { //nie liczbowa wartosc na miejscu
			std::cin.clear();
			while (std::cin.get() != 'n')
				continue;
			std::cout << "Niepoprawna wartosc, podaj jeszcze raz: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	
	std::cout << "Gotowe.\n";

	system("PAUSE");
	return 0;
}

double *fill_array(double ar[], int limit) {
	double tmp;
	int i;
	
	for (i = 0; i < limit; i++) {
		std::cout << "Podaj wartosc nr " << i + 1 << ": ";
		std::cin >> tmp;
	

		if (!std::cin) {
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "bledne dane, wprowadzenie danych przerwane.\n";
			break;
		}
		else if (tmp < 0)
			break;
		ar[i] = tmp;
		
	}
	
	return ar+i;
}

void show_array(double arr[], double *n) {
	
	int i = 0;
   while(&arr[i]!=n){

		std::cout << "Nieruchomosc nr " << i + 1 << ": ";
		std::cout << arr[i] << "\n";
		i++;
	}
}

void revalue(double r, double arr[], double *n) {
	int i = 0;
	while (&arr[i] != n) {

		arr[i] *= r;
		i++;
	}
		
}