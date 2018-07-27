#include <iostream>

using namespace std;

double lata;

double lat_swietlnych(double l)
{
    return l*63240;
}
int main()
{
    cout << "Podaj liczbe lat swietlnych";
    cin >> lata;
    cout << lata<<" lat swietlnych = "<<lat_swietlnych(lata)<<" jednostek astronomicznych.";
    return 0;
}
