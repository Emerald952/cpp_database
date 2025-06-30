#include "catch.hpp"
#include "cppdb.h"

TEST_CASE("Store and retrieve a value", "[setKeyValue, getKeyValue]"){
    //Story:
    //[Who] As a database user
    //[What] I need to store and retrieve a value with a simple name
    //[Value] So I can persist data for later use

    SECTION("Basic set and get"){
        std::string dbname;
        std::unique_ptr<cppdb::IDatabase> db(cppdb::CppDB::createEmptyDB(dbname));
        //We would be successful when
        //Retrieved value is the same as stored value
        std::string key("simplestring");
        std::string value("Some value");
        db->setKeyValue(key, value);
        REQUIRE(value == db->getKeyValue(key));

        db->destroy();
    }
}