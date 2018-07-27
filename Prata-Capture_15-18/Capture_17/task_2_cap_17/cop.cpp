#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){
    using namespace std;

    ofstream out;
    out.open("count.txt");
    
    if(!out.is_open()){
        cerr << "Nie mozna otworzyc pliku.\n";
        exit(EXIT_FAILURE);
    }

    int count = 0;
    char ch;

    cin.get(ch);

    while(ch != '\n'){
        count++;
        out << ch;
        cin.get(ch);
    }

    out.close();

    return 0;
}

