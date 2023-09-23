#pragma once

#include "json.hpp"
#include <string>
#include <vector>

using std::string;
using namespace nlohmann;

class Record
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Record, id, patientID, departmentid, date, diagnosis, prescription, treatment);

public:

    Record() = default;
    
    void print();

    bool operator==(const int& other) const;

    std::vector<string> to_row() const;

    
    int id;
    int patientID;
    int departmentid;
    string date;
    string diagnosis;
    string prescription;
    string treatment;
};