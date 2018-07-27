#include <iostream>

class A
{
public:
    A() { std::cout << "Constructor A\n"; }
    virtual ~A() { std::cout << "Destructor A\n"; }
};

class B : public A
{
public:
    B() { std::cout << "Constructor B\n"; }
   ~B() { std::cout << "Destructor B\n"; }
};

int main()
{
    
    A *ptrA = new A;
    A *ptrB = new B;
    
    
    delete ptrA;
    delete ptrB;
    return 0;
}
