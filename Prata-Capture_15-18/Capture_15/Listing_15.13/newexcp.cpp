//wyjatek bad_alloc
#include <iostream>
#include <new>
#include <cstdlib>

struct Big{
    double stuff[200000];
};

int main(){

 Big *pb;
 try{
  std::cout<<"Proba przydzialu wielkiego bloku pamieci:\n";
  pb = new Big[1000000]; //16 00 000 000 bajtow
  std::cout<<"Udalo sie przebrnac przez instrukcje new:\n";
 }

 catch(std::bad_alloc & ba){
  std::cout<<"Przechwycilem wyjatek!\n";
  std::cout<<ba.what()<<std::endl;
  exit(EXIT_FAILURE);
 }

  std::cout<<"Udalo sie przydzielic pamiec\n";
  pb[0].stuff[0]=4;
  std::cout<<pb[0].stuff[0]<<std::endl;
  delete [] pb;

 return 0;

}

