#include "stdafx.h"
#include "stonewt.h"
#include <iostream>

Stonewt::Stonewt(double lbs) {
	mode = POUNDS;
	stone = int(lbs) / lbs_per_stn; // dzielenie calkowite
	pds_left = int(lbs) % lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

//konstruuje obiekt Stonewt  z liczby kamieni i funtow
Stonewt::Stonewt(int stn, double lbs) {
	mode = STONE;
	stone = stn;
	pds_left = lbs;
	pounds = stn * lbs_per_stn + lbs;
}

Stonewt::Stonewt() {
	stone = 0;
	pounds = pds_left = 0;
	mode = STONE;
}

Stonewt::~Stonewt() {
}

//funkcje konwersji
Stonewt::operator int()const {
	return int(pounds + 0.5);
}

Stonewt::operator double()const {
	return pounds;
}

Stonewt operator*(const Stonewt & st, const double x) {
	return Stonewt(st.pounds*x);
}

Stonewt operator*(double x, const Stonewt & st) {
	return Stonewt(st.pounds*x);
}

Stonewt operator+(const Stonewt & st1, const Stonewt & st2) {
	return Stonewt(st1.pounds + st2.pounds);
}

Stonewt operator-(const Stonewt & st1, const Stonewt & st2) {
	return Stonewt(st1.pounds - st2.pounds);
}

Stonewt operator/(const Stonewt & st1, const Stonewt & st2) {
	return Stonewt(st1.pounds / st2.pounds);
}

Stonewt operator*(const Stonewt & st1, const Stonewt & st2) {
	return Stonewt(st1.pounds*st2.pounds);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & v) {

	if (v.mode == v.STONE)
		os << v.stone << " kamieni, " << v.pds_left << " funtow\n";

	if (v.mode == v.POUNDS)
		os << v.pounds << " funtow\n";
	return os;
}

// OPERATORY RELACJI

bool operator<(const Stonewt & st1, const Stonewt & st2) {
	if (st1.pounds < st2.pounds)
		return true;

	else
		return false;	
}

bool operator<=(const Stonewt & st1, const Stonewt & st2) {
	if (st1.pounds <= st2.pounds)
		return true;

	else
		return false;
}

bool operator>(const Stonewt & st1, const Stonewt & st2) {
	if (st1.pounds > st2.pounds)
		return true;

	else
		return false;
}

bool operator>=(const Stonewt & st1, const Stonewt & st2) {
	if (st1.pounds >= st2.pounds)
		return true;

	else
		return false;
}

bool operator==(const Stonewt & st1, const Stonewt & st2) {
	if (st1.pounds == st2.pounds)
		return true;
	else
		return false;
}

bool operator!=(const Stonewt & st1, const Stonewt & st2) {
	if (st1.pounds != st2.pounds)
		return true;
	else
		return false;
}