#include <iostream>

using namespace std;

int stopnie;

int fahr(int s)
{
    return 1.8*s+32;
}

int main()
{
    cout << "Podaj temperature w stopniach Celsjusza:";
    cin >> stopnie;
    cout << stopnie<<" stopnie Celsjusza to "<<fahr(stopnie)<<" Farhenheita";
    return 0;
}
