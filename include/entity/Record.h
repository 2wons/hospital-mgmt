#pragma once

#include <string>
#include <vector>
#include <map>
#include "json.hpp"
#include "Entity.h"

using std::string;
using namespace nlohmann;

class Record : public Entity
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Record, id, patientID, departmentid, date, diagnosis, prescriptions, treatment);

public:

    Record() = default;

    std::vector<string> to_row() const;

    std::vector<string> row_headers() const;

    std::map<string, int> getPrescriptions();
    
    int patientID;
    int departmentid;
    string date;
    string diagnosis;
    string treatment;

    std::map<string, int> prescriptions;
};