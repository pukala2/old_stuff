#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

int suma(int *n, int *k)
{
	return *n + *k;
}

int main()
{
	array<int, 5> tab; //zad 3
	tab[0] = 1;
	tab[1] = 2;
	tab.at(2) = 3;
	tab.at(3) = 4;
	tab[4] = 5;
///////////////////////////////////////////////////////////////

	int *x = &tab[0];//zad 4
	int *y = &tab[4];

	int even;

	even=suma(x, y);

	cout << even<<endl;
/////////////////////////////////////////////////////////////////

	array<float, 2> ideas;//zad 5
	ideas.at(1) = 3;

	cout << ideas.at(1) << endl;
/////////////////////////////////////////////////////////////////////

	char jedzenie[] = "cheasburger"; //zad 6
	cout << jedzenie << endl;
//////////////////////////////////////////////////////////////////////

	string kupa = "Waldorf Salad"; //zad 7

 //////////////////////////////////////////////////////////////////////

	struct ryba  //zad 8
	{
		string rodzaj;
		int waga;
		float dlugosc;
	};
//////////////////////////////////////////////////////////////////////

	ryba *r = new ryba;  //zad 9

	r->rodzaj = "losos";
	r->waga = 5;
	r->dlugosc = 15.5;

	cout << endl << endl << "zad 8" << endl;
	cout << "Rodzaj:"<<r->rodzaj << ", waga:" << r->waga << ", dlugpsc: " << r->dlugosc<<endl;
//////////////////////////////////////////////////////////////////////////////////////////////////

	enum odpowiedz

	system("PAUSE");
    return 0;
}

