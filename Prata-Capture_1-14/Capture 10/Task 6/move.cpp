#include "stdafx.h"
#include <iostream>
#include <string>
#include "Move.h"

Move Move::add(const Move &m)const {
	Move tmp;
	tmp.x = m.x + this->x;
	tmp.y = m.y + this->y;
	return tmp;
}

Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}

void Move::showmove()const {
	std::cout << "x = " << x << "  ";
	std::cout << "y = " << y << std::endl;
}