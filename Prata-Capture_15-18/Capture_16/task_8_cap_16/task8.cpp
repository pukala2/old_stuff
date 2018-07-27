#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>


int main()
{    
     std::string tmp;
     std::list<std::string> bolek;
     std::list<std::string> lolek;   

     std::cout<<"Podaj imiona listy Bolka, <koniec> aby zakonczyc : ";

     while(std::cin >> tmp){
         if(tmp == "@")
             break;
         std::cout<<"Podaj imiona listy Bolka, <@> aby zakonczyc : ";
         bolek.push_front(tmp);
     }

     std::cout<<"Podaj imiona listy Lolka, <koniec> aby zakonczyc : ";

     while(std::cin >> tmp && tmp != "koniec"){
         if(tmp == "@")
             break;
         std::cout<<"Podaj imiona listy Lolka, <@> aby zakonczyc : ";
         lolek.push_front(tmp);
     }

     std::cout<<"\nLista gosci Bolka : ";

     std::list<std::string>::iterator it;
     for(it = bolek.begin(); it != bolek.end(); it ++)
         std::cout<<*it<<" ";

     std::cout<<"\nLista gosci Lolka : ";

     for(it = lolek.begin(); it != lolek.end(); it ++)
         std::cout<<*it<<" ";

     std::cout<<"\nListy po dodaniu do siebie i po posortowaniu : ";
     bolek.merge(lolek);
     bolek.sort();
     bolek.unique();

     for(it = bolek.begin(); it != bolek.end(); it ++)
         std::cout<<*it<<" ";


     return 0;
}
