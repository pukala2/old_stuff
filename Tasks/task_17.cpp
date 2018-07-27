#include <iostream>

void foo(int & a)
{
    a += 1;
}

int main()
{
    int x = 5;
    foo(x);
    std::cout << x;
    
    return 0;
}
