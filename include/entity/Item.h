#pragma once

#include <string>
#include <vector>

#include "json.hpp"
#include "Entity.h"

using std::string;
using namespace nlohmann;

class Item : public Entity
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Item, id, Name, Quantity, Cost);

public:
    Item() {}

    std::vector<string> to_row() const;

    string Name;
    int Quantity;
    double Cost;
};