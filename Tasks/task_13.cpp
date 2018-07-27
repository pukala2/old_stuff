#include <iostream>

class A
{
public:
    A() { std::cout << "Constructor A default\n"; }
    virtual ~A() { std::cout << "Destructor A\n"; }
private:
    int value;
};

class B : public A
{
public:
    B() { std::cout << "Constructor B default\n"; }
   ~B() { std::cout << "Destructor B\n"; }
};

class C : public A
{
public:
    C() { std::cout << "Constructor C default\n"; }
   ~C() { std::cout << "Destructor C\n"; }
};

int main()
{
    
    A A1;
    B B1;
    C C1;
    
    return 0;
}
