#pragma once
#include <iostream>
#include <string>

class abstr_emp {
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp() :fname("brak"), lname("brak"), job("brak") {}
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j) :fname(fn), lname(ln), job(j) {}
    virtual void ShowAll()const;//obsluguje i wyswietla wszystkie dane 
    virtual void SetAll();//prosi urzytkownika o podanie wartosci 
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & ab); //wyswietla imie i nazwisko        
    virtual ~abstr_emp(){}; //virtualna klasa bazowa
    enum slasskind { Employee, Manager, Fink, Highfink };
    abstr_emp & SetIn(std::istream &is){
        is >> fname;
        is >> lname;
        is >> job;
    }
};


class Employee :public abstr_emp {
public:
    Employee() :abstr_emp() {}
    Employee(const std::string &fn, const std::string &ln, const std::string &j) :abstr_emp(fn, ln, j) {}
    virtual void ShowAll()const;
    virtual void SetAll();
    friend std::istream & operator>>(std::istream & is, Employee & e);
};


class Manager :virtual public abstr_emp {
private:
    int chargeof; //liczba obiektow abstr_emp ktorymi zarzadza 
protected:
    int inChargeof()const { return chargeof; } //wyjscie 
    int & inChargeof() { return chargeof; }  //wejscie 
public:
    Manager() :abstr_emp(), chargeof(0) {}
    Manager(const std::string &fn, const std::string &ln, const std::string &j, int ico) :abstr_emp(fn, ln, j), chargeof(ico) {}
    Manager(const abstr_emp & ab, int ico) :abstr_emp(ab), chargeof(ico) {}
    Manager(const Manager & m) :abstr_emp(m), chargeof(m.chargeof) {}
    virtual void ShowAll()const;
    virtual void SetAll();
    friend std::istream & operator>>(std::istream & is, Manager & m);

};


class Fink :virtual public abstr_emp {
private:
    std::string reportsto; //do kogo fink donosiciel przysyla raport
protected:
    const std::string ReportsTo()const { return reportsto; }
public:
    Fink() :abstr_emp(), reportsto("brak") {}
    Fink(const std::string &fn, const std::string &ln, const std::string &j, std::string rpo) :abstr_emp(fn, ln, j), reportsto(rpo) {}
    Fink(const abstr_emp & ab, std::string rpo) :abstr_emp(ab), reportsto(rpo) {}
    Fink(const Fink & fi) :abstr_emp(fi), reportsto(fi.reportsto) {}
    virtual void ShowAll()const;
    virtual void SetAll();
    friend std::istream & operator>>(std::istream & is, Fink & f);
};


class HighFink : public Manager, public Fink { //glowny donosiciel
public:
    HighFink():abstr_emp("brak", "brak", "brak"),Manager("brak", "brak", "brak",0), Fink("brak", "brak", "brak","brak"){}
    HighFink(const std::string &fn, const std::string &ln, const std::string &j, std::string rpo, int ico) :abstr_emp(fn, ln, j), 
    Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}
    HighFink(const abstr_emp & ab, std::string rpo, int ico) :abstr_emp(ab), Manager(ab, ico), Fink(ab, rpo) {}
    HighFink(const Fink & fi, int ico) :abstr_emp(fi), Manager(fi, ico), Fink(fi) {}
    HighFink(const Manager & m, const std::string & rpo) :abstr_emp(m), Manager(m), Fink(m, rpo) {}
    HighFink(const HighFink & h) :abstr_emp(h), Manager(h), Fink(h) {}
    virtual void ShowAll()const;
    virtual void SetAll();
    friend std::istream & operator>>(std::istream & is, Fink & hf);
};



