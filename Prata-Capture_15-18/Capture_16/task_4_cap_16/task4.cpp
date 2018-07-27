#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

int reduce(long ar[], int n);


int main(){
    long arr[5] = {1,3,3,5,6};
    
    int elements = reduce(arr, 5);

    std::cout<<"Liczba elementow po posortowaniu i usunieciu = " << elements << '\n';

   
    return 0;
}

int reduce(long ar[], int n){
    std::list<long> tmp(ar, ar + n);
    tmp.sort();
    tmp.unique();
    
     for(auto i : tmp)
        std::cout<<i<<std::endl;

    return tmp.size();
}

