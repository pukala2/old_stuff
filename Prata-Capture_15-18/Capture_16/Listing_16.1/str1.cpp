//str1.cpp -- wprowadzenie do klasy string
#include <iostream>
#include <string>
//uzywanie konstruktorow klasy string

int main(){
    using namespace std;
    string one("Zwyciezca loterii!"); //konstruktor nr 1
    cout<<one<<endl;
    string two(20,'$'); //konstruktor 2
    cout<<two<<endl;
    string three(one); //konstruktor 3
    cout<<three<<endl;
    one += "Ups!"; //przeciazony operator +=
    cout<<one<<endl;
    two = "Przepraszam. To byl"; 
    three[10] = 'k';
    string four;   //konstruktor 4
    four = two + three; //przeciazony operator =
    cout<<four<<endl;
    char alls[] = "Wszystko dobre, co sie dobrze konczy";
    string five(alls,22); //konstruktor 5
    cout<<five<<endl;
    string six(alls + 9, alls +14); //konstruktor 6
    cout<<six<<", ";
    string seven(&five[9], &five[14]); //ponownie konstruktor nr 6
    cout<<seven<<"...\n";
    string eight(four, 20, 9);  //konstruktor nr 7
    cout<<eight<<" w akcji "<<endl;
    return 0;
}
