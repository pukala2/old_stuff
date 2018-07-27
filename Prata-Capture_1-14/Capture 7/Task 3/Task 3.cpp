// zad 3 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include  <iostream>

struct pudlo {
	char producent[40];
	float wysokos;
	float szerokosc;
	float dlugosc;
	float objetosc;
};

void show(pudlo x);
void obw(pudlo &x);
void load(pudlo &x);

int main()
{
	pudlo p1;
	
	load(p1);
	obw(p1);
	show(p1);

	system("PAUSE");
    return 0;
}

void show(pudlo x) {
	std::cout << "Pudlo " << x.producent << std::endl;
	std::cout << "Wysokosc=" << x.wysokos << std::endl;
	std::cout << "Szerokosc=" << x.szerokosc << std::endl;
	std::cout << "Dlugosc=" << x.dlugosc << std::endl;
	std::cout << "Objetosc=" << x.objetosc << std::endl;
}

void obw(pudlo &x) {
	x.objetosc = x.dlugosc*x.szerokosc*x.wysokos;
}

void load(pudlo &x) {
	std::cout << "Podaj nazwe producenta:";
	std::cin >> x.producent;
	std::cout << "Podaj wysokos:";
	std::cin >> x.wysokos;
	std::cout << "Podaj szerokosc:";
	std::cin >> x.szerokosc;
	std::cout << "Podaj dlugosc:";
	std::cin >> x.dlugosc;
}