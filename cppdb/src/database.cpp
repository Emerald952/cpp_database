#include <iostream>
#include <fstream>
#include <filesystem>

#include "include/database.h"
#include "include/extensions/extdatabase.h"

namespace fs = std::filesystem;

using namespace cppdb;
using namespace cppdbext;

// Hidden database: Impl class here
class EmbeddedDB::Impl : public IDatabase{
    public:
        Impl(std::string dbname, std::string fullpath);
        ~Impl();

        std::string                                 getDirectory(void);

        //KEY-VALUE USE CASES
        void                                        setKeyValue(std::string key, std::string value);
        std::string                                 getKeyValue(std::string key);

        //MANAGEMENT FUNCTION
        static const std::unique_ptr<IDatabase>      createEmptyDB(std::string dbname);

        static const std::unique_ptr<IDatabase>      load(std::string dbname);
        void                    destroy();
    private:
        std::string m_name;
        std::string m_fullpath;
    
};

EmbeddedDB::Impl::Impl(std::string dbname, std::string fullpath)
    : m_name(dbname), m_fullpath(fullpath)  
{
    ;
}


EmbeddedDB::Impl::~Impl(){

}


//MANAGEMENT FUNCTIONS
const std::unique_ptr<IDatabase> EmbeddedDB::Impl::createEmptyDB(std::string dbname){
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
    return std::make_unique<EmbeddedDB::Impl>(dbname, dbfolder);
}

const std::unique_ptr<IDatabase> EmbeddedDB::Impl::load(std::string dbname){
    std::string basedir(".cppdb");
    std::string dbfolder(basedir + "/" + dbname);
    return std::make_unique<EmbeddedDB::Impl>(dbname, dbfolder);

}

void EmbeddedDB::Impl::destroy(){
    if(fs::exists(m_fullpath)){
        fs::remove_all(m_fullpath);
    }
}

//INSTANCE USER FUNCTIONS

std::string EmbeddedDB::Impl::getDirectory(){
    return m_fullpath;
}

void EmbeddedDB::Impl::setKeyValue(std::string key, std::string value){
    //output file stream to write data 
    std::ofstream os;
    //std::ios::trunc->overwrite the file if it exist
    os.open(m_fullpath + "/" + key + "_string.kv", std::ios::out | std::ios::trunc);
    //write the value string into the file
    os << value;
    os.close();
}

std::string EmbeddedDB::Impl::getKeyValue(std::string key){
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


//High level Database class API implementation below:



//EMBEDDED DATABASE
EmbeddedDB::EmbeddedDB(std::string dbname, std::string fullpath) 
    : mImpl(std::make_unique<EmbeddedDB::Impl>(dbname,fullpath))
{
    
}

EmbeddedDB::~EmbeddedDB(){

}

const std::unique_ptr<IDatabase> EmbeddedDB::createEmptyDB(std::string dbname){
    return EmbeddedDB::Impl::createEmptyDB(dbname);
}

const std::unique_ptr<IDatabase> EmbeddedDB::load(std::string dbname){
    return EmbeddedDB::Impl::load(dbname);
}

void EmbeddedDB::destroy(){
    mImpl->destroy();
}

//INSTANCE USER FUNCTIONS

std::string EmbeddedDB::getDirectory(){
   return mImpl->getDirectory();
}

void EmbeddedDB::setKeyValue(std::string key, std::string value){
    mImpl->setKeyValue(key,value);
}

std::string EmbeddedDB::getKeyValue(std::string key){
    mImpl->getKeyValue(key);
}
