#include "stdafx.h"
#include <iostream>
#include "cow.h"

//char name[20];
//char *hobby;
//double weight;

Cow::Cow() {
	strcpy_s(name,20,"brak");
	hobby = new char[1];
	hobby[0] = '\0';
	weight=0;
	std::cout << "KONSTRUKTOR DOMYSLNY\n";
}

Cow::Cow(const char *nm, const char *ho, double wt) {
	strcpy_s(name, 20, nm);
	int len = strlen(ho)+1;
	hobby = new char[len];
	strcpy_s(hobby, len, ho);
	weight = wt;
	std::cout << "KONSTRUKTOR JAWNY\n";
}

Cow::Cow(const Cow & c) {
	
	strcpy_s(name, 20, c.name);
	int len = strlen(c.hobby) + 1;
	hobby = new char[len];
	strcpy_s(hobby, len, c.hobby);
	weight = c.weight;
	std::cout << "COPY KONSTRUKTOR\n";


}

Cow::~Cow() {
	delete[] hobby;
	std::cout << "DESTRUKTOR\n";
}

Cow & Cow::operator=(const Cow & c) {
	if (this == &c)
		return *this;
	delete hobby;
	strcpy_s(name, 20, c.name);
	int len = strlen(c.hobby) + 1;
	hobby = new char[len];
	strcpy_s(hobby, len, c.hobby);
	weight = c.weight;
	std::cout << "OPERATOR ROWNANIA\n";
	return *this;
}

void Cow::ShowCow()const {
	std::cout <<"NAME"<< name << std::endl;
	std::cout << "HOBBY" << hobby << std::endl;
	std::cout << "WAGA" << weight << std::endl << std::endl;
}