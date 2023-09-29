#include "entity/Doctor.h"

std::vector<string> Doctor::to_row() const
{
    return{std::to_string(id), lastName, firstName, std::to_string(departmentid)};
}

string Doctor::getPasskey() const
{
    return passkey;
}

string Doctor::fullName() const
{
    return "(" + std::to_string(id) + ") Dr. " + firstName + " " + lastName;
}