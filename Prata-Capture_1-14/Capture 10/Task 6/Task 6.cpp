// zad 6 rozdzial 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Move.h"


int main()
{
	Move ob1(3, 4);
	std::cout << "Ojeckt 1\n";
	ob1.showmove();
	std::cout << "Ojeckt 2\n";
	Move ob2(2, 2);
	ob2.showmove();
	Move sum = ob1.add(ob2);
	std::cout << "Ojeckt 3\n";
	sum.showmove();
	sum.reset();
	std::cout << "Po resecie\n";
	sum.showmove();
	system("PAUSE");
}



