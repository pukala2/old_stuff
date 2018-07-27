// zad 8 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <string>


const int Seasons = 4;
const char* Snames[Seasons] = { "Wiosna","Lato","Jesien","Zima" };

struct Wydatki {
	double extens[Seasons];
};

void fill(Wydatki *p, int Seasons);
void show(Wydatki *p, int Seasons);

int main()
{


	Wydatki *expense=new Wydatki;
	fill(expense,Seasons);
	show(expense,Seasons);

	system("PAUSE");
    return 0;
}


void show(Wydatki *p, int Seasons) {
	double total = 0;
	std::cout << "n\Wydatki" << std::endl;
		for (int i = 0; i < Seasons; i++) {
			std::cout << Snames[i] << ": " << p->extens[i] << " zl" << std::endl;
			total += p->extens[i];
		}
		std::cout<<"Laczne wydatki to :" << total << std::endl;
}

void fill(Wydatki *p,const int Seasons){
	for (int i = 0; i < Seasons; i++) {
		std::cout << "Podaj wydatki >>" << Snames[i] << "<< : ";
		std::cin >> p->extens[i];
	}
	
}