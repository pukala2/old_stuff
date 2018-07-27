#include "stdafx.h"
#include "disk.h"
#include <iostream>
void Bravo(const Cd & disk) {
	disk.report();
}

//public metods base class
Cd::Cd(const char *per, const char *lab, int sel, double pt) {
	strcpy(performers, per);
	strcpy(laber, lab);
	selections = sel;
	playtime = pt;
}

Cd::Cd(const Cd & cd) {
	strcpy(performers, cd.performers);
	strcpy(laber, cd.laber);
	selections = cd.selections;
	playtime = cd.playtime;
}

Cd::~Cd() {}

void Cd::report()const {
	std::cout << "\nPerformer :" << performers << std::endl;
	std::cout << "Laber :" << laber << std::endl;
	std::cout << "Selection :" << selections << std::endl;
	std::cout << "Play Time :" << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & cd) {
	if (&cd == this)
		return *this;
	strcpy(performers, cd.performers);
	strcpy(laber, cd.laber);
	selections = cd.selections;
	playtime = cd.playtime;
	return *this;
}

//public metods derived class

Classic::Classic(const char *m, const char *per,
	const char *lab, int sel, double pt) :Cd(per, lab, sel, pt) {
	strcpy(maintrack, m);
}

void Classic::report()const {
	Cd::report();
	std::cout << "Main track :" << maintrack << std::endl;
}