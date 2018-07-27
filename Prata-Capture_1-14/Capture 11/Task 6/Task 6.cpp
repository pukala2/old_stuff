// zad 6 rozdzial 11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "stonewt.h"


int main()
{

	Stonewt big(11,0);
	
	Stonewt arr[6];
	arr[3] = Stonewt(33);
	arr[4] = Stonewt(154);
	arr[5] = Stonewt(66);
	
	for (int i = 0; i < 3; i++) {
		double val;
		std::cout << "Podaj wartosc " << i + 1<<" : " << std::endl;
		std::cin >> val;
		arr[i] = val;
	}
	
	Stonewt max=arr[0];
	Stonewt min=arr[0];

	for (int i = 1; i < 6; i++) {
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	for (int i = 0; i < 6; i++) {
		if (arr[i] >= big)
			std::cout << arr[i];
	}
	
	std::cout << "Najwieksza wartosc to = " << max;
	std::cout << "Najmniejsza wartosc to = " << min;

	system("PAUSE");
	return 0;
}