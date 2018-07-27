#include <iostream>
#include <string>
#include <vector>
#include <memory>

//funkcja ktora usunie obiekt juzek po zakonczeniu programu

std::shared_ptr<std::string> pNico(new std::string("juzek"),
    [](std::string *p){
    std::cout << "delete " << *p << std::endl;
    delete p;
    });


int main(){
    using namespace std;
    //dwa wspoldzielne wskazniki reprezentujace 2 imiona
    shared_ptr<string> pNico(new string("juzek"));
    shared_ptr<string> pJutta(new string("adam"));

    //poprawka  imion na wielka litere
    (*pNico)[0] = 'J';
    pJutta->replace(0,1,"A");

    //umieszczenie wskaznika w kontenerze wieloktotnie
    vector<shared_ptr<string>> whoMadeCoffe;
    whoMadeCoffe.push_back(pJutta);
    whoMadeCoffe.push_back(pJutta);
    whoMadeCoffe.push_back(pNico);
    whoMadeCoffe.push_back(pJutta);
    whoMadeCoffe.push_back(pNico);

    //wypisanie wszystkich elementow
    for(auto ptr : whoMadeCoffe){
        cout << *ptr << " ";
    }
    cout << endl;

    //ponowna zmiana imienia
    *pNico = "Swir";

    //ponowne wypisanie elementow:
    for(auto ptr : whoMadeCoffe){
        cout << *ptr << " ";
    }
    cout << endl;
    
    //wypisanie wewnetrznych danych wskaznika
    cout << "use_count: " << whoMadeCoffe[0].use_count() << endl;


}
