#pragma once

#include <string>
#include "json.hpp"

using std::string;
using namespace nlohmann;

class Patient
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Patient, id, name, lastName, firstName, dob, address);

public:
    Patient() {}

    Patient(int id, string name, string lastName, string firstName, string dob, string  address)
        : id(0), name(name), lastName(lastName), firstName(firstName), dob(dob), address(address) {};
    
    void print();
    
    int id;
    string name;
    string lastName;
    string firstName;
    string dob;
    string address;
};