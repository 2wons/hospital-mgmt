#pragma once

#include <string>
#include <vector>

#include "json.hpp"
#include "Entity.h"

using std::string;
using namespace nlohmann;

class Doctor : public Entity
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Doctor, id, lastName, firstName, departmentid, passkey);

    string passkey;

public:
    Doctor() {}

    std::vector<string> to_row() const;
    
    string lastName;
    string firstName;
    int departmentid;

    string getPasskey() const;
};