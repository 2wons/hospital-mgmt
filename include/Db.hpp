#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <thread>
#include <chrono>

#include "json.hpp"
#include "boolinq.h"

using namespace nlohmann;

template <class T>
class Db
{
public:

    Db() {}

    Db(std::string jsondb) : file(jsondb) 
    { 
        try
        {
            load();
        } 
        catch (const json::exception& e)
        {
            std::cerr << e.what() << "\n"
                      << "in-> " 
                      << file << "\n";

            std::this_thread::sleep_for(
                std::chrono::seconds(5));
            exit(1);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << "\n"
                      << "in-> " 
                      << file << "\n";

            std::this_thread::sleep_for(
                std::chrono::seconds(5));
            exit(1);
        }
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
        item.setID(makeId());
        db.push_back(item); 
    }

    auto query()
    {
        return boolinq::from(db);
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

    void remove(const int& id) 
    {
        std::remove(db.begin(), db.end(), id);
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
        if (db.empty())
            return 1;
        
        int latest = db[db.size()-1].getID();

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