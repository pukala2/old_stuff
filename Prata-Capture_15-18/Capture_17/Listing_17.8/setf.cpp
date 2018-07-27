//setf.cpp -- sterowanie formatowaniem za pomoca metody setf()
#include <iostream>

int main(){
    int temperature = 26;

    std::cout << "Dzisiaj temeratura wody: ";
    std::cout.setf(std::ios_base::showpos);
    std::cout << temperature << std::endl;

    std::cout << "Dla znajomych programistow bedzie to\n";
    std::cout << std::hex <<temperature <<std::endl; //zapis szesnastkowy
    std::cout.setf(std::ios_base::uppercase); //wielkie litery w zapisie szesnastkowym
    std::cout.setf(std::ios_base::showbase); //przedrostek 0x w zapisie szesnastkowym
    std::cout << "lub\n";
    std::cout << temperature << std::endl;

    std::cout << "Jakie to prawdziwe (czyli " << true << ") ojej -- jakie to prawdziwe ( czyli "
        << std::cout.setf(std::ios_base::boolalpha);
    std::cout << true <<")!\n";

    return 0;

}
