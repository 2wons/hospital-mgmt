#include <iostream>
#include <string>

#include "entity/Patient.h"

std::vector<string> Patient::to_row() const
{
    return {std::to_string(id), lastName, firstName, dob, address, std::to_string(balance)};
}

string Patient::fullName() const
{
    return lastName + ", " + firstName;
}