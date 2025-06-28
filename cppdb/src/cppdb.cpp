#include "cppdb.h"

using namespace cppdb;

CppDB::CppDB(){
    
}

// Asks Database class to do work, then gives the result back to the caller
Database CppDB::createEmptyDB(std::string &dbname){
    return Database::createEmptyDB(dbname);
}

Database CppDB::loadDB(std::string &dbname){
    return Database::load(dbname);
}