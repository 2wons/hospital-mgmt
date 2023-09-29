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
        load();
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
    std::vector<T>& all()
    {
        return db;
    }

    typename std::vector<T>::iterator find(const int& id) 
    {
        return std::find(db.begin(), db.end(), id);
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

    int makeId()
    {
        int latest = db[db.size()-1].id;

        while (true)
        {
            latest++;
            if (find(latest) == db.end())
                break;
        }
        return latest;

    }

private:
    std::vector<T> db;
    std::string file;
};