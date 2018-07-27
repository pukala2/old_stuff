//functor.cpp -- uzywanie functorow
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T> //klasa functora definiuje operator()()
class TooBig{
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void Outint(int n) { std::cout<<n<<"  "; }

int main(){
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100); //ograniczenie = 100

    //int vals[10] = {50, 100, 90, 180, 60, 210, 415 , 88, 188, 201};
    list<int> yadayada = { 50, 100, 90, 180, 60, 210, 415 , 88, 188, 201 };
    list<int> etcetera = { 50, 100, 90, 180, 60, 210, 415 , 88, 188, 201 };
    
    cout<<"Orginalne listy:\n";
    for_each(yadayada.begin(), yadayada.end(), Outint);
    cout<<endl;
    for_each(etcetera.begin(), etcetera.end(), Outint);
    cout<<endl;

    yadayada.remove_if(f100); //uzywa nazwanego obiektu funkcyjnego
    etcetera.remove_if(TooBig<int>(200)); //tworzy obiekt funkcyjny
    cout<<"Przyciete listy:\n";
    for_each(yadayada.begin(), yadayada.end(), Outint);
    cout<<endl;
    for_each(etcetera.begin(), etcetera.end(), Outint);
    cout<<endl;

    return 0;
}
