// zad 2 rozdzial 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>   //prototypy funkcji rand() i srand()
#include <time.h>    //prototyp funkcji time
#include "vect.h"



int main()
{
	using VECTOR::Vector;


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

		while (result.set_mag() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		std::cout << "Po " << steps << " krokach delikwent osiagnal polozenie:\n";
		std::cout << result << std::endl;
		result.polar_mode();
		std::cout << " czyli\n" << result << std::endl;
		std::cout << "Srednia dlugosc kroku pozornego = "
			<< result.set_mag() / steps << std::endl;
		steps = 0;
		result.reset(0.0, 0.0);
		std::cout << "Podaj dystans do przejscia (k aby zakonczyc): ";
	}
	std::cout << "Koniec!\n";
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;

	
	system("PAUSE");
	return 0;
}

