#pragma once
#include <iostream>
#include <string>


class abstr_emp {
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string &fn, const std::string &ln, const std::string &j);
	virtual void ShowAll()const;//obsluguje i wyswietla wszystkie dane
	virtual void SetAll();//prosi urzytkownika o podanie wartosci
	friend std::ostream & operator<<(std::iostream & os, const abstr_emp & ab); //wyswietla imie i nazwisko
	virtual ~abstr_emp() = 0; //virtualna klasa bazowa
};

class Employee :public abstr_emp{
public:
	Employee();
	Employee(const std::string &fn, const std::string &ln, const std::string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
};

class Manager :virtual public abstr_emp {
private:
	int chargeof; //liczba obiektow abstr_emp ktorymi zarzadza
protected:
	int inChargeof()const { return chargeof; } //wyjscie
	int & inChargeof() { return chargeof; }  //wejscie
public:
	Manager();
	Manager(const std::string &fn, const std::string &ln, const std::string &j, int ico);
	Manager(const abstr_emp & ab, int ico);
	virtual void ShowAll()const;
	virtual void SetAll();
};