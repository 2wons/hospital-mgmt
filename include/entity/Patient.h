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
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(
        Patient, 
        id, 
        lastName, 
        firstName, 
        dob, 
        address, 
        insurer,
        heartrate,
        painlevel,
        temp, 
        balance);

    string insurer;

public:
    Patient() {}

    string getInsurer() const;
    void setInsurer(string insurer);

    bool hasInsurer() const;

    void setVitals(int heartrate, int painlevel, float temp);

    void owe(double cost);

    std::vector<string> to_row() const;

    string fullName() const;


    
    double balance;
    string lastName;
    string firstName;
    string dob;
    string address;

    //vitals
    int heartrate;
    int painlevel;
    float temp;
};