#include <iostream>

using namespace std;

float wzrost; float m;
float waga; float kg;


int main()
{
    cout << "Podaj wzrost w stopach:";
    cin >> wzrost;
    cout << "Podaj swoja wage w funtach:";
    cin >> waga;


   m=wzrost/12*(0.0254);kg=waga/2.2;
   float bmi=kg/m*m;



   cout <<"BMI wynosi : "<<bmi<<endl;
   cout <<"Twoj wzrost to: "<<m*100<<" a waga "<<kg;
    return 0;
}
