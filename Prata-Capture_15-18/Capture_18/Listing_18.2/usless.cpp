//usless.cpp -- klasa (poza tym bezuzyteczna) ilustrujaca semantyke przeniesienia
#include <iostream>
#include <utility>

using namespace std;

class Usless{
private:
    int n; //liczba elementow
    char *pc; //wskaznik do danych 
    static int ct; //liczba elementow
    void ShowObject() const;
public:
    Usless();
    explicit Usless( int k);
    Usless(int k, char ch);
    Usless(const Usless & f);
    Usless(Usless &&f); //konstruktor przenoszacy
    ~Usless();
    Usless operator+(const Usless &f) const;
    //operator=() potrzebny w wersjach kopiujacej i przenoszacej
    void ShowData() const;
};

int Usless::ct = 0;

Usless::Usless(){
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "Konstruktor domyslny; liczba obiektow = " << ct << "\n";
    ShowObject();
}

Usless::Usless(int k) : n(k){
    ++ct;
    pc = new char[n]; 
    cout << "Konstruktor (int); liczba obiektow = " << ct << "\n";
    ShowObject();
}

Usless::Usless(int k, char ch) : n(k){
    ++ct;
    cout << "Konstruktor (int, char); liczba obiektow: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Usless::Usless(const Usless & f) : n(f.n) {
    ++ct;
    cout << "Konstruktor kopiujacy; liczba obiektow: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Usless::Usless(Usless && f): n(move(f.n)), pc(move(f.pc)){
    ++ct;
    f.pc = nullptr;
    f.n = 0;
    cout << "Konstruktor przenoszacy; liczba obiektow: " << ct << endl;
    ShowObject();
}

Usless::~Usless(){
    cout << "Destruktor; liczba obiektow: " << --ct << endl;
    cout << "usowamy obiekt:\n";
    ShowObject();
    delete [] pc;
}

Usless Usless::operator+(const Usless & f) const{
    cout << " wejscie do operator +()\n";
    Usless tmp = Usless(n + f.n);
    for(int i = 0; i < n; i++)
        tmp.pc[i] = pc[i];
    for(int i = n; i < tmp.n; i++)
        tmp.pc[i] = f.pc[i - n];
    cout << "obiekt tymczasowy:\n";
    cout << "wyjscie z operator+()\n";
    return tmp;
}

void Usless::ShowObject() const{
    cout << "Liczba elementow " << n;
    cout << ", adres danych : " << (void*) pc << endl;
}

void Usless::ShowData() const{
    if(n == 0)
        cout << "(obiekt pusty)";
    else
        for(int i =0; i < n; i++)
            cout << pc[i];
    cout << endl;
}


int main(){
    {
        Usless one(10, 'x');
        Usless two = one;
        Usless three(20, 'o');
        Usless four(std::move(one + three));
        cout << "obiekt 1.: ";
        one.ShowData();
        cout << "obiekt 2.: ";
        two.ShowData();
        cout << "obiekt 3.: ";
        three.ShowData();
        cout << "obiekt 4.: ";
        four.ShowData();
        Usless five(Usless(20, 'p'));
        cout << "obiekt 5.: ";
        five.ShowData();
    }
}
