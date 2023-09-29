#include <iostream>
#include <string>

#include "entity/Patient.h"

bool Patient::operator==(const int& other) const
{
    return this->id == other;
}

std::vector<string> Patient::to_row() const
{
    return {std::to_string(id), lastName, firstName, dob, address, std::to_string(balance)};
}