#include <iostream>
#include <string>

#include "entity/Patient.h"

void Patient::print()
{
    std::cout << id << ": " << lastName << ", " << dob << std::endl;
}

bool Patient::operator==(const int& other) const
{
    return this->id == other;
}

std::vector<string> Patient::to_row() const
{
    return {std::to_string(id), lastName, firstName, dob, address};
}