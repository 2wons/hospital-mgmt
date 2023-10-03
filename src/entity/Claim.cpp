#include "entity/Claim.h"
#include "Date.h"


Claim::Claim()
{
    this->setStatus(ClaimStatus::Pending);
}

Claim::Claim(Record record, double cost, string insurer)
{
    string service;
    this->addService(record.treatment);

    auto prescs = record.getPrescriptions();

    // write prescriptions and their quantity
    for (const auto& item: prescs)
    {
        service = item.first + " x" + std::to_string(item.second);
        this->addService(service);
    }

    this->patientid  = record.patientID;
    this->to_insurer = insurer;
    this->totalCost = cost;
    this->date = Date().getDate(TODAY);
    this->date_last_updated = Date().getDate(TODAY);
    this->setStatus(ClaimStatus::Pending);

}

void Claim::approve()
{
    this->setStatus(ClaimStatus::Approved);
    this->date_last_updated = Date().getDate(TODAY);
}

void Claim::deny()
{
    this->setStatus(ClaimStatus::Denied);
    this->date_last_updated = Date().getDate(TODAY);
}

void Claim::addService(string service)
{
    this->for_services.push_back(service);
}

double Claim::getCost() const
{
    return totalCost;
}

void Claim::setCost(const double& cost)
{
    this->totalCost = cost;
}

int Claim::getPatientId() const
{
    return this->patientid;
}

ClaimStatus Claim::getStatus() const
{
    return status;
}

void Claim::setStatus(ClaimStatus status)
{
    this->status = status;
}

std::string Claim::status_str() const
{
    switch (status)
    {
        case Pending:   return "Pending";
        case Approved:  return "Approved";
        case Denied:    return "Denied";
    }

    return "";
}

std::vector<string> Claim::to_row() const
{
    using std::to_string;
    string services_str;
    for (auto& service : for_services) 
        services_str += service + "\n";
    

    return {
        to_string(id),
        to_string(patientid),
        to_insurer,
        services_str,
        date_last_updated,
        to_string(totalCost),
        status_str()
    };
}

std::vector<string> Claim::row_headers() const
{
    return {
        "id",
        "patient_id",
        "to_insurer",
        "for_services",
        "date_last_updated",
        "totalCost",
        "status"
    };
}

std::string Claim::service_str() const
{
    string service_s;
    // write to string
    for (const auto& service : for_services)
    {
        service_s += service + "\n";
    }

    return service_s;
}

Table Claim::toTable() const
{
    using std::to_string;

    Table table;
    table.add_row({"id",                std::to_string(this->getID())});
    table.add_row({"patientid",         std::to_string(patientid)});
    table.add_row({"to_insurer",        to_insurer});
    table.add_row({"for_services",      service_str()});
    table.add_row({"date_last_updated", date_last_updated});
    table.add_row({"totalCost",         std::to_string(totalCost)});
    table.add_row({"status",            status_str()});

    return table;
}