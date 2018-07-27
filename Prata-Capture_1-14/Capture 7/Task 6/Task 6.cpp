// zad 6 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void fill_array(double *ar, int s);
void show_array(double *ar);
void reverse_array(double *ar);

static int no = 0;

int main()
{
	double arr[5];
	fill_array(arr, 5);
	reverse_array(arr);
	show_array(arr);
	

	system("PAUSE");
    return 0;
}


void show_array(double *ar) {
	std::cout << std::endl;
	std::cout <<"----====ZAWARTOSC NASZEJ TABLICY====----:" <<std::endl;
	std::cout << std::endl;

	
		for (int i = 0; i<no; i++)
			std::cout << "Zawartosc " << i+1 << " tablicy :" << ar[i] << std::endl;
	
		std::cout << "Zawartosc " << no+1 << " tablicy :" << ar[no] << std::endl;

}

void fill_array(double *ar, int s) {
	std::cout << "Podaj 1 wartosc:";
	while (std::cin >> *ar && no < s-1) {
		std::cout << "Podaj " << no + 2 << " wartosc:";
		ar++;
		no++;
	}
	if (no <= s-1)
		no--;
}

void reverse_array(double *ar) {
	int i = 0;
	int j = no;
	while(i<j){
		double tmp;
		tmp = ar[i];
		ar[i] = ar[j];
		ar[j] = tmp;
		i++;
		j--;
	}
}