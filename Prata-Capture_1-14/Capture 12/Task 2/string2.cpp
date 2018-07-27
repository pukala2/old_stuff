#include "stdafx.h"
#include "String2.h"
#include <string.h>
#include <cctype>

//inicjalizacja statycznej skladowej klasy
int StringBad::num_strings = 0;

//metoda statyczna
int StringBad::HowMany() {
	return num_strings;
}

//metody klasy
//konstruuje obiekt StringBad na bazie ciagu jezyka C
StringBad::StringBad(const char *s) {
	len = std::strlen(s);    //ustalanie rozmiaru
	str = new char[len + 1];  //przydzial odpowiedniej ilosci pamieci
	strcpy_s(str, len + 1, s);      //inicjalizacja wskaznika
	num_strings++;            //uaktualnienie licznika
	//std::cout << num_strings << ": \"" << str << "\"-obiekt utworzony.\n";  //komunikat diagnostyczny utworzony
}

StringBad::StringBad() {
	len = 4;
	str = new char[4];
	strcpy_s(str, 4, "C++");
	num_strings++;
	//std::cout << num_strings << ": \"" << str << "\"-obiekt domyslny utworzony.\n";  //komunikat diagnostyczny utworzony
}


StringBad::~StringBad() {
	--num_strings;
	delete[]str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st) {
	os << st.str;
	return os;
}

StringBad::StringBad(const StringBad & st) {
	num_strings++;  //alokacja licznika obiektow
	len = st.len;   //ciag obiektu ma te sama dlugosc
	str = new char[len + 1]; //przydzial stosownej ilosci pamieci
	strcpy_s(str, len + 1, st.str);
	//std::cout << num_strings << ": \"" << str << "\"-obiekt utworzony.\n";  //komunikat diagnostyczny utworzony
}

StringBad & StringBad::operator=(const StringBad & st) {
	if (this == &st) //kontrola autoprzypisania
		return *this; //nic nie trzeba robic
	delete[]str;  //zwolenieni poprzedniego wskazywanego ciagu
	len = st.len;  //ciag obiektu ma ta sama dlugosc
	str = new char[len + 1];  //przydzial stosownej ilosci pamieci
	strcpy_s(str, len + 1, st.str); //kopiowanie ciagu do nowo przydzielonej pamieci
	return *this;  //zwrocenie L obiektu
}

char & StringBad::operator[](int i) {
	return str[i];
}

const char & StringBad::operator[](int i)const {
	return str[i];
}

StringBad & StringBad::operator=(const char *s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

//wczytanie ciagu z wejscia
std::istream & operator >> (std::istream & is, StringBad & st) {
	char temp[StringBad::CINLIM];
	is.get(temp, StringBad::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

bool operator<(const StringBad & st, const StringBad & st2) {
	return (std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const StringBad & st, const StringBad & st2) {
	return st2 < st;
}

bool operator==(const StringBad & st, const StringBad & st2) {
	return (std::strcmp(st.str, st2.str) == 0);
}

StringBad StringBad::operator+(const StringBad & st2) {
	int SIZE = this->len + st2.len + 1;
	char *tmp = new char[SIZE];
	strcpy(tmp, this->str);
	strcpy(tmp + this->len ,st2.str);
	
	return StringBad(tmp);
	delete[] tmp;

}

StringBad operator+(const char *ch, StringBad st1) {
	int SIZE = std::strlen(ch) + st1.len + 1;
	char *tmp = new char[SIZE];
	strcpy(tmp, ch);
	strcpy(tmp + std::strlen(ch), st1.str);
	return StringBad(tmp);
	delete[] tmp;
}

StringBad & StringBad::StringLOW(){
	
	int i = 0;
	while (this->str[i])
	{
			this->str[i]=tolower(this->str[i]);
			i++;
	}
	return *this;
}

StringBad & StringBad::StringUP() {
	int i = 0;
	while (this->str[i])
	{
		this->str[i] = towupper(this->str[i]);
		i++;
	}
	return *this;
}

int & StringBad::Howchar(const char  ch) {
	int i = 0;
	int count = 0;
	while (this->str[i])
	{
		if (this->str[i] == ch)
			count++;
		i++;
	}
	return count;
}