#include "stdafx.h"
#include <cstring>
#include <iostream>
#include "golf.h"


Golf::Golf(char *fn, int hand) {
	strncpy_s(fullname, fn, Len);
	handicap = hand;
}

void Golf::Golf::showgolf()const {
	std::cout << fullname << std::endl;
	std::cout << handicap << std::endl;
}

void Golf::setgolf() {
	static int no = 0;

	std::cout << "Podaj imie: ";
	std::cin.get(fullname, Len);
	if (fullname[0] == ' ')
		no += 0;
	else
		no++;
	std::cout << "Podaj handicap :";
	std::cin >> handicap;
	std::cin.ignore();

	
}

void Golf::handlicap(int hc) {
	handicap = hc;
}