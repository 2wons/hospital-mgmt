#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>

#include "json.hpp"

using namespace nlohmann;

template <class T>
class Db
{
public:

    Db() {}

    Db(std::string jsondb) : file(jsondb) 
    { 
        load(); // if you want to disable file loading temporarily, comment this out
    }

    void load()
    {
        std::ifstream i(file);
        ordered_json j;
        i >> j;
        db = j.get<std::vector<T>>();
    }

    void save() 
    {
        std::ofstream o(file);
        ordered_json j = db;
        o << j.dump(4);
    }

    void add(T item) 
    { 
        db.push_back(item); 
    }

    /**
    * @brief retrieves all records in list
    * @return vector of records
    */
    std::vector<T> all()
    {
        return db;
    }

    T find() 
    {
        //implement
    }

    T remove() 
    {
        //implement
    }

    std::vector<T> where(std::function<bool(const T)> callback)
    {
        std::vector<T> results;

        for (auto v : db)
        {
            if (callback(v))
                results.push_back(v);
        }

        return results;
    }

private:
    std::vector<T> db;
    std::string file;
};