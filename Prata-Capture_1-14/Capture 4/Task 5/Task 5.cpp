#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>


using namespace std;

float policz_srednia(float x,float y,float z)
{
	int suma;
	suma = x + y + z;

	return suma / 3;
}

int main()
{
	float wynik;
	array<float, 3> czas;

	cout << "Podaj 3 czasy biegu:"; cin >> czas[0] >> czas[1] >> czas[2];
	wynik = policz_srednia(czas[0],czas[1],czas[2]);

	cout << endl << wynik;

	system("PAUSE");
	return 0;
}