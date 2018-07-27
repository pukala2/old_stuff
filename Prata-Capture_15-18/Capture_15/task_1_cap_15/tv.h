#pragma once
#include <iostream>
class Remote;
class Tv {
    public:
     friend class Remote; //klasa remote ma dostep do prywatnych danych tv
     enum { Off, On };
     enum { MinVal, MaxVal=20 };
     enum { Antena, Cable };
     enum { TV, Dvd };
     Tv(int s = Off, int mc = 125) : state(s), volume(5),
     maxchanel(mc), chanel(2), mode(Cable), input(TV) {}
     void Onoff() { state = (state == On) ? Off : On; }
     bool IsOn()const { return state == On; }
     bool Vol_up();
     bool Vol_down();
     void Chan_up();
     void Chan_down();
     void Set_mode() { mode = (mode == Antena) ? Cable : Antena; }
     void Set_input() { mode = (mode == TV) ? Dvd : TV; }
     void Settings()const; //wyswietla wszystkie ustawienia
     void Remote_MON(Remote & r );  //metoda pozwalajaca zmieniac stan pilota
    private:
     int state; //wlaczony lub wylaczony
     int volume; //zakladamy, ze mozna glosnosc wyrazic liczba
     int maxchanel; //maksymalna liczba kanalow
     int chanel; //aktualnie wlaczony program
     int mode; //antena lub telewizja kablowa
     int input; //telewizja lub dvd
     };

class Remote {
   private:
       friend class Tv; //klasa Tv ma dostep do prywatnych remote
        int mode; //kontroluje TV lub Dvd
        enum {normal, inter};
    public:
        Remote(int m = Tv::TV, int s = normal) : mode(m), remote_state(s) {}
        bool Vol_up(Tv & t) {return t.Vol_up(); }
        bool Vol_down(Tv & t) { return t.Vol_down(); }
        bool Status_mode() {return remote_state == normal; }// nowa metoda wyswietlajaca tryb pilota
        void Onoff(Tv & t) { t.Onoff(); }
        void Chan_up(Tv & t) { t.Chan_up(); }
        void Chan_down(Tv & t) {t.Chan_down(); }
        void Set_chan(Tv & t, int c) { t.chanel = c; }
        void Set_mode(Tv & t) { t.Set_mode(); }
        void Set_input(Tv & t) { t.Set_input(); }
    private:
        int remote_state; //nowa skladowa
};



