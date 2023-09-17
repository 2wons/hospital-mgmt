#pragma once

#include <string>
#include "json.hpp"

using std::string;
using namespace nlohmann;

class Doctor
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Doctor, lastName, firstName, dob, address, contact_no, department);

public:
    Doctor() {}

    Doctor(string lastName, string firstName, string dob, string address, string contact_no, string department)
        : lastName(lastName), firstName(firstName), dob(dob), address(address), contact_no(contact_no), department(department) {};
    
    //void print();
    
    string lastName;
    string firstName;
    string dob;
    string address;
    string contact_no;
    string department;
};