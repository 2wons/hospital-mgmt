#include "entity/Appointment.h"

Appointment::Appointment(const int& patientID, 
                         const int& doctorID, 
                         const std::string date,
                         const int& hour,
                         const std::string subject)
{
    this->patientID = patientID;
    this->doctorID = doctorID;
    this->date = date;
    this->hour = hour;
    this->subject = subject;
}

int Appointment::getDocID() const
{
    return doctorID;
}

int Appointment::getPatientID() const
{
    return patientID;
}

std::vector<std::string> Appointment::to_row() const
{
    return {std::to_string(id),
            std::to_string(patientID),
            std::to_string(doctorID),
            date, subject};
}

std::vector<std::string> Appointment::row_headers() const
{
    return {
        "id",
        "patient_id",
        "doctor_id",
        "date",
        "subject"
    };
}