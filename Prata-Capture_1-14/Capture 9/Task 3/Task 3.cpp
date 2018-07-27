// zad 3 rozdzial 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <new>

struct chaff {
	char dross[20];
	int slag;
};

void add(chaff &x,const char*txt, int val);
void show(const chaff &x);

char buffor[200];
const int LEN = 3;

int main()
{
	
	chaff *arr= new (buffor) chaff [LEN];
	
	add(arr[0], "Przemek", 4);
	add(arr[1], "Roksana", 6);
	add(arr[2], "Zyszek", 3);
	
	for(int i=0;i<LEN;i++)
	show(arr[i]);
	
	chaff *arr_next = new chaff[LEN];

	add(arr_next[0], "Grzesiek", 8);
	add(arr_next[1], "Franek", 9);
	add(arr_next[2], "Jacek", 10);

	for (int i = 0; i<LEN; i++)
		show(arr_next[i]);

	system("PAUSE");
    return 0;
}

void add(chaff &x, const char*txt, int val) {
	
	strcpy_s(x.dross, txt);
	x.slag = val;
}

void show(const chaff &x) {
	std::cout << x.dross << std::endl;
	std::cout << x.slag << std::endl;
}