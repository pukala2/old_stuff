//vect2.cpp -- metody i iteratory klasy vector
#include <iostream>
#include <string>
#include <vector>
#include "vec.h"

int main(){
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
    int num = books.size();

    if(num > 0){
        cout<<"Dziekuje. Wpisales nastepujace dane:\n"
            <<"Ocena\tKsiazka\n";
        for(int i = 0; i<num; i++)
            ShowReview(books[i]);
        cout<<"Przypomnienie ocen:\n"
            <<"Ocena\tKsiazka\n";
      //zastosowanie iteratora
        vector<Review>::iterator pr;
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        vector<Review> oldlist(books); //uzywam konstruktor kopiujacy

        if(num>3){
            //usuwa 2 elementy
            books.erase(books.begin() + 1, books.begin() + 3);
            cout<<"Po usunieciu :\n";
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            //wstawia 1 element
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout<<"Po wstawieniu:\n";
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout<<"Zmiana zawartosci wectorow oldlist i books:\n";
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout<<"Bez wypisania nie ma wyswietlania\n";
    return 0;
}
