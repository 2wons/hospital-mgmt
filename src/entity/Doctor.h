#pragma once

#include <string>
#include <vector>
#include "json.hpp"

using std::string;
using namespace nlohmann;

class Doctor
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Doctor, id, lastName, firstName, departmentid);

public:
    Doctor() {}

    std::vector<string> to_row() const;
    
    int id;
    string lastName;
    string firstName;
    int departmentid;
};