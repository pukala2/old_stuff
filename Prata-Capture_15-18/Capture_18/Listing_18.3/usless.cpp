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
    Usless operator=(const Usless &f); //przypisanie kopiujace
    Usless operator=(Usless &&f); //kopiowanie przenoszace
    void ShowData() const;
};

int Usless::ct = 0;

Usless::Usless(){
    ++ct;
    n = 0;
    pc = nullptr;
}

Usless::Usless(int k) : n(k){
    ++ct;
    pc = new char[n]; 
}

Usless::Usless(int k, char ch) : n(k){
    ++ct;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = ch;
}

Usless::Usless(const Usless & f) : n(f.n) {
    ++ct;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
}

Usless::Usless(Usless && f): n(move(f.n)), pc(move(f.pc)){
    ++ct;
    f.pc = nullptr;
    f.n = 0;
}

Usless::~Usless(){
    delete [] pc;
}

Usless Usless::operator+(const Usless & f) const{
    Usless tmp = Usless(n + f.n);
    for(int i = 0; i < n; i++)
        tmp.pc[i] = pc[i];
    for(int i = n; i < tmp.n; i++)
        tmp.pc[i] = f.pc[i - n];
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

Usless Usless::operator=(const Usless &f){
    cout << "Kopiujacy operator przypisania.\n";
    if(this==&f)
        return *this;
    delete [] pc;
    n = f.n;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    return *this;
}

Usless Usless::operator=(Usless &&f){
    cout << "Przenoszacy operator przypisania.\n";
    if(this == &f)
        return *this;
    n = f.n;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    return *this;
}


int main(){
    {
        Usless one(10, 'x');
        Usless two = move(one + one); //wywolanie konstruktora przenoszacego
        cout << "obiekt one: ";
        one.ShowData();
        cout << "Obiekt two: ";
        two.ShowData();
        Usless three, four;
        cout << "Three = one\n";
        three = one;
        //automatczne przypisanie kopiujace
        cout << "Teraz obiekt three = ";
        three.ShowData();
        cout << "a obiekt one = ";
        one.ShowData();
        cout << "four = one + two\n";
        four = one + two;
        //automatyczne przyisanie kopiujace
        cout << "teraz obiekt four = ";
        four.ShowData();
        cout << "For = move(one)\n";
        four = move(one);
        //wymuszone przypisanie przenoszace
        cout << "teraz obiekt four =";
        four.ShowData();
        cout << "a obiekt one = ";
        one.ShowData();
    }
}
