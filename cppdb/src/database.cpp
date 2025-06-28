#include "include/database.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace cppdb;

//intialize dbname and fullpath
Database::Database(std::string dbname, std::string fullpath) 
    : m_name(dbname), m_fullpath(fullpath){
    
}

//MANAGEMENT FUNCTIONS

//static function that creates a new empty database
Database Database::createEmptyDB(std::string dbname){
    std::string basedir(".cppdb");

    //checks if basedir exist, or not
    if(!fs::exists(basedir)){
        fs::create_directory(basedir);
    }

    std::string dbfolder(basedir + "/" + dbname);

    //checks if dbfolder exist, or not
    if(!fs::exists(dbfolder)){
        fs::create_directory(dbfolder);
    }

    return Database(dbname, dbfolder);

}

Database Database::load(std::string dbname){
    std::string basedir(".cppdb");
    std::string dbfolder(basedir + "/" + dbname);
    return Database(dbname, dbfolder);

}

void Database::destroy(){
    if(fs::exists(m_fullpath)){
        fs::remove_all(m_fullpath);
    }
}

//INSTANCE USER FUNCTIONS

std::string Database::getDirectory(){
    return m_fullpath;
}

void Database::setKeyValue(std::string key, std::string value){
    //output file stream to write data 
    std::ofstream os;
    //std::ios::trunc->overwrite the file if it exist
    os.open(m_fullpath + "/" + key + "_string.kv", std::ios::out | std::ios::trunc);
    //write the value string into the file
    os << value;
    os.close();
}

std::string Database::getKeyValue(std::string key){
    //opens the file for reading
    std::ifstream t(m_fullpath + "/" + key + "_string.kv");
    std::string value;
/*
    //this will only read until the first space so we are not using this
    t >> value;
    t.close();
*/
    //This moves the file pointer to the end to determine size.
    t.seekg(0, std::ios::end);
    //Now that we're at the end of file tellg get the current pos and reserve enough memory to fit the entire file
    value.reserve(t.tellg());
    //Move file pointer back to start
    t.seekg(0, std::ios::beg);

    //From start of t to EOF this iterates and assign it to value
    value.assign((std::istreambuf_iterator<char>(t)), 
                    std::istreambuf_iterator<char>()); 
    return value;
}
