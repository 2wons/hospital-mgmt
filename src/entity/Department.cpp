#include "entity/Department.h"

std::vector<std::string> Department::to_row() const
{
    return {std::to_string(id), dptname};
}
