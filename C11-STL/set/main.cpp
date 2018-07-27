#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

int main(){
    //typ kolekcji
    //brak powtorzen
    //porzadek malejacy
    set<int, greater<int>> coll1;

    //wstaw elementy w pzypadkowej kolejnosci uzywajac wersji funkcji skladowych
    coll1.insert({4,3,5,1,6,2});
    coll1.insert(5);

    //iteruj po wszystkich elementach
    for(int elem : coll1){
        cout << elem << ' ';
    }
    cout << endl;

    //wstaw ponownie wartosc 4 i przetworz wartosc zwracana
    auto status = coll1.insert(4);
    if(status.second){
        cout << "wartosc 4 wstawiono jako element "
            << distance(coll1.begin(), status.first) + 1 << endl;
    }
    else{
        cout << "element 4 juz istnieje" << endl;
    }

    //przypisz elementy do innego zbioru o porzadku rosnacym
    set<int> coll2(coll1.cbegin(), coll1.cend());
    //wypisz wszystkie elementy zbioru uzywajac iteratora strumieniowego
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout," "));
    cout << endl;

    //usun wszystkie elementy az do elementu o wartosci 3
    coll2.erase(coll2.begin(), coll2.find(3));

    //usun wszystkie elementy o wartosci 5
    int num;
    num = coll2.erase(5);
    std::cout << "usunieto " << num << " elementow" << endl;

    //wypisz wszystkie elementy
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout," "));
    cout << endl;
}
