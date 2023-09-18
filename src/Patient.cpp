#include <iostream>

#include "Patient.h"

void Patient::print()
{
    std::cout << id << ": " << lastName << ", " << dob << std::endl;
}