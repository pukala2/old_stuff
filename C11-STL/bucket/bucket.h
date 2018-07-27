#include <iostream>
#include <iomanip>
#include <utility>
#include <iterator>
#include <typeinfo>

//ogolne wyswietlanie par (elementow map)
template<typename T1, typename T2>
std::ostream & operator<<(std::ostream & strm, const std::pair<T1,T2>&p){
    return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T>
void printHashTableState(const T & cont){
    //podstawowe dane dotyczace ukladu wewnetrznego
    std::cout << "rozmiar:               " << cont.size() << "\n";
    std::cout << "liczba kubelkow:       " << cont.bucket_count() << "\n";
    std::cout << "wsp. obciazenia:       " << cont.load_factor() << "\n";
    std::cout << "maks. wsp. obciazenia: " << cont.max_load_factor() << "\n";

    //kategoria iteratora
    if(typeid(typename std::iterator_traits<typename T::iterator>::iterator_category)
            == typeid(std::bidirectional_iterator_tag)){
        std::cout << "typ polaczenia:     lista dwukierunkowa\n";
    }
    else{
        std::cout << "typ polaczenia:     lista jednokierunkowa\n";
    }

    //elementy w kubelkach
    std::cout << "dane: " << "\n";
    for(auto idx = 0; idx != cont.bucket_count(); ++idx){
        std::cout << " b[" << std::setw(2) << idx << "]: ";
        for(auto pos = cont.begin(idx); pos != cont.end(idx); ++pos){
            std::cout << *pos << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
