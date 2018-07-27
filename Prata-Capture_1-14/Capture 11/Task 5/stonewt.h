#pragma once
#include <iostream>

class Stonewt {
public:
	enum Mode { STONE, POUNDS };
private:
	enum { lbs_per_stn = 14 };  //liczba funtow na kamien
	Mode mode; //skladowa sterujaca
	int stone;  //masaw calych kamieniach 
	double pds_left;  //reszta w funtach
	double pounds;  //masa w funtach
public:
	Stonewt(double lbs); //konstruktor dla funtow
	Stonewt(int stn, double lbs);  //konstruktor dla kamieni i funtow
	Stonewt();  //konstruktor domyslny
	~Stonewt();  //destruktor
	friend Stonewt operator*(const Stonewt & st, const double x);
	friend Stonewt operator*(double x, const Stonewt & st);
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & v);
	operator double()const;
	operator int()const;
	friend Stonewt operator*(const Stonewt & st1, const Stonewt & st2);
	friend Stonewt operator+(const Stonewt & st1, const Stonewt & st2);
	friend Stonewt operator-(const Stonewt & st1, const Stonewt & st2);
	friend Stonewt operator/(const Stonewt & st1, const Stonewt & st2);

	
};
