//list.cpp -- uzywanie listy
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void Outint(int n) { std::cout<<n<<" "; }

int main(){
    using namespace std;
    list<int> one(5, 2); //lista pieciu wartosci 2
    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout<<"Lista one: ";
    for_each(one.begin(), one.end(), Outint);
    cout<<"\nLista two: ";
    for_each(two.begin(), two.end(), Outint);
    cout<<"\nLista three: ";
    for_each(three.begin(), three.end(), Outint);
    
    three.remove(2);
    cout<<"\nLista three, bez dwojek: ";
    for_each(three.begin(), three.end(), Outint);
    three.splice(three.begin(), one);
    cout<<"\nLista three, po uzyciu funkcji splice: ";
    for_each(three.begin(), three.end(), Outint);
    cout<<"\nLista one: ";
    for_each(one.begin(), one.end(), Outint);
    three.unique();
    cout<<"\nLista three po uzyciu funkcji unique: ";
    for_each(three.begin(), three.end(), Outint);
    three.sort();
    three.unique();
    cout<<"\nLista three po uzyciu sort oraz unique: ";
    for_each(three.begin(), three.end(), Outint);
    two.sort();
    three.merge(two);
    cout<<"\nPosortowana lista two wklejona w liste three: ";
    for_each(three.begin(), three.end(), Outint);
    cout<<endl;

    return 0;
}
