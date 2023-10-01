#include <iostream>
#include <string>

#include "entity/Patient.h"

std::vector<string> Patient::to_row() const
{
    return {std::to_string(id), lastName, firstName, dob, address, std::to_string(balance)};
}

string Patient::fullName() const
{
    return lastName + ", " + firstName;
}

string Patient::getInsurer() const
{
    return insurer;
}

void Patient::setInsurer(string insurer)
{
    this->insurer = insurer;
}

bool Patient::hasInsurer() const
{
    return !insurer.empty();
}

void Patient::owe(double cost)
{
    balance += cost;
}

void Patient::setVitals(int heartrate, int painlevel, float temp)
{
    this->heartrate = heartrate;
    this->painlevel = painlevel;
    this->temp = temp;
}