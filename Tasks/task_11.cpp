#include <iostream>

class A
{
public:
    A(int val)
    {
        valuea = val;
        std::cout << "Constructor A\n";
    }
    A(const A & cp)
    {
        std::cout << "Copy Constructor A\n";
        valuea = cp.valuea;
    }
    virtual ~A() { std::cout << "Destructor A\n"; }
private:
    int valuea;
};

class B : public A
{
public:
    B(int val) : A(val)
    {
        valueb = val;
        std::cout << "Constructor B\n";
    }
    B(const B & cp) : A(cp)
    {
        std::cout << "Copy Constructor B\n";
        valueb = cp.valueb;
    }
    ~B() { std::cout << "Destructor B\n"; }
private:
    int valueb;
};


int main()
{
    
    A ptrA1(3);
    A ptrA2(ptrA1);

    return 0;
}
