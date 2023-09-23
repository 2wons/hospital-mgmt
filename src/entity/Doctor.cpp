#include "Doctor.h"

std::vector<string> Doctor::to_row() const
{
    return{std::to_string(id), lastName, firstName, std::to_string(departmentid)};
}