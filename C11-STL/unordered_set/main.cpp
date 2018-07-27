#include <iostream>
#include <unordered_set>
#include <numeric>
using namespace std;

int main(){
    //utworz i zainicjalizuj zbior nieuporzadkowany
    unordered_set<int> coll = { 1,2,3,5,7,11,13,17,19,77 };
    //wypisz elementy
    for(const auto i : coll){
        cout << i << " ";
    }
    cout << endl;
    
    //wstaw dodadkowe elementy
    coll.insert({-7,17,33,-11,17,19,1,13});
    //wyswietl elementy
    for(const auto i : coll){
        cout << i << " ";
    }
    cout << endl;
    
    //usun element o konkretnej wartosci
    coll.erase(33);

    //wstaw sume wszystkich istniejacych wartosci
    coll.insert(accumulate(coll.begin(), coll.end(), 0));

    //sprawdz czy zbior zawiera wartosc 19
    if(coll.find(19) != coll.end()){
        cout << "19 jest w zbiorze" << endl;
    }

    //usun wszystkie wartosci ujemne
    unordered_set<int>::iterator pos;
    for(pos = coll.begin(); pos != coll.end(); ){
        if(*pos < 0){
            pos = coll.erase(pos);
        }
        else{
            ++pos;
        }
    }
    for(const auto i : coll){
        cout << i << " ";
    }
    cout << endl;
}
