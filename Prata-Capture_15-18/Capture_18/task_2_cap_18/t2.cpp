#include <string>
#include <iostream>
#include <utility>

class Cpmv{
public:
    struct Info{
        std::string qcode;
        std::string zcode;
        Info(const std::string & q="brak", const std::string & z = "brak") : qcode(q), zcode(z) {}
    };
private:
    Info *p;
public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && cp);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
};

int main(){
    Cpmv x; //konstruktor domyslny
    x.Display();

    Cpmv y("ALA", "KOT"); // konstruktor z parametrami string
    y.Display();

    Cpmv z(y); //konstruktor kopiujacy
    z.Display();

    Cpmv a(std::move(y)); //move konstruktor
    a.Display();

    Cpmv b;
    b = a; //operator przypisania kopiujacy
    b.Display();

    Cpmv c;
    c = std::move(x); //operator przypisania przenoszacy
    c.Display();

    Cpmv d = (std::move(c + b)); // operato dodawania z r value
    d.Display();
}

Cpmv::Cpmv(){
    std::cout << "Konstruktor domyslny.\n";
    p = new Info;
}

Cpmv::Cpmv(std::string q, std::string z){
    std::cout << "Konstruktor z parametrami string.\n";
    p = new Info(q,z);
}

Cpmv::Cpmv(const Cpmv & cp){
    std::cout << "Konstruktor kopiujacy.\n";
    p = new Info(cp.p->qcode, cp.p->zcode);
}

Cpmv::Cpmv(Cpmv && cp){
    std::cout << "Konstruktor przenoszacy.\n";
    p = cp.p;
    cp.p = nullptr;
}

Cpmv::~Cpmv(){
    std::cout << "Destruktor.\n";
    delete p;
}

Cpmv & Cpmv::operator=(const Cpmv & cp){
    std::cout<< "Operator przypisania kopiujacy.\n";
    if(this == &cp)
        return *this;
    p = new Info(cp.p->qcode, cp.p->zcode);
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv){
    std::cout << "Operator przypisania przenoszacy.\n";
    if(this == &mv)
        return *this;
    p = mv.p;
    mv.p = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const{
    std::cout << "Operator dodawania.\n";
    Cpmv tmp(this->p->qcode + obj.p->qcode, this->p->zcode + obj.p->zcode);
    return tmp;
}

void Cpmv::Display() const{
    std::cout << p->qcode << " " << p->zcode << std::endl;
}

