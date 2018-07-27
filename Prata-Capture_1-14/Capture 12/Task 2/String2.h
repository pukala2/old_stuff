#pragma once
#include <iostream>

class StringBad {
private:
	char *str;  //wskaznik ciagu
	int len;  //dlugosc ciagu
	static int num_strings; //liczba obiektow
	static const int CINLIM = 80; //limit dlugosci ciagu na wejsciu
public:
	StringBad(const char *s);  //konstruktor
	StringBad(); //konstruktor domyslny
	StringBad(const StringBad & st); //konstruktor kopiujacy
	~StringBad();  //destruktor
	int length()const { return len; } //metoda zwracajaca dlugosc

									  //metody przeciazajace operatory
	StringBad & operator=(const StringBad & s);  //przeciazenie operatora = moze byc tylko wykonane w metodzie
	StringBad & operator=(const char *s);//metoda umozliwia przypisania ciagu znakow , wyeliminowalo to koniecznosc tworzenia
	char & operator[](int i);  //metoda zwracajaca wskazany przez nas zkak ciagu
	const char & operator[](int i)const; //metoda na rzecz obiektow const
	StringBad operator+(const StringBad & st2); //metoda pozwalajaca dodawac ciagi znakow

	StringBad & StringUP(); //konwertuje male litery na duze
	StringBad & StringLOW(); //konwertuje duze litery na male
	int & Howchar(const char ch); //zwraca wystapienie litery w ciagu

    //funkcje zaprzyjaznione przeciazajace operatory
	friend StringBad operator+(const char *ch,StringBad st1); //metoda pozwalajaca dodawac ciagi znakow
	friend bool operator<(const StringBad & st, const StringBad & st2);
	friend bool operator>(const StringBad & st, const StringBad & st2);
	friend bool operator==(const StringBad & st, const StringBad & st2);
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
	friend std::istream & operator >> (std::istream & is, StringBad & st);

	//metota statyczna
	static int HowMany();
};
