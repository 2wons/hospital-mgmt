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
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Patient, id, lastName, firstName, dob, address, insurer, balance);

    string insurer;

public:
    Patient() {}

    string getInsurer() const;
    void setInsurer(string insurer);

    bool hasInsurer() const;

    void owe(double cost);

    std::vector<string> to_row() const;

    string fullName() const;
    
    double balance;
    string lastName;
    string firstName;
    string dob;
    string address;
};