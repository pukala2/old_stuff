#include <iostream>

using namespace std;

int wzrostcm;

int main()
{
    cout << "podaj wzrost w cm:";
    cin >> wzrostcm;

    const float cal=30.48;

    cout << "Twoj wzrost to: "<<wzrostcm/cal<<" cali lub "<<cal/12<<" stop";

    return 0;
}
