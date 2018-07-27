#include <iostream>
#include <iomanip>

using namespace std;

float litry;

int main()
{
    cout << "Podaj ile litrow pali twoj samochod na 100 km:";
    cin >>litry;

    float dzielnik=(litry/3.875);
    float mila=0.6214*100/dzielnik;


   cout <<"twoj samochod pali: "<<setprecision(2)<<mila<<" mil na galon.";


    return 0;
}
