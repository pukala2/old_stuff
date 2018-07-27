#include <iostream>

void foo()
{
    static int counter;
    std::cout << counter++ << std::endl;
}

int main()
{

    foo();
    foo();
    
    return 0;
}
