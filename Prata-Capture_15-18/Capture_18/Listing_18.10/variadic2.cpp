#include <iostream>
#include <string>

//definicja dla pustej listy parametrow
void Show_list() {}

//definicja dla pojedynczego parametru
template<typename T>
void Show_list(const T & value){
    std::cout << value << '\n';
}

//definicja dla dwoch i wiecej parametrow
template<typename T, typename... Args>
void Show_list(const T & value, const Args&... args){
    std::cout << value << '\n';
    Show_list(args...);
}

int main(){
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mosci String tez!";
    Show_list(n, x);
    Show_list(x*x, '!', 7, mr);
    return 0;
}
