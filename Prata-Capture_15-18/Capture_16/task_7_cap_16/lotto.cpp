#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

std::vector<int>Lotto(int lp, int lk);

int main(){
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> wynik = Lotto(51,6);
    std::cout<<"O to wylosowane liczby:\n";
    for(auto i : wynik)
        std::cout<<i<<"\t";
    std::cout<<std::endl;
    return 0;
}

std::vector<int> Lotto(int lp, int lk){
    std::vector<int> tmp;
    for(int i = 0; i < lp; i++)
        tmp.push_back(i + 1);

    std::random_shuffle(tmp.begin(),tmp.end());


    std::vector<int> score(lk);
    for(int i = 0; i < lk; i++)
        score[i] = tmp[i];

    return score;
}
