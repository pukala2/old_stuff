#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <vector>

int main()

{
  std::vector<std::string> eng;
  std::vector<std::string> pol;
  std::map<std::string,std::string> words;
  std::string tmp;

  std::ifstream file;
  file.open("list.txt");
  if(!file.is_open()){
    std::cerr << "Podany plik nie istnieje\n";
    exit(EXIT_FAILURE);
  } 
  int nr = 1;
  while(getline(file, tmp)){
    switch(nr){
        case 1: eng.push_back(tmp); break;
        case 2: pol.push_back(tmp); break;
    }
    nr++;
    if(nr > 2)
        nr = 1;
  }
  
  for(int i = 0; i < eng.size(); i++)
    words.insert(std::pair<std::string, std::string>(eng[i], pol[i]));

  std::map<std::string, std::string>::iterator it;
  it = words.begin();
    
  std::cout << "Witaj, zgadnij slowa\n\n";

  while(words.size() != 0 && tmp[0] != '@'){
    std::cout <<words.size() << "." << it->second << " : " ;
    getline(std::cin, tmp);
        if(it->first == tmp){
            std::cout << "Dobrze.\n";
            words.erase(it);
        }
        else{
            std::cout << "Zle.\n";
            std::cout << " Poprawna odpowiedz : " << it->first << std::endl;
        }
        ++it;
        if(it == words.end() && words.size() != 0)
            it = words.begin();
    }
    
    
    std::cout << "Koniec.\n";
}
