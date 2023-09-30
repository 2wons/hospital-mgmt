#include "entity/Item.h"

std::vector<string> Item::to_row() const
{
    return{std::to_string(id), Name, std::to_string(Quantity), std::to_string(Cost)};
}

void Item::add(const int& quantity)
{
    this->Quantity += quantity;
}

void Item::pull(const int& quantity)
{
    this->Quantity -= quantity;
}

bool Item::canPull() const
{
    return this->Quantity > 0;
}