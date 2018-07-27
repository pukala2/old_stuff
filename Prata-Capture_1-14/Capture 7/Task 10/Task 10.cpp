// zad 10 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

double calculate(double a, double b, double(*p)(double p1, double p2));
double add1(double x, double y);
double add2(double x, double y);
double add3(double x, double y);
typedef double(*ptr_wsk)(double x, double y);

const int size = 3;




int main()
{
	ptr_wsk arr[size] = { add1,add2,add3 };

	for (int i = 0; i < size; i++) {
		double a, b;
		std::cout << "Podaj dwie wartosci :";
		std::cin >> a >> b;
		double x=calculate(a, b, arr[i]);
		std::cout << "Twoj wynik to :" << x << std::endl;
	}
	
	system("PAUSE");
    return 0;
}

double calculate(double a, double b, double(*p)(double p1, double p2)) {
	return p(a, b);
}


double add1(double x, double y) {
	return x + y;
}

double add2(double x, double y) {
	return x * y;
}

double add3(double x, double y) {
	return x / y;
}