//inserts.cpp -- funkcja copy() i iteratory wstawiania
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

void Output(const std::string &s) { std::cout<<s<<" ";}

int main(){
    using namespace std;
    string s1[4] = {"kata", "karp", "karma", "kura"};
    string s2[2] = {"pusty", "pies"};
    string s3[2] = {"maska", "muzyk"};
    vector<string> words(4);

    copy(s1, s1+4, words.begin());
    for_each(words.begin(), words.end(), Output);
    cout<<endl;

    //tworzy anonimowy obiekt typu back_insert_iterator
    copy(s2, s2+2, back_insert_iterator<vector<string> >(words));
    for_each(words.begin(), words.end(), Output);
    cout<<endl;

    //tworzy anonimowy obiekt typu insert_iterator
    copy(s3, s3+2, insert_iterator<vector<string> >(words, words.begin()));
    for_each(words.begin(), words.end(), Output);
    cout<<endl;

    return 0;
}
