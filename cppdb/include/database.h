#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>

//namespace groups everything to cppdb::, prevents name collisions
namespace cppdb{

//virtual fuction =>  no direct implementation
class IDatabase{
    public:
        IDatabase() = default;
        virtual ~IDatabase() = default;

        //return filesystem path of the database instance
        virtual std::string                             getDirectory(void) = 0;

        //KEY-VALUE USE CASES
        virtual void                                    setKeyValue(std::string key, std::string value) = 0;
        virtual std::string                             getKeyValue(std::string key) = 0;

        //MANAGEMENT FUNCTION
    
        static const std::unique_ptr<IDatabase>         createEmptyDB(std::string dbname);
        static const std::unique_ptr<IDatabase>         load(std::string dbname);
        virtual void                                    destroy() = 0;
    
};

}
#endif