#pragma once
#include "stdafx.h"
#include <string>
#include <string.h>


//base class
class Cd { //represents CD
private:
	char performers[50];
	char laber[20];
	int selections; // number of songs
	double playtime; // length of the CD
public:
	Cd(const char *per = "Brak", const char *lab = "Brak", int sel = 0, double pt = 0.0);
	Cd(const Cd & cd); //copy constructor
	~Cd(); //destructor
	virtual void report()const; // shows information about all data
	Cd & operator=(const Cd & cd);
};

//class Derived
class Classic : public Cd {
private:
	char maintrack[100];
public:
	Classic(const char *m = "Brak", const char *per = "Brak",
		const char *lab = "Brak", int sel = 0, double pt = 0.0);
	virtual void report()const; // shows information about all data
};

void Bravo(const Cd & disk);