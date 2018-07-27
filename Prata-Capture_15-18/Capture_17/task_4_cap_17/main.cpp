#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main(){
    using namespace std;
    ifstream f1;
    ifstream f2;
    ofstream out;
    f1.open("f1.txt");
    f2.open("f2.txt");
    out.open("out.txt");

    if(!f1.is_open() || !f2.is_open()){
        cerr << "ktorys z plikow nie istnieje.\n";
        exit(EXIT_FAILURE);
    }
    string str1, str2;
    vector<string> part1;
    vector<string> part2;
    while(getline(f1,str1))
        part1.push_back(str1);
    while(getline(f2,str2))
        part2.push_back(str2);
    
    int i = 0;
    int size;

    if(part1.size() > part2.size())
        size = part2.size();
    else
        size = part1.size();

    for(i = 0; i < size; i++)
        out << part1[i] << " " << part2[i] << endl;
    
    if(part1.size() > part2.size()){
        for(int j = i; j < part1.size(); j++)
            out << part1[j] << endl;
    }

     if(part1.size() < part2.size()){
        for(int j = i; j < part2.size(); j++)
            out << part2[j] << endl;
    }
        
    f1.close();
    f2.close();
    out.close();

    return 0;
}
