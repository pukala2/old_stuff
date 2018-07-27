#include "stdafx.h"
#include "complex0.h"

Complex::Complex() {
	nat = 0.0;
	imag = 0.0;
}

Complex::Complex(double x, double i) {
	nat = x;
	imag = i;
}

Complex::~Complex() {

}

Complex operator+(const Complex & n1, const Complex & n2) {
	return Complex(n1.nat + n2.nat, n1.imag + n2.imag);
}

Complex operator-(const Complex & n1, const Complex & n2) {
	return Complex(n1.nat - n2.nat, n1.imag - n2.imag);
}

Complex operator*(const Complex & n1, const Complex & n2) {
	Complex n3;
	n3.nat = n1.nat * n2.nat - n1.imag * n2.imag;
	n3.imag = n1.nat * n2.imag + n1.imag * n2.nat;
	return n3;
}

std::ostream & operator<<(std::ostream & os, const Complex & n1) {
	os << "(" << n1.nat << "," << n1.imag << "i)\n";
	return os;
}

Complex Complex::operator*(const double n) {
	return Complex(nat*n, imag*n);
}

Complex operator*(const double n, const Complex & x) {
	return Complex(n*x.nat, n*x.imag);
}

Complex operator-(const Complex & x) {
	return Complex(x.nat, -1 * (x.imag));
}

std::istream & operator >> (std::istream & is, Complex & n1) {
	std::cout << "Skladowa rzeczywista: ";
	is >> n1.nat;
	std::cout << "Skladowa urojona: ";
	is >> n1.imag;
	return is;
}