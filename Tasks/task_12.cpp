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
    B(const A & cp) : A(cp)
    {
        std::cout << "Copy Constructor B\n";
    }
    ~B() { std::cout << "Destructor B\n"; }
private:
    int valueb;
};


int main()
{
    
    A A1(3);
    A A2(A1);
    B B1(A2);

    return 0;
}
