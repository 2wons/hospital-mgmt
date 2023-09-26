#include "entity/Record.h"
#include <iostream>

void Record::print()
{
    ///std::cout << id << ": " << PatientID << ", " << date << ", " << attendingPerson << std::endl;
}

bool Record::operator==(const int& other) const
{
    return this->id == other;
}

std::vector<string> Record::to_row() const
{
    return { 
        std::to_string(id), 
        std::to_string(patientID),
        std::to_string(departmentid),
        date,
        diagnosis,
        prescription,
        treatment 
    };
}
