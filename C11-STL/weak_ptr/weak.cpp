#include <iostream>
#include <string>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<weak_ptr<Person>> kids;

    Person(const string &n, shared_ptr<Person> m = nullptr,
            shared_ptr<Person> f = nullptr) : name(n), mother(m), father(f){}

    ~Person(){
        cout << "Usuwam " << name << endl;
    }
};

shared_ptr<Person> initFamily(const string & name){
    shared_ptr<Person> mom(new Person("mama "+name));
    shared_ptr<Person> dad(new Person("tata "+name));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

int main(){
    shared_ptr<Person> p = initFamily("nico");

    cout << "Rodzina nico istnieje" << endl;
    cout << "-nico jest wspoldzielony " << p.use_count() << "-krotnie" << endl;
    cout << "imie pierwszego dziecka mamy nico: "
         << p->mother->kids[0].lock()->name << endl;

    p = initFamily("jim");
    cout << "Rodzina Jima istnieje" << endl;
}
