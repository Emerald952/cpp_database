#ifndef DATABASE_H
#define DATABASE_H

#include<string>

namespace cppdb{

class Database{
    public:
        //Constructir that takes dbname and its fullpath to represent an exisiting or new database
        Database(std::string dbname, std::string fullpath);

        //gets path to the database folder on disk
        std::string getDirectory(void);

        void setKeyValue(std::string key, std::string value);
        std::string getKeyValue(std::string key);

        // static fuction responsible for creating empty database folder 
        static Database createEmptyDB(std::string dbname);

        static Database load(std::string dbname);
        void destroy();
    protected:
        std::string m_name;
        std::string m_fullpath;
};

}
#endif