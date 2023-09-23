#pragma once

#include <string>
#include <vector>
#include "json.hpp"

using std::string;
using namespace nlohmann;

class Patient
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Patient, id, lastName, firstName, dob, address, billings);

public:
    Patient() {}

    bool operator==(const int& other) const;

    void print();

    std::vector<string> to_row() const;
    
    int id;
    string lastName;
    string firstName;
    string dob;
    string address;
    std::vector<string> billings;
};