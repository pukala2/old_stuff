#pragma once
#include <iostream>

class Time {
private:
	int hours;
	int minutes;
public:
	Time();//konstruktor
	Time(int h, int m);
	void AddMin(int m);
	void AddHr(int m);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time & t, const Time & z);//przeladowanie plusa
	friend Time operator-(const Time & t, const Time & z);//przeladowanie minusa
	friend Time operator*(const Time & t, double n);//przeladowanie operatora mnozenia
	friend Time operator*(double n, const Time & t);//przeladowanie operatora mnozenia
	friend Time operator*(double m, Time & t) { return t*m; }//definicja miejscowa inline
	friend std::ostream & operator<<(std::ostream & os, Time & t);
};

