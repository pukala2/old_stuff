#include <iostream>

int main(){
    char ch;
    int count;
    std::cout << " Podaj slowa a ja policze znaki <$ aby zakonczyc> :\n";
    
    std::cin.get(ch);

    while(ch != '$'){
        count++;
        std::cin.get(ch);
    }

    std::cout << "Znak ktory pozostal w strumieniu = " << ch << std::endl;
    std::cout << "Liczba znakow = " << count << std::endl;
    
    return 0;
}
