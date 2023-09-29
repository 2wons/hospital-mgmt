#pragma once

#include <string>
#include <vector>
#include "json.hpp"
#include "Entity.h"

using std::string;
using namespace nlohmann;

class Patient : public Entity
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Patient, id, lastName, firstName, dob, address, balance);

public:
    Patient() {}

    std::vector<string> to_row() const;
    
    double balance;
    string lastName;
    string firstName;
    string dob;
    string address;
    std::vector<string> billings;
};