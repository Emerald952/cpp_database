#ifndef EXTDATABASE_H
#define EXTDATABASE_H

#include <memory>
#include "../database.h"

namespace cppdbext{

using namespace cppdb;

class EmbeddedDB : public IDatabase{
    public:
        //Constructor that takes dbname and its fullpath to represent an exisiting or new database
        EmbeddedDB(std::string dbname, std::string fullpath);
        ~EmbeddedDB();

        std::string             getDirectory(void);

        //KEY-VALUE USE CASES
        void                    setKeyValue(std::string key, std::string value);
        std::string             getKeyValue(std::string key);

        //MANAGEMENT FUNCTION
        static  const std::unique_ptr<IDatabase>               createEmptyDB(std::string dbname);
        static  const std::unique_ptr<IDatabase>               load(std::string dbname);
        void                    destroy();

        
    
    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
};

}
#endif