// zad 4 rozdzial 11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "mytime3.h"


int main()
{
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	std::cout << "Aida i Tosca:\n";
	std::cout << aida << "" << tosca << std::endl;
	temp = aida + tosca;
	std::cout << "Aida + Tosca : ";
	std::cout << temp;
	temp = aida*1.17;
	std::cout << "Aida * 1.17 : ";
	std::cout << temp;
	std::cout << "10 * Tosca : " << 10.0*tosca << std::endl;
	temp = aida - tosca;
	std::cout << temp;
	temp = aida * 5;
	std::cout << temp;
	temp =5 * aida;
	std::cout << temp;

	system("PAUSE");
	return 0;
}

