#include <iostream>
#include "cxxopts.hpp"
#include "cppdb.h"
using namespace std;

cxxopts::Options options("cppdb-cli", "CLI for cppdb");

void printUsage(){
    cout << "Whoops bad config!!!" << endl;
}

int main(int argc, char* argv[]) {
    options.add_options()
        ("c, create", "Create a DB")
        ("d, destroy", "Destroy a DB")
        ("s, set", "Set a key in DB")
        ("g, get", "Get a key from DB")
        ("n, name", "Database name (required)", cxxopts::value<string>())
        ("k, key", "key to set/get", cxxopts::value<string>())
        ("v, value", "Value to set", cxxopts::value<string>())
    ;
    auto result = options.parse(argc,argv);

    if(result.count("c")){
        if(!result.count("n")){
            cout<<"Specify database name with -n <name> "<<endl;
            printUsage();
            return 1;
        }
        //Create database
        string dbname(result["n"].as<string>());
        Database db(CppDB::createEmptyDB(dbname));
        return 0;
    }
    if(result.count("d")){
        if(!result.count("n")){
            cout<<"Specify database name with -n <name> "<<endl;
            printUsage();
            return 1;
        }
        //Destroy database
        string dbname(result["n"].as<string>());
        Database db(CppDB::loadDB(dbname));
        db.destroy();
        return 0;
    }
    if(result.count("s")){
        if(!result.count("n")){
            cout<<"Specify database name with -n <name> "<<endl;
            printUsage();
            return 1;
        }
        if(!result.count("k")){
            cout<<"Specify key with -k <name> "<<endl;
            printUsage();
            return 1;
        }
        if(!result.count("v")){
            cout<<"Specify value with -v <name> "<<endl;
            printUsage();
            return 1;
        }
        //Set key values in database
        string dbname(result["n"].as<string>());
        string k(result["k"].as<string>());
        string v(result["v"].as<string>());
        Database db(CppDB::loadDB(dbname));
        db.setKeyValue(k,v);
        return 0;
    }
    if(result.count("g")){
        if(!result.count("n")){
            cout<<"Specify database name with -n <name> "<<endl;
            printUsage();
            return 1;
        }
        if(!result.count("k")){
            cout<<"Specify key with -k <name> "<<endl;
            printUsage();
            return 1;
        }
        
        //Get key values from database
        string dbname(result["n"].as<string>());
        string k(result["k"].as<string>());
        Database db(CppDB::loadDB(dbname));
        cout<<db.getKeyValue(k)<<endl;
        return 0;
    }

    cout<<"No command specified!!!"<<endl;
    
    printUsage();
    return 1;
}
