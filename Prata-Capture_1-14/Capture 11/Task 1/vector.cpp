#include "stdafx.h"
#include "vector.h" //wlacza plik naglowkowy <iostream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
	//przelicznik radianow na stopnie
	const double Rad_to_deg = 45.0 / atan(1.0);
	//powinno wyjsc okolo 57,2957795130823
	//metody prywatne
	//obliczenia dlugosci wektora ze skladowych x i y
	void Vector::set_mag() {
		mag = sqrt(x*x + y*y);//pitagoras
	}

	void Vector::set_ang() {
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(x, y);
	}

	//oblicza skladowa x ze wspolrzednych biegunowych
	void Vector::set_x() {
		x = mag*cos(ang);
	}

	//oblicza skladowa y ze wspolrzednych biegunowych
	void Vector::set_y() {
		y = mag*sin(ang);
	}

	//metody publiczne
	Vector::Vector() {
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	//konstruuje wektor o zadanych wspolrzednych biegunowych (w trybie 'p')
	//badz prostokatach (w domyslnym trybie 'r')
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else {
			cout << "Niepoprawna wartosc trzeciego argumentu Vector() --";
			cout << "zeruje wektor\n";
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}

	//zerowanie wartosci wektora dla zadanych wspolrzednych kartezjanskich (dla RECT)
	//albo dla zadanych wspolrzednych biegunowych (POL)	
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (form = RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form = POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Niepoprawny trzeci argument set() --";
			cout << "zeruje wektor\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector() {//destruktor
	}

	void Vector::polar_mode() { //przelacza do reprezentacji biegunowej
		mode = POL;
	}

	void Vector::rect_mode() { //przelacza do reprezentacji kartezjanskiej
		mode = RECT;
	}

	//przeciazone operatory
	//dodawanie dwoch wektorow
	Vector Vector::operator+(const Vector & b)const {
		return Vector(x + b.x, y + b.y);
	}

	//odejmowanie wektora b od wektora a
	Vector Vector::operator-(const Vector & b)const {
		return Vector(x - b.x, y - b.y);
	}

	//zmienia znak wektora
	Vector Vector::operator-()const {
		return Vector(-x, -y);
	}

	//mnozy wektor wywolujacy przez n
	Vector Vector::operator*(double n)const {
		return Vector(n * x, n * y);
	}

	//funkcje zaprzyjaznione 
	//mnozy wektor n przez wektor a
	Vector operator*(double n, const Vector & a) {
		return Vector(a * n);
	}

	//wyswietla wspolrzedne wektora (prostokatne w trybie RECT,
	//biegunowe w trybie POL)
	std::ostream & operator<<(std::ostream & os, const Vector & v) {
		if (v.mode == Vector::RECT) {
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::POL) {
			os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		}
		else {
			os << "Niepoprawny tryb reprezentacji obiektu wektora";
		}

		return os;
	}

	Vector::operator double() {
		return mag;
	}
}//koniec przestrzeni nazw VECTOR