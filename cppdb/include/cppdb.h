#ifndef CPPDB_H // Header Guard-> Checks if CPPDB_H has been defined before or not,  avoid duplicate definition
#define CPPDB_H

#include<string>

//CLIENT API FILES ONLY
#include "database.h"


namespace cppdb{

class CppDB{
    public:
        CppDB();
        //Calls Database
        static std::unique_ptr<IDatabase> createEmptyDB(std::string& dbname); 
        static std::unique_ptr<IDatabase> loadDB(std::string& dbname);
};

}
#endif