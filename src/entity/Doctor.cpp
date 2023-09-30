#include "entity/Doctor.h"

std::vector<string> Doctor::to_row() const
{
    return{std::to_string(id), lastName, firstName, std::to_string(departmentid)};
}

string Doctor::getPasskey() const
{
    return passkey;
}

string Doctor::fullName() const
{
    return "(" + std::to_string(id) + ") Dr. " + firstName + " " + lastName;
}

void Doctor::initialize_schedule(string date)
{
    for (int i = 13; i <= 19; i++) 
    {
        schedule[date][i] = AVAILABLE;
    }
}

int Doctor::book_appointment(string date) 
{
    if (!hasDate(date)) {
        initialize_schedule(date);
    }

    for (int i = 13; i <= 19; i++) 
    {
        if (!schedule[date][i]) {
            schedule[date][i] = BOOKED;
            return i;
        }
    }
    // If all slots are booked, return -1
    return -1;
}

bool Doctor::hasDate(string date)
{
    if (schedule.empty()) {
        return false;
    }
    return (schedule.find(date) != schedule.end());
}