#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

struct Review{
        std::string title;
            int rating;
                double price;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool WorseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool CheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(std::shared_ptr<Review> & rr);
void ShowReview(std::shared_ptr<Review> & rr);

int main(){
    using namespace std;
    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp;
    while(FillReview(temp))
        books.push_back(temp);
     if(books.size() > 0){
         cout<<"Dziekuje. Podales "
             <<books.size() << " ocen ksiazek:\n"
             <<"Ocena\tKsiazka\n";
         for_each(books.begin(), books.end(), ShowReview);
         cout<<"Wybierz metode sortowania.\n";
         cout<<"1.Sortowanie wedlug tytulu.\n";
         cout<<"2.Sortowanie wedlug oceny.\n";
         cout<<"3.Sortowanie wedlug ceny.\n";
         cout<<"Wybor: ";
         char ch;
         cin>>ch;

        switch(ch){
            case '1':
                sort(books.begin(), books.end());
                cout<<"Posortowane wedlug tytulu:\nOcena\nKsiazka\n";
                break;

            case '2':
                sort(books.begin(), books.end(),WorseThan);
                cout<<"Posortowane wedlug tytulu:\nOcena\nKsiazka\n";
                break;

            case '3':
                sort(books.begin(), books.end());
                cout<<"Posortowane wedlug tytulu:\nOcena\nKsiazka\n";
                break;
             }
        for_each(books.begin(), books.end(), ShowReview);
                
                random_shuffle(books.begin(), books.end());
                        cout<<"Po wymieszaniu:\nOcena\nKsiazka\n";
                                for_each(books.begin(), books.end(), ShowReview);
     }
         else
                     cout<<"Brak danych. ";
             cout<<"Koniec\n";
                 
                 return 0;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2){     //sortowanie wedlug tytulow
        if(r1->title < r2->title)
                    return true;
            else if(r1->title == r2->title && r1->rating < r2->rating)
                        return true;
                else
                        return false;
}

bool WorseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2){
        if(r1->rating < r2->rating)
                    return true;                                     //sortowanie wedlug oceny
            else
                        return false;
}

bool CheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2){
         if(r1->price < r2->price)
                     return true;                                     //sortowanie wedlug ceny
             else
                         return false;
}

bool FillReview(std::shared_ptr<Review> & rr){
        std::shared_ptr<Review>x(new Review);
        std::cout<<"Wpisz tytul ksiazki (koniec, aby zakonczyc): ";
        std::getline(std::cin, x->title);
        if(x->title == "koniec")
            return false;
        std::cout<<"Wpisz ocene: ";
        std::cin>>x->rating;
        std::cout<<"Podaj cene ksiazki: ";
        std::cin>>x->price;

        rr = x;
        if(!std::cin)
            return false;
        //pozbycie sie reszty danych wejsciowych

        while(std::cin.get() != '\n')
            continue;
        return true;
}
                                                
                                                
void ShowReview(std::shared_ptr<Review> & rr){
    std::cout<<rr->rating<<"\t"<<rr->title<<"\t"<<rr->price<<std::endl;
}
