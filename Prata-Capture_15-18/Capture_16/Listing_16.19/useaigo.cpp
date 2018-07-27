//useaigo.cpp -- uzywanie roznych elementow bibloteki STL
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

char ToLower(char ch) { return tolower(ch); }
string & ToLower2(string &st);
void display(const string &s);

int main(){
    vector<string> words;
    cout<<"Podaj slowa (koniec, aby zakonczyc):\n";
    string input;
    while(cin >> input && input != "koniec")
        words.push_back(input);

    cout<<"Podales nastepujace slowa:\n";
    for(auto i:words)
        cout << i <<"  ";
    cout<<endl;

    //umiesza slowa w zbiorze, przeksztalcajac duze litery na male
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator<set<string> >(wordset, wordset.begin()), ToLower2);
    cout<<"\nAlfabetyczna lista slow:\n";

    for(auto i:words)
        cout << i <<"  ";
    cout<<endl;

    //umieszcza slowa i liczbe i wystapien w kontenerze map
    map<string, int> wordmap;
    set<string>::iterator si;

    for(si = wordset.begin(); si != wordset.end(); si++ )
        wordmap[*si] = count(words.begin(), words.end(), *si);

    //wyswietla zawartosc kontenera map
    cout<<"\nLiczba wystapien slow:\n";
    for(si = wordset.begin(); si != wordset.end(); si++)
            cout<<*si<<":"<<wordmap[*si] << endl;
            

    return 0;
}

string & ToLower2(string &st){
    transform(st.begin(), st.end(), st.begin(), ToLower);
    return st;
}
