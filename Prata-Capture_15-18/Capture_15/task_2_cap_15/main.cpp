#include <iostream>
#include <math.h>
#include "exc.h"
#include <stdexcept>

double hmean(double a, double b);
double gmean(double a, double b);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    double x,y,z;
    cout<<"Podaj dwie liczby:";
    
    while(cin>>x>>y){
        try{
            z=hmean(x,y);
            cout<<"Srednia harmoniczna liczb "<<x<<" "<<y<<" Wynosi:"<< z<<endl;
            cout<<"Srednia geometryczna liczb wynosi "<<gmean(x,y)<<endl;
            cout<<"Podaj kolejna pare liczb, <w aby wyjsc>:";
        }
                 
     catch(Bad_gmean::Bad2 & b2){
         std::cout<<b2.what();
         cout<<"Sprobuj ponownie.\n";
         continue;
     }

     catch(Bad_hmean::Bad & b){
         std::cout<< b.what(); 
          cout<<"Zle dane koniec zabawy\n";
          break;
     }
    }
   
    cout<<"Koniec.\n";
}

double hmean(double a, double b){
    if(a==-b)
        throw Bad_hmean::Bad();
    return 2.0*a*b/(a+b);
}

double gmean(double a, double b){
    if(a<0||b<0)
       throw Bad_gmean::Bad2();
    return sqrt(a*b);
}
