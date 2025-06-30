#include "cppdb.h"
#include "include/extensions/extdatabase.h"

using namespace cppdb;
using namespace cppdbext;

CppDB::CppDB(){
    
}

// Asks Database class to do work, then gives the result back to the caller
std::unique_ptr<IDatabase> CppDB::createEmptyDB(std::string &dbname){
    return EmbeddedDB::createEmptyDB(dbname);
}

std::unique_ptr<IDatabase> CppDB::loadDB(std::string &dbname){
    return EmbeddedDB::load(dbname);
}