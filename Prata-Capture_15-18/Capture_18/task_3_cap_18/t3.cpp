#include <iostream>

template<class T>
T adder(T val){
    return val;
}

template<typename T, typename... Args>
T adder(T first, Args... args){
    return first + adder(args...);
}

int main(){
    std::cout << adder(1,2,3,4,5,5) << std::endl;
    return 0;
}
