// Checks if CPPDB_H has been defined before or not
//Header Guard, avoid duplicate definition
#ifndef CPPDB_H
#define CPPDB_H

#include<string>
#include "database.h"

class CppDB{
    public:
        CppDB();
        //Calls Database
        static Database createEmptyDB(std::string& dbname); 
        static Database loadDB(std::string& dbname);
};

#endif