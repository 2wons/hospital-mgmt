#include "Department.h"

bool Department::operator==(const int& other) const
{
    return id == other;
}

std::vector<std::string> Department::to_row() const
{
    return {std::to_string(id), dptname};
}
