#include "stdafx.h"
#include "disc.h"
#include <iostream>


Cd::Cd(const char *per, const char *lab, int sel, double pt) {
	
	performers = new char[strlen(per) + 1];
	strcpy_s(performers, strlen(per) + 1, per);
    laber = new char[strlen(lab) + 1];
	strcpy_s(laber, strlen(lab) + 1,lab);
	selections = sel;
	playtime = pt;
	std::cout << "Base construcotr is work.\n";
}

Cd::Cd(const Cd & cd) {
	performers = new char[strlen(cd.performers) + 1];
	strcpy_s(performers, strlen(cd.performers) + 1, cd.performers);
	laber = new char[strlen(cd.laber) + 1];
	strcpy_s(laber, strlen(cd.laber) + 1, cd.laber);
	selections = cd.selections;
	playtime = cd.playtime;
	std::cout << "Base copy construcotr is work.\n";
}

Cd::~Cd() {
	std::cout << "Base destructor is work.\n";
	delete[] performers;
	delete[] laber;
}

void Cd::report()const {
	std::cout << "\nPerformer :" << performers << std::endl;
	std::cout << "Laber :" << laber << std::endl;
	std::cout << "Selection :" << selections << std::endl;
	std::cout << "Play Time :" << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & cd) {
	if (this == &cd)
		return *this;
	std::cout << "Base Operator = is work.\n";
	delete [] performers;
	delete [] laber;
	performers = new char[strlen(cd.performers) + 1];
	strcpy_s(performers, strlen(cd.performers) + 1, cd.performers);
	laber = new char[strlen(cd.laber) + 1];
	strcpy_s(laber, strlen(cd.laber) + 1, cd.laber);
	selections = cd.selections;
	playtime = cd.playtime;
	return *this;
}

//metods derivet class

Classic::Classic(const char *m, const char *per,
	const char *lab, int sel, double pt):Cd(per,lab,sel,pt){
	maintrack = new char[strlen(m) + 1];
	strcpy_s(maintrack, strlen(m) + 1, m);
	std::cout << "Derivet construcotr is work.\n";
}

Classic::Classic(const Classic & cd):Cd(cd) {
	maintrack = new char[strlen(cd.maintrack) + 1];
	strcpy_s(maintrack, strlen(cd.maintrack) + 1, cd.maintrack);
	std::cout << "Derivet copy construcotr is work.\n";
}

 Classic::~Classic() {
	 std::cout << "Derivet destructor is work.\n";
	 delete[] maintrack;
}

 void Classic::report()const {
	 Cd::report();
	 std::cout << "Main track :" << maintrack << std::endl;
}

 Classic & Classic::operator=(const Classic & cd) {
	 if (this == &cd)
		 return *this;
	 Cd::operator=(cd);
	 delete[] maintrack;

	 maintrack = new char[strlen(cd.maintrack)+1];
	 strcpy_s(maintrack, strlen(cd.maintrack)+1, cd.maintrack);
	 std::cout << "Devert Operator = is work.\n";
	 return *this;
 }

 void Bravo(const Cd & disk) {
	 disk.report();
 }