// zad 9 rozdzial 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int SLEN = 30;
struct Student {
	char fulname[SLEN];
	char hooby[SLEN];
	int ooplevel;
};



int getinfo(Student pa[], int n);
void display1(Student pa);
void display2(const Student *pa);
void display3(const Student pa[], int n);

int main()
{
	
	std::cout << "Podaj wielkosc grupy :";
	int clas_size;
	std::cin >> clas_size;
	while (std::cin.get() != '\n')
		continue;
	Student *ptr_stu = new Student[clas_size];
	int entered = getinfo(ptr_stu, clas_size);
	
	for (int i = 0; i < entered; i++) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	std::cout << "GOTOWE\n";
	

	system("PAUSE");
    return 0;
}

int getinfo(Student pa[], int n) {
	int i = 0;
	while (i<n) {
		std::cout << "Podaj nazwe "<<i+1 <<" studenta : ";
		std::cin.get(pa[i].fulname,SLEN);
		if ((int)pa[i].fulname[0] == 0)
			break;
		std::cout << "Podaj hobby " << i + 1 << " studenta : ";
		std::cin >> pa[i].hooby;
		std::cout << "Podaj level " << i + 1 << " studenta : ";
		std::cin >> pa[i].ooplevel;
		i++;
		std::cin.ignore();
	}
	if (i == 0)
		std::cout << "Brak elementow w liscie!!!\n";
	
	return i;
}

void display1(Student pa) {
	std::cout << "\nTU DISPLAY1\n\n";
	
		std::cout << pa.fulname << std::endl;
		std::cout << pa.hooby << std::endl;
		std::cout << pa.ooplevel<< std::endl;
		
}
		
	
void display2(const Student *pa) {
	std::cout << "\nTU DISPLAY2\n\n";
	
		std::cout << pa->fulname << std::endl;
		std::cout << pa->hooby << std::endl;
		std::cout << pa->ooplevel << std::endl;
}

void display3(const Student pa[], int n) {
	std::cout << "\nTU DISPLAY3\n\n";
	for (int i = 0; i < n; i++) {
		std::cout << pa[i].fulname << std::endl;
		std::cout << pa[i].hooby << std::endl;
		std::cout << pa[i].ooplevel << std::endl;
	}
}