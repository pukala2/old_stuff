#include <iostream>
#include <unordered_set>
#include "bucket.h"

int main(){
    //utworzenie i inicjalizacja zbioru nieporzadkowanego
    std::unordered_set<int> intset = { 1,2,3,5,7,11,13,17,19 };
    printHashTableState(intset);

    //wstaw dodatkowe wartosci (moze spowodowac ponowne przemieszczanie)
    intset.insert({-7,17,33,4});
    printHashTableState(intset);
}
