#pragma once

#include <string>
#include <vector>

#include "json.hpp"

using std::string;
using namespace nlohmann;

class Item
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Item, id, Name, Quantity, Cost);

public:
    Item() {}

    std::vector<string> to_row() const;

    int id;
    string Name;
    int Quantity;
    double Cost;
};