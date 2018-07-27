#include "stdafx.h"
#include <iostream>
#include "customer.h"
#include <cstringt.h>

using namespace Client;

Stack::Stack() {
	top = 0;
}

bool Stack::isempty()const {
	return top == 0;
}

bool Stack::isfull()const {
	return top == MAX;
}

bool Stack::push(Customer & item) {
	std::cout << "Podaj imie : ";
	std::cin >> item.fullname;
	std::cout << "Podaj wartosc : ";
	std::cin >> item.payment;
	if (top < MAX) {
		arr[top++] = item;

	}
	else
		return false;
}

bool Stack::pop(Customer & item) {
	if (top > 0) {
		general += item.payment;
		item = arr[--top];
		return true;
	}
	else return false;
}

void Stack::show() {
	for (int i = 0; i < top; i++) {
		std::cout <<"Obiekt "<<arr[i].fullname;
		std::cout << "   " << arr[i].payment << std::endl;
	}
	std::cout << "Dlug wynosi = "<<general << std::endl;
}

void Client::menu() {
	std::cout << "1.Dodanie obiektu" << std::endl;
	std::cout << "2.Skasowanie obiektu" << std::endl;
	std::cout << "3.Pokazanie elementow" << std::endl;
	std::cout << "4.Wyjscie" << std::endl;
}