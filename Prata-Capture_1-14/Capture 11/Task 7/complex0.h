#pragma once
#include "stdafx.h"
#include <iostream>



class Complex {
private:
	double nat;
	double imag;
public:
	Complex();  //konstruktor domyslny
	Complex(double x, double i);
	~Complex(); //destruktor
	friend Complex operator+(const Complex & n1, const Complex & n2);
	friend Complex operator-(const Complex & n1, const Complex & n2);
	friend Complex operator*(const Complex & n1, const Complex & n2);
	Complex operator*(const double n);
	friend Complex operator*(const double n, const Complex & x);
	friend Complex operator-(const Complex & x);
	friend std::ostream & operator<<(std::ostream & os, const Complex & n1);
	friend std::istream & operator >> (std::istream & is, Complex & n1);
};