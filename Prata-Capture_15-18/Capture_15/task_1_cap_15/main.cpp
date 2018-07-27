#include "tv.h"
#include <iostream>

int main()
{
    Tv s42;
    std::cout << "Poczatkowe ustawienia telewizora 42\n";
    s42.Settings();
    s42.Onoff();
    s42.Chan_up();
    std::cout << "\nNowe ustawienia telewizora 42:\n";
    s42.Settings();
    Remote grey;
    grey.Status_mode()== true ? std::cout<<"Pilot jest w stanie normal\n" : std::cout<<"Pilot jest w stanie inter\n"; 
    grey.Set_chan(s42,10);
    grey.Vol_up(s42);
    grey.Vol_up(s42);

    
    std::cout << "Ustawienia telewizora po uzyciu pilota:\n";
    s42.Settings();
    s42.Remote_MON(grey); 
    grey.Status_mode()== true ? std::cout<<"Pilot jest w stanie normal\n" : std::cout<<"Pilot jest w stanie inter\n"; 

    Tv s58(Tv::On);
    s58.Set_mode();
    grey.Set_chan(s58,28);                                                 
    std::cout << "\nUstawienia telewizora 58:\n";
    s58.Settings();
    std::cin.get();
    return 0;
}
