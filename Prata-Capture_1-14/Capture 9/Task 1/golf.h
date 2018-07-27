#pragma once
#include <cstring>
const int Len = 40;

struct Golf {
	char fullname[Len];
	int handicap;
};

void setgolf(Golf & g, const char *name, int hc) {
	strncpy_s(g.fullname,name,Len);
	g.handicap = hc;
}

void showgolf(const Golf & g) {
	std::cout << g.fullname << std::endl;
	std::cout << g.handicap << std::endl;
}

void setgolf(Golf & g) {
	static int no= 0;

	std::cout << "Podaj imie: ";
	std::cin.get(g.fullname,Len);
	if (g.fullname[0] == ' ')
		no += 0;
	else
		no++;
	std::cout << "Podaj handicap :";
	std::cin >> g.handicap;
	std::cin.ignore();

	std::cout <<"Numer "<<no<<std::endl;
}

void handlicap(Golf & g, int hc) {
	g.handicap = hc;
}