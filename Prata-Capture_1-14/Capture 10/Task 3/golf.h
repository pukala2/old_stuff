#include "stdafx.h"
#include <cstring>
#include <iostream>


class Golf {
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf(char *fn="noname",int hand=0);
	void showgolf()const;
	void setgolf();
	void handlicap(int hc);
};




