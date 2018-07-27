#include <iostream>
#include <math.h>
using namespace std;

int stopnie;float minut; float sekund;
float suma;
const float M=60;
const float S=3600;

int main()
{
    cout << "Podaj ile stopni:";
    cin >> stopnie;
    cout << "Podaj ile minut:";
    cin >> minut;
    cout << "Podaj ile sekund:";
    cin >> sekund;
    cout <<stopnie<<" stopni, "<<minut<<" minut, "<<sekund<<" sekund = ";
    cout <<stopnie+minut/M+sekund/S;

    return 0;
}
