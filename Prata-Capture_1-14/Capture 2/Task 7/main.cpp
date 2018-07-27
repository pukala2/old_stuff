#include <iostream>

using namespace std;

int godz; int minut;

void godzin(int g)
{
    cout <<"Czas:"<< g;
}
void minutt(int m)
{
    cout << m;
}

int main()
{
    cout << "Podaj liczbe godzin:";
    cin >> godz;
    cout << "Podaj liczbe minut:";
    cin >> minut;
    godzin(godz);cout <<":";
    minutt(minut);
    return 0;
}
