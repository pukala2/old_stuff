// zad 1 rozdzial 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>   //prototypy funkcji rand() i srand()
#include <time.h>    //prototyp funkcji time
#include "vector.h"
#include <fstream>


int main()
{
	using VECTOR::Vector;

	std::ofstream plik;
	plik.open("Vector.txt");


	srand(time_t(0));   //inilicjacja generatora liczb pseudo-losowych
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	std::cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	while (std::cin >> target) {

		std::cout << "Podaj dlugosc kroku : ";
		if (!(std::cin >> dstep))
			break;

		while (result.magval() < target) {
			double x = step.xval();
			double y = step.yval();
			plik << steps << ": (x, y) = (" << x << ", " << y << ")" << std::endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		plik << "Po " << steps << " krokach delikwent osiagnal polozenie:\n";
		plik << result << std::endl;
		result.polar_mode();
		plik << " czyli\n" << result << std::endl;
		plik << "Srednia dlugosc kroku pozornego = "
			<< result.magval() / steps << std::endl;
		steps = 0;
		result.reset(0.0, 0.0);
		std::cout << "Podaj dystans do przejscia (k aby zakonczyc): ";
	}
	std::cout << "Koniec!\n";
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;

	plik.close();
	system("PAUSE");
	return 0;
}

