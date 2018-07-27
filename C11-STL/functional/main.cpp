#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

int main(){
    set<int,greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    deque<int> coll2;

    //greater powoduje odwrotne sortowanie
    
    for(const auto & i : coll1)
        cout << i << " ";
    cout << endl;
    cout << endl;

    //przeksztalc wszystkie elementy do kolejki coll2 jako iloczyn 10
    
    transform(coll1.cbegin(), coll1.cend(), //zrodlo
            back_inserter(coll2), //przeznaczenie
            bind(multiplies<int>(), _1, 10)); //operacja

    for(const auto & i : coll2)
        cout << i << " ";
    cout << endl;
    cout << endl;
    
    //zastap elementy o wartosci 70 elementami o wartosci 42
    
    replace_if(coll2.begin(), coll2.end(), //zakres
            bind(equal_to<int>(),_1, 70), //kryterium zastapienia
            42); //nowa wartosc

    for(const auto & i : coll2)
        cout << i << " ";
    cout << endl;
    cout << endl;

    //usun wszystkie elementy o wartosci pomiedzy 50 i 80
    coll2.erase(remove_if(coll2.begin(), coll2.end(),
                bind(logical_and<bool>(),
                    bind(greater_equal<int>(), _1, 50),
                    bind(less_equal<int>(), _1, 80))),
            coll2.end());
   
    for(const auto & i : coll2)
        cout << i << " ";
    cout << endl;
}
