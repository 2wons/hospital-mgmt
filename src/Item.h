#pragma once

#include <string>
#include "json.hpp"

using std::string;
using namespace nlohmann;

class Item
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Item, Name, Quantity, Price);

public:
    Item() {}

    Item(string Name, int Quantity, double Price)
        : Name(Name), Quantity(Quantity), Price(Price) {};
    
    string Name;
    int Quantity;
    double Price;
};