#include <iostream>

class A
{
public:
    A() { std::cout << "Constructor A default\n"; }
    A(int val) : value(val)
    { 
        std::cout << "Constructor A not default\n"; 
    }
   virtual ~A() { std::cout << "Destructor A\n"; }
private:
    int value;
};

class B : public A
{
public:
    B() { std::cout << "Constructor B default\n"; }
    B(int val) : A(val)
    { 
        std::cout << "Constructor B not default\n"; 
    }
   ~B() { std::cout << "Destructor B\n"; }
};

int main()
{
    
    A *ptrA = new A;
    B *ptrB = new B(4);
    
    
    delete ptrA;
    delete ptrB;
    return 0;
}
