#include "entity/Record.h"
#include <iostream>

std::vector<string> Record::to_row() const
{
    // retrieve items and make them into a string with format "ItemName - x<Quantity>"
    std::string itemsStr;
    for (auto& [name, quantity] : prescriptions)
    {
        itemsStr += name + " - x" + std::to_string(quantity) + "\n";
    }
    
    return { 
        std::to_string(id), 
        std::to_string(patientID),
        std::to_string(departmentid),
        date,
        diagnosis,
        itemsStr,
        treatment 
    };
}


std::map<string, int> Record::getPrescriptions()
{
    return prescriptions;
}