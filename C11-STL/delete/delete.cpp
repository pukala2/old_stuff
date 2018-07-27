//stl remove 
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

int main(){
    std::list<int> coll;
    //ustaw elementy od 6 do 1 oraz od 1 do 6
    for(int i = 1; i <= 6; i++){
        coll.push_front(i);
        coll.push_back(i);
    }

    //wypisz wszystkie elementy
    std::copy(coll.cbegin(), coll.cend(), //zakres
            std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;


    //usun wszystkie elementy o wartosci 3
    //zachowaj nowa pozycje konca
    std::list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

    //wypisz wynikowe elementy kolekcji
    std::copy(coll.begin(), end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //wypisz liczbe elementow usunietych
    std::cout << "Liczba usunietych elementow: " << std::distance(end, coll.end()) << std::endl;

    //usun "usuniete" elementy
    coll.erase(end, coll.end());

    //wypisz wszystkie elementy kolekcji
    std::copy(coll.cbegin(), coll.cend(),
            std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
}
