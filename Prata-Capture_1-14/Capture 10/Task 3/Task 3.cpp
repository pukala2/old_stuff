// zad 3 rozdzial 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "golf.h"
#include <cstring>
#include <iostream>


int main()
{
	Golf g[4];

	for (int i = 0; i<3; i++)
		g[i].setgolf();
	g[0].handlicap(4);
	for (int i = 0; i<4; i++)
		g[i].showgolf();

	
	system("PAUSE");
    return 0;
}

