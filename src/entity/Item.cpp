#include "entity/Item.h"

std::vector<string> Item::to_row() const
{
    return{Name, std::to_string(Quantity), std::to_string(Cost)};
}