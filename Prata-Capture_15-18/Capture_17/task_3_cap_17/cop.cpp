#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){
    using namespace std;
    const char * name1 = "will_be_coppy.txt";
    ifstream fin;
    fin.open(name1);

    if(!fin.is_open()){
        cerr << "Podany plik nie istnieje.\n";
        exit(EXIT_FAILURE);
    }

    ofstream fout;
    fout.open("get_coppy.txt");
    
    char ch;

    while(fin.get(ch)){
        fout << ch;
    }

    fin.close();
    fout.close();
    return 0;
}
