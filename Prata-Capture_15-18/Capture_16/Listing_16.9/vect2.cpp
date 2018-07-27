//vect2.cpp -- metody i iteratory klasy vector
#include <iostream>
#include <string>
#include <vector>
#include "vec.h"
#include <algorithm>

int main(){
    using namespace std;

    vector<Review> books;
    Review temp;
    
    while(FillReview(temp))
        books.push_back(temp);
    if(books.size() > 0)
    {
        std::cout<<"Dziekuje. Podales "<<books.size()<<" ocen ksiazek:\n"
            <<"Ocena\tKsiazka\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());
        std::cout<<"Posortowane wedlog tytulu: \nOcena\tKsiazka\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), WorseThan);
        cout<<"Posortowane wedlug oceny: :\nOcena\tKsiazka\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout<<"Po wymieszaniu:\nOcena\tKsiazka\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout<<"Brak danych. ";
    cout<<"Koniec.\n";

    return 0;
}
