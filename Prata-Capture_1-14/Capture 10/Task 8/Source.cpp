#include "stdafx.h"
#include <iostream>
#include "header.h"
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

bool Stack::push(Object & item) {
	std::cout << "Podaj imie : ";
	std::cin >> item.fullname;
	std::cout << "Podaj wartosc : ";
	std::cin >> item.age;
	if (top < MAX) {
		arr[top++] = item;

	}
	else
		return false;
}

bool Stack::pop(Object & item) {
	if (top > 0) {
		item = arr[--top];
		return true;
	}
	else return false;
}

void Stack::show() {
	for (int i = 0; i < top; i++) {
		std::cout << "Obiekt "<<i+1<<". " << arr[i].fullname;
		std::cout << "   " << arr[i].age << std::endl;
	}
}

void Client::menu() {
	std::cout << "1.Dodanie obiektu" << std::endl;
	std::cout << "2.Skasowanie obiektu" << std::endl;
	std::cout << "3.Pokazanie elementow" << std::endl;
	std::cout << "4.Edycja elementu" << std::endl;
	std::cout << "5.Wyjscie" << std::endl;
}


void Client::funkcja(Object & stru)
{
	std::cout << "Podaj nowa nazwe : ";
	std::cin >> stru.fullname;
	std::cout << "Podaj nowa wartosc : " << std::endl;
	std::cin >> stru.age;
}


void Stack::visit(void(*ptr)(Object & str)) {
	
	int n;
	std::cout << "Podaj nr elementu : ";
	std::cin >> n;
	ptr(arr[n-1]);		
}
