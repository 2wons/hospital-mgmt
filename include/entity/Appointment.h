#pragma once

#include "Entity.h"
#include <string>
#include "json.hpp"

using namespace nlohmann;

class Appointment : public Entity
{
public:
    Appointment() = default;

    Appointment(const int& patientID, 
                const int& doctorID, 
                const std::string date,
                const int& hour, 
                const std::string subject);
    
    std::vector<std::string> to_row() const;

    std::vector<std::string> row_headers() const;

    int getDocID() const;

    int getPatientID() const;

private:
    int patientID;
    int doctorID;
    int hour;
    std::string date;
    std::string subject;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Appointment, id, patientID, doctorID, date, hour, subject);
};