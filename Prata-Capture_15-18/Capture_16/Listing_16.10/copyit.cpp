#include <iostream>
#include <iterator>
#include <vector>

int main(){
    using namespace std;

    int cast[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);
    //kopiuje dane z tablicy do vectora
    copy(cast, cast + 10, dice.begin());
    cout<<"Niech kosci zostana rzucone!\n";
    //tworzy ostream_operator
    ostream_iterator<int, char> out_iter(cout, "  ");
    //kopiuje z vectora do strumienia wyjscia
    copy(dice.begin(), dice.end(), out_iter);
    cout<<endl;
    cout<<"Niejawne uzycie iteratora odwrotnego.\n";
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout<<endl;
    cout<<"Jawne uzycie iteratora odwrotnego.\n";
    vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout<<*ri<<"  ";
    cout<<endl;

    return 0;
}
