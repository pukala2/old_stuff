#include "ab.h"
#include <iostream>

//metods class abst_em
void abstr_emp::ShowAll()const {
    std::cout << "imie :" << fname << std::endl;
    std::cout << "nazwisko :" << lname << std::endl;
    std::cout << "Praca :" << job << std::endl;
}

void abstr_emp::SetAll() {
    std::cout << "Podaj imie :";
    std::cin >> fname;
    std::cout << "Podaj nazwisko :";
    std::cin >> lname;
    std::cout << "Podaj prace :";
    std::cin >> job;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & ab) {
    os << "imie :" << ab.fname << "\n";
    os << "nazwisko :" << ab.lname << "\n";
    return os;                                    
}
//metods class Employe
void Employee::ShowAll()const {
    abstr_emp::ShowAll();
}

void Employee::SetAll() {
    abstr_emp::SetAll();
}

//metods class manager
void Manager::ShowAll()const {
    abstr_emp::ShowAll();
    std::cout << "Liczba osob do zarzadzania:" << chargeof << "\n";
}

void Manager::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Podaj liczbe osob do zarzadzania:";
    std::cin >> chargeof;
}

//metods class Fink
void Fink::ShowAll()const {
    abstr_emp::ShowAll();
    std::cout << "Przysyla raport do:" << reportsto << "\n";
}

void Fink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Do kogo przysyla raport:";
    std::cin >> reportsto;
}

//metods HighFinker
void HighFink::ShowAll()const {
    Manager::ShowAll();
    std::cout << "Przysyla raport do:" << Fink::ReportsTo() << std::endl;
}

void HighFink::SetAll() {
    Fink::SetAll();
    std::cout << "Podaj liczbe osob do zarzadzania:";
    std::cin >> inChargeof();
}

//operators overloading

 std::istream & operator>>(std::istream & is, Employee & e){
    abstr_emp::
    return is;
 }
/*
 std::istream & operator>>(std::istream & is, Manager & m){
    is >> m.fname;
    is >> m.lname;
    is >> m.job

    is >> m.chargeof;
    return is;
 }

 std::istream & operator>>(std::istream & is, Fink & f){
    is >> f.fname;
    is >> f.lname;
    is >> f.job;
    is >> f.reportsto;
    return is;
 }

 std::istream & operator>>(std::istream & is, Fink & hf){
    is >> hf.fname;
    is >> hf.lname;
    is >> hf.job;
    is >> hf.chargeof;
    is >> hf.reportsto;
    return is;
 }
 */
