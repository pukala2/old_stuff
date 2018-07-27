#include <iostream>

using namespace std;

long long sekundy;

const int DS=86400;
const int GS=3600;
const int MS=60;

int main()
{
    cout << "Podaj liczbe sekund:";
    cin >> sekundy;

    long long dzien=sekundy/DS;
    long long godzin=(sekundy)%(dzien*DS)/GS;
    long long minut=(sekundy)%(dzien*DS)%(godzin*GS)/MS;
    long long sekund=(sekundy)%(dzien*DS)%(godzin*GS)%(minut*MS);

    cout <<sekundy<<" sekund = "<<dzien<<" dni, "<<godzin;
    cout<<" godzin, "<<sekund<<" sekund";
    return 0;


}
