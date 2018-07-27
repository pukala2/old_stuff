#include <iostream>

struct A
{
    A() { std::cout << "Constructor A default\n"; }
    virtual ~A() { std::cout << "Destructor A\n"; }
};

struct B : public A
{
    B() { std::cout << "Constructor B default\n"; }
    ~B() { std::cout << "Destructor B\n"; }
};

struct C : public B
{
public:
    C() { std::cout << "Constructor C default\n"; }
   ~C() { std::cout << "Destructor C\n"; }
};

int main()
{
    
    A *ptrA = new A;
    A *ptrB = new B;
    A *ptrC = new C;
    
    delete ptrA;
    delete ptrB;
    delete ptrC;
    return 0;
}
