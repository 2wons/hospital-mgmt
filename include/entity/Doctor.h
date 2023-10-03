#pragma once

#include <string>
#include <vector>
#include <map>

#include "json.hpp"
#include "Entity.h"

using std::string;
using namespace nlohmann;

enum TimeSlotState
{
    AVAILABLE,
    BOOKED
};

// map TimeSlotState values to JSON as strings
NLOHMANN_JSON_SERIALIZE_ENUM( TimeSlotState, {
    {AVAILABLE, "AVAILABLE"},
    {BOOKED, "BOOKED"},
})

class Doctor : public Entity
{
public:
    Doctor() {}

    void initialize_schedule(string date);

    int book_appointment(string date);

    std::vector<string> to_row() const;

    bool hasDate(std::string date);
    
    string getPasskey() const;

    string fullName() const;

    int getDeptID() const;

    string  lastName;
    string  firstName;
    int     departmentid;
    int     numAppointments;

private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Doctor, id, lastName, firstName, numAppointments, departmentid, passkey, schedule);

    string passkey;

    std::map<string, std::map<int, TimeSlotState>> schedule;
};