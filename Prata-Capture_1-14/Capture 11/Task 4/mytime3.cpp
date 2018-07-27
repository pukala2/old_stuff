#include "stdafx.h"
#include "mytime3.h"

Time::Time() {
	hours = minutes = 0;
}

Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}


void Time::AddMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int m) {

	hours += m;
}

void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

Time operator+(const Time & t, const Time & z) {
	Time sum;
	sum.minutes = z.minutes + t.minutes;
	sum.hours = z.hours + t.hours;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time & t, const Time & z){
	Time diff;
	int total1, total2;
	total1 = z.minutes + (60 * t.hours); //zamiana godzin na minuty + minuty
	total2 = z.minutes + (60 * z.hours);  //zamiana godzin na minuty + minuty
	diff.minutes = (total1 - total2) % 60;
	diff.hours = (total1 - total2) / 60;
	return diff;
}

Time operator*(const Time & t, double n){
	Time result;
	long totalminutes = t.hours*n * 60 + t.minutes*n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(double n, const Time & t) {
	Time result;
	long totalminutes = t.hours*n * 60 + t.minutes*n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream & operator<<(std::ostream & os, Time & t) {
	os << t.hours << " godzin, " << t.minutes << " minut" << std::endl;
	return os;
}