//strfile.cpp -- wczytuje ciagi znakow z plikow
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(){
    using namespace std;
    ifstream fin;
    fin.open("zakupy.txt");
    if(fin.is_open()==false){
        cerr << "Nie mozna otworzyc pliku.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;

    getline(fin,item, ':');
    while(fin){    //dopoki wprowadzane dane sa poprawne
        ++count;
        cout<<count<<": "<<item<<endl;
        getline(fin, item, ':');
    }
    cout<<"koniec\n";
    fin.close();
    return 0;
}
