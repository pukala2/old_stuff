#include <iostream>
#include <iomanip>

using namespace std;

long double ludnosc_swiata;
long double ludnosc_polski;


int main()
{
    cout<<"Podaj liczbe ludnosci swiata:";
    cin >> ludnosc_swiata;
    cout<<"Podaj liczbe ludnosci polski:";
    cin >> ludnosc_polski;
    long double procent=(ludnosc_polski*100)/ludnosc_swiata;
    cout << setprecision(5)<<"Populacja Polski stanowi "<<procent<<"%"<<" populacji swiata";
    return 0;
}
