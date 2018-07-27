#include <sqlite3.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "planer.h"
#include <stdio.h>


void Menu(){
    std::cout << "Welcome in your planer\n";
    std::cout << "1.Create new planer.\n";
    std::cout << "2.Have exist planer.\n";
    std::cout << "3.Exit\n";
    std::cout << "choice: ";
}

std::string Create_statement(){
    std::string state = "CREATE TABLE PLANER("  \
                         "ACTION           TEXT    NOT NULL," \
                         "TIME            TEXT     NOT NULL," \
                         "PLACE        CHAR(50)," \
                         "DESCRIPTION         TXT );";
    return state;
}

std::string Insert_data(){
    std::string data;
    std::string action;
    std::string time;
    std::string place;
    std::string desc;
    std::cout << "Give the name of the action: ";
    Eatline();
    while(std::getline(std::cin, action)){
        Eatline();
        if(data.size() == 0){
            data = "INSERT INTO PLANER (ACTION,TIME,PLACE,DESCRIPTION) ";
            std::cout << "Set the time: ";
            std::cin >> time;
            std::cout << "Set the place: ";
            std::cin >> place;
            Eatline();
            std::cout << "Short description: ";
            std::getline(std::cin, desc);
            Eatline();
            std::string data2 = "VALUES ('";
            data2 += action + "','";
            data2 += time + "','";
            data2 += place + "','";
            data2 += desc + "');";
            data += data2;
        }
        else{
            std::cout << "Give the name of the action: ";
            std::getline(std::cin, action);
            Eatline();
            data += "INSERT INTO PLANER (ACTION,TIME,PLACE,DESCRIPTION) ";
            std::cout << "Set the time: ";
            std::cin >> time;
            std::cout << "Set the place: ";
            std::cin >> place;
            std::cout << "Short description: ";
            Eatline();
            std::getline(std::cin, desc);
            Eatline();
            std::string data2 = "VALUES ('";
            data2 += action + "','";
            data2 += time + "','";
            data2 += place + "','";
            data2 += desc + "');";
            data += data2;   
        }
        std::cout << "Do you want add new action y/n :";
        char ch; std::cin >> ch;
        if(ch == 'n'){
            break;
        }
        continue;
    }
        return data; 
}
