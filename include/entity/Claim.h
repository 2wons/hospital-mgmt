#pragma once

#include "Entity.h"
#include "Record.h"
#include "json.hpp"
#include "tabulate.hpp"

using std::string;
using namespace nlohmann;
using namespace tabulate;

enum ClaimStatus
{
    Pending,
    Approved,
    Denied
};

// map Claimstatus values to JSON as strings
NLOHMANN_JSON_SERIALIZE_ENUM( ClaimStatus, {
    {Pending, "pending"},
    {Approved, "approved"},
    {Denied, "denied"},
})

class Claim : public Entity
{
public:
    Claim();

    Claim(Record record, double cost, string insurer);

    void approve();

    void deny();
    
    void addService(string service);

    double getCost() const;
    void setCost(const double& cost);

    int getPatientId() const;

    ClaimStatus getStatus() const;
    void setStatus(ClaimStatus status);

    std::string status_str() const;

    std::vector<string> to_row() const;

    std::vector<string> row_headers() const;

    Table toTable() const;

    std::string service_str() const;

private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(
        Claim, 
        id, 
        patientid, 
        to_insurer, 
        for_services, 
        date_last_updated,
        totalCost,
        status );
    
    int patientid;
    string to_insurer;
    string date;
    string date_last_updated;
    double totalCost;
    std::vector<string> for_services;
    ClaimStatus status;

};