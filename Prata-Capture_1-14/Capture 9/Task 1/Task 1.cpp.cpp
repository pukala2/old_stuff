// zad 1 rozdzial 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "golf.h"

void setgolf(Golf & g, const char *name, int hc);
//funkcja ustawia nazwisko i handicap na podstawie 
//argumentow wywolania

void setgolf(Golf & g);
//funkcja pobiera dane od urzytkownika
//gdzie ustawia odpowiednie wartosci struktury
//zwraca 1 jezeli udalo sie wpisac dane

void handlicap(Golf & g, int hc);
//ustawia handlicap gracza

void showgolf(const Golf & g);
//pokazuje zawartosc pol struktury

int main()
{
	Golf g[4];
	
	for(int i=0;i<3;i++)
	setgolf(g[i]);
	setgolf(g[3], "Kalinka", 22);
	handlicap(g[0], 33);
	for(int i=0;i<4;i++)
	showgolf(g[i]);

	
	

	system("PAUSE");
    return 0;
}

