
#pragma once

#include <vector>
#include <string>

class Entity
{
protected:
    int id;

public:

    int getID() const;

    void setID(const int& id);

    bool operator==(const int& other) const;

    virtual std::vector<std::string> to_row() const = 0;
};