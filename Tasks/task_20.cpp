#include <iostream>

template <class T>
void foo(T value)
{
    static int counter;
    ++counter;
    std::cout << counter << std::endl;
}

int main()
{
    foo(4);
    foo(5);
    foo(5.5);

    return 0;
}
