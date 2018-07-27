#include <iostream>
#include <fstream>
#include <cstdlib>  //funkcja exit

int main(int argc, char * argv[])

{
    using namespace std;

    if(argc == 1){
        cerr << "Skladnia " << argv[0] << "plik[i]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin;
    long count;
    long total = 0;
    char ch;              

    for(int file = 1; file < argc; file++){
        fin.open(argv[file]);  //skojarz strumien z plikiem ardv[file]
        if(!fin.is_open()){
            cerr << "Nie mozna otworzyc pliku " << argv[file] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while(fin.get(ch))
            count++;
        cout << count << "znakow w pliku " << argv[file] <<endl;
        total += count;
        fin.clear();
        fin.close();
    }
    cout<< total << " znakow we wszystkich plikach\n";
    
    return 0;
}
