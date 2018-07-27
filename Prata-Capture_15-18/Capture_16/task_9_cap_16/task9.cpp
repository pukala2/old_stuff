#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main(){
   
    std::srand(time(NULL));
    
    std::vector<int> vi0;

    int tmp;

    for(int i=0; i <= 10000000; i++){
        tmp = std::rand()%10000+1;
        vi0.push_back(tmp);
    }

    std::vector<int> vi(vi0);
    std::list<int> li;
    std::copy(vi.begin(), vi.end(), back_inserter(li));

    std::clock_t start, stop;
    double timer;
    std::cout<<"Licze czas dla sortowania vectora vi z 10 000 000 elementow  ...\n";

    start = clock();

    std::sort(vi.begin(), vi.end());

    stop = clock();
   
    timer = (double)(stop - start)/CLOCKS_PER_SEC;
    std::cout<<"Czas sortowania vector = "<<timer<<std::endl;

    std::cout<<"Licze czas dla sortowania list li z 10 000 000 elementow  ...\n";

    start = clock();

    li.sort();

    stop = clock();
    timer = (double)(stop - start)/CLOCKS_PER_SEC;
    std::cout<<"Czas sortowania list = "<<timer<<std::endl;

    std::cout<<"\nPrzywrocenie do listy li nieuporzadkowanych elementow...\n\n"
        <<"Nastepnie mirzenie czasu dla kopiowania li do vi, sortowanie vi i kopiowanie sportorem do li...\n";
    
    li.clear();
    vi.clear();

    std::copy(vi0.begin(), vi0.end(), back_inserter(li));

    start = clock();
    
    vi.insert(vi.begin(), li.begin(), li.end());

    std::sort(vi.begin(), vi.end());
    std::copy(vi.begin(), vi.end(), back_inserter(li));
    
    stop = clock();
    
    timer = (double)(stop - start)/CLOCKS_PER_SEC;
    std::cout<<"Czas calej operacji = "<<timer<<std::endl;


    return 0;
}
