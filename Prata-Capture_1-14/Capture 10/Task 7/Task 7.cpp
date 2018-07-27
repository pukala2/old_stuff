// Zad 7 rzodzial 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Plorg {
private:
	std::string imie;
	int sytosc;
public:
	Plorg(std::string n = "Plorga", int s = 50);
	void show()const;
};

int main()
{
	Plorg x1;
	x1.show();
	system("PAUSE");
}

Plorg::Plorg(std::string n, int s) {
	imie = n;
	sytosc = s;
}

void Plorg::show()const {
	std::cout << imie << std::endl;
	std::cout << sytosc << std::endl;
}
