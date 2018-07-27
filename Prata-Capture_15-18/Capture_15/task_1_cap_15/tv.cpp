#include "tv.h"
#include <iostream>

bool Tv::Vol_up() {
     if (volume < MaxVal) {
         volume++;
         return true;
     }
     else
         return false;
}

bool Tv::Vol_down() {
     if (volume > MinVal) {
         volume--;
         return true;
     }
     else
         return false;
}

void Tv::Chan_up() {
     if (chanel < maxchanel) {
         chanel++;
     }
     else
         chanel = 1;
}

void Tv::Chan_down() {
     if (chanel > 1)
         chanel--;
     else
         chanel = maxchanel;
}

 void Tv::Remote_MON(Remote & r ){  //metoda pozwalajaca zmieniac stan pilota
         if(IsOn() == true)
             r.remote_state = (r.remote_state == Remote::normal) ? Remote::inter : Remote::normal;
     }

void Tv::Settings()const {
     std::cout << "Telewizor jest " << (state == Off ? "Wylaczony" : "Wlaczony") << std::endl;
     if (state == On) {
         std::cout << "Glosnosc = " << volume << std::endl;
         std::cout << "Program = " << chanel << std::endl;
         std::cout << "Tryb = " << (mode == Antena ? "antena" : "kabel") << std::endl;
         std::cout << "Wejscie = " << (input == TV ? "TV":"DVD") << std::endl;
     }
}
