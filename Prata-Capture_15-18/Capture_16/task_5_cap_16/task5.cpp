#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <string>
////
template<class T>
int reduce(T ar[], int n);


int main(){
    long arrl[5] = {1, 3, 3, 5, 6}; 
    int elements = reduce(arrl, 5);
    std::cout<<"Sprawdzenie dzialania funkcji dla typu long.\n";
    std::cout<<"Liczba elementow po posortowaniu i usunieciu = " << elements << '\n';
    
    std::cout<<std::endl;
  
    std::string arrs[5] = {"kot", "kot", "pies", "slon", "zaba"}; 
    elements = reduce(arrs, 5);
    std::cout<<"Sprawdzenie dzialania funkcji dla typu string.\n";
    std::cout<<"Liczba elementow po posortowaniu i usunieciu = " << elements << '\n';
    
    std::cout<<std::endl;


    return 0;
}


template<class T>
int reduce(T ar[], int n){
    std::list<T> tmp(ar, ar + n);
    tmp.sort();
    tmp.unique();
    
     for(auto i : tmp)
        std::cout<<i<<std::endl;

    return tmp.size();
}

