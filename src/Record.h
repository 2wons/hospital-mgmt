#pragma once

#include "json.hpp"
#include <string>

using std::string;
using namespace nlohmann;

class Record
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Record, id, patientID, date, diagnosis, prescription, treatment, attendingPerson);

public:

    Record() {}
    
    void print();
    
    int id;
    int patientID;
    string date;
    string diagnosis;
    string prescription;
    string treatment;
    string attendingPerson;
};