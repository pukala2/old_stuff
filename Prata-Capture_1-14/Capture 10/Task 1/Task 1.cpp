// zad 1rozdzial 10.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>


class Rachunek {
private:
	std::string name;
	int nomber;
	double saldo;
public:
	Rachunek(std::string na = "Brak", int no = 0, double sa = 0);
	void show()const;
	void add(double x);
	void pay(double x);
};


int main()
{
	Rachunek ja("Przemek", 225322245, 5000);
	ja.show();
	ja.add(3000);
	ja.show();
	ja.pay(2000);
	ja.show();
	ja.pay(7000);

	system("PAUSE");
	return 0;
}

Rachunek::Rachunek(std::string na, int no, double sa) {
	name = na;
	nomber = no;
	saldo = sa;
}

void Rachunek::show()const {
	std::cout << name << std::endl;
	std::cout << nomber << std::endl;
	std::cout << saldo << std::endl;
}

void Rachunek::add(double x) {
	saldo += x;
}

void Rachunek::pay(double x) {
	if (saldo < x)
		std::cout << "Brak Srodkow na koncie!!" << std::endl;
	else
		saldo -= x;
}
