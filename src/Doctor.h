#pragma once

#include <string>
#include "json.hpp"

using std::string;
using namespace nlohmann;

class Doctor
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Doctor, lastName, firstName, contact_no, department);

public:
    Doctor() {}

    Doctor(int id, string lastName, string firstName, string contact_no, string department)
        : id(id), 
        lastName(lastName), 
        firstName(firstName), 
        contact_no(contact_no), 
        department(department) {};
    
    //void print();
    
    int id;
    string lastName;
    string firstName;
    string contact_no;
    string department;
};