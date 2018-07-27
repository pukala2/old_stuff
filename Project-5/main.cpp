#include <stdio.h>
#include <iostream>
#include <sqlite3.h> 
#include "planer.h"
#include <string>
#include <cstring>
#include <cstdlib>

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    char choice;
   
    Menu();
    while(std::cin >> choice){ 

        switch(choice){
   
        case '1':{
            std::cout << "Enter the name your planer:";
            std::string name;
            std::cin >> name;
            std::cout << name << std::endl;
            name += ".db";
//create database
            rc = sqlite3_open(name.c_str(), &db);
            if( rc ) {
      	        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
     	        exit(EXIT_FAILURE);
   		    }
		    else
      	        fprintf(stdout, "Opened database successfully\n");
//create sql statement   
            sql = Create_statement();
//execute sql statement
            rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);
            if(rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
            }
		    sql = Insert_data();
		    rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

   		    if( rc != SQLITE_OK ){
      		    fprintf(stderr, "SQL error: %s\n", zErrMsg);
      		    sqlite3_free(zErrMsg);
   		    } 
		    else
			    fprintf(stdout, "Records created successfully\n");
		    Menu();
            break;
        }

        case '2':{
            std::cout << "Enter the name your planer: ";
            std::string nam;
            std::cin >> nam;
            nam += ".db";
            std::cout << '\n';
            const char* data = "Callback function called";
            rc = sqlite3_open(nam.c_str(), &db);
            if( rc ) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                exit(EXIT_FAILURE);
            }
// create statement
            sql = "select * from PLANER";
// exequte statement
            rc = sqlite3_exec(db, sql.c_str(), Callback, (void*)data, &zErrMsg);
            if( rc != SQLITE_OK ) {
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
            }
            char add;
            std::cout << "Press\n1.Add action\n2.Delete action\n3.back\n";
            while(std::cin >> add && add != '3'){
            switch(add){
                    case '1':{ 
		            sql = Insert_data();
		            rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

   		            if( rc != SQLITE_OK ){
      		            fprintf(stderr, "SQL error: %s\n", zErrMsg);
      		            sqlite3_free(zErrMsg);
   		            } 
		            else
			            fprintf(stdout, "Records created successfully\n");
                    std::cout << "Press\n1.Add action\n2.Delete action\n3.back\n";

                    break;
                    }
                    case '2':{
                        std::cout << "Press ACTION to delete: ";
                        std::string del;
                        std::getline(std::cin, del);
                        Eatline();
                        del += "';";
                        sql = "DELETE from PLANER where ACTION = '";
                        sql += del;
                        std::cout << sql << std::endl;
                        rc = sqlite3_exec(db, sql.c_str(), Callback, (void*)data, &zErrMsg);
                        if( rc != SQLITE_OK ) {
                            fprintf(stderr, "SQL error: %s\n", zErrMsg);
                            sqlite3_free(zErrMsg);
                        } 
                        else {
                            fprintf(stdout, "Operation done successfully\n");
                        }
                        std::cout << "Press\n1.Add action\n2.Delete action\n3.back\n";
                        break;
                    }
            }
            }
            Menu();
            break;
            }
        
        case '3':{
            std::cout << "Bye bye.\n";
            exit(0);    
            }
        }
    }
    sqlite3_close(db);    
}
