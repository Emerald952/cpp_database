#include <filesystem>
#include <string>

#include "test.h"
#include "cppdb.h"

//Shortens for std::filesystem to fs
namespace fs = std::filesystem;

//Testing whether the database creation logic actually creates the directory structure on the disk
TEST_CASE("Create a new empty database", "[createEmptyDB]"){
    //Story
    //  [Who]   a Database User
    //  [What]  to create a reference to a database
    //  [Value] to later store and retrieve data

    SECTION("Default settings"){
        //this create a db named myemptydb
        std::string dbname("myemptydb");
        //Call the database creation fuction through CppDB
        std::unique_ptr<cppdb::IDatabase> db(cppdb::CppDB::createEmptyDB(dbname));

        //Check if directory was created or not
        REQUIRE(fs::is_directory(fs::status(db->getDirectory())));

        //Iterate over the directory content, to ensure directory is empty
        const auto& p = fs::directory_iterator(db->getDirectory());
        REQUIRE(p == end(p));

        db->destroy();
        REQUIRE(!fs::exists(fs::status(db->getDirectory())));
    }
}

TEST_CASE("load an existing database", "[loadDB]"){
    //Story
    //  [Who]   a Database User
    //  [What]  to create a reference to an existing  database
    //  [Value] to later store and retrieve data


    SECTION("Default settings"){
        std::string dbname("myemptydb");
        std::unique_ptr<cppdb::IDatabase> db(cppdb::CppDB::createEmptyDB(dbname));

        std::unique_ptr<cppdb::IDatabase> db2(cppdb::CppDB::loadDB(dbname));

        REQUIRE(fs::is_directory(fs::status(db->getDirectory())));

        const auto& p = fs::directory_iterator(db->getDirectory());
        REQUIRE(p == end(p));

        db->destroy();
        REQUIRE(!fs::exists(fs::status(db->getDirectory())));
    }
    
}