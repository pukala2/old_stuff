// zad 2 rozdzial 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>

class Person {
private:
	static const int LIMIT = 256;
	std::string lname;//imie 
	char fname[LIMIT]; //nazwisko
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const std::string & ln, const char *fn = "HejTy");
	void show()const;//wyswiwtla imie nazwisko
	void formalshow()const;//nazwisko imie
};

int main()
{
	Person one;
	Person two("Staszek");
	Person three("Jacek", "Placek");
	one.show();
	std::cout << std::endl;
	one.formalshow();
	two.formalshow();
	two.show();
	three.formalshow();
	three.show();

	system("PAUSE");
	return 0;
}

void Person::show()const {
	std::cout << fname << std::endl;
	std::cout << lname << std::endl;
}
void Person::formalshow()const {
	std::cout << lname << std::endl;
	std::cout << fname << std::endl;
}


Person::Person(const std::string & ln, const char *fn) {
	lname = ln;
	strcpy_s(fname, fn);
}