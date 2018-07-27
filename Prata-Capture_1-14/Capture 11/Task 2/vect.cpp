#include "stdafx.h"
#include "vect.h" //wlacza plik naglowkowy <iostream>

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
	double Vector::set_mag() {
		return sqrt(x*x + y*y);//pitagoras
	}

	double Vector::set_ang() {
		if (x == 0.0 && y == 0.0)
			return 0.0;
		else
			return atan2(x, y);
	}

	//oblicza skladowa x ze wspolrzednych biegunowych
	void Vector::set_x() {
		x = set_mag()*cos(set_ang());
	}

	//oblicza skladowa y ze wspolrzednych biegunowych
	void Vector::set_y() {
		y = set_mag()*sin(set_ang());
	}

	void Vector::set_x(double n1, double n2) {
		x = n1*sin(n2);
	}

	void Vector::set_y(double n1, double n2) {
		y = n1*sin(n2);
	}

	//metody publiczne
	Vector::Vector() {
		x = y =  0.0;
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
			set_x(n1,n2);
			set_y(n1,n2);
		}
		else {
			cout << "Niepoprawna wartosc trzeciego argumentu Vector() --";
			cout << "zeruje wektor\n";
			x = y = 0;
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
			double tmp = n2 / Rad_to_deg;
			set_x(n1,tmp);
			set_y(n1,tmp);
		}
		else {
			cout << "Niepoprawny trzeci argument set() --";
			cout << "zeruje wektor\n";
			x = y = 0.0;
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
		
		Vector tmp = v;
		
		if (tmp.mode == Vector::RECT) {
			os << "(x,y) = (" << tmp.x << ", " << v.y << ")";
		}
		else if (tmp.mode == Vector::POL) {
			os << "(m,a) = (" << tmp.set_mag() << ", " << tmp.set_ang() * Rad_to_deg << ")";
		}
		else {
			os << "Niepoprawny tryb reprezentacji obiektu wektora";
		}

		return os;
	}

	Vector::operator double() {
		return set_mag();
	}
}//koniec przestrzeni nazw VECTOR