#include <iostream>

using namespace std;

int wiek;

int ile_miesiecy(int m)
{
    return m*12;
}

int main()
{
    cout << "Podaj swoj wiek:";
    cin >> wiek;
    cout <<"Twoj wiek w miesiacach to :"<<ile_miesiecy(wiek);
    return 0;
}
