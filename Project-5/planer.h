#include <sqlite3.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

static int Callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
    for(i = 0; i<argc; i++) {
    	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}  

void Menu();
std::string Create_statement();
std::string Insert_data();
inline void Eatline(){ while(std::cin.get() != '\n')continue; } 
