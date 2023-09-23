#pragma once
#include <string>
#include <vector>
#include "json.hpp"

class Department
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Department, id, dptname);

public:
    Department() {}

    bool operator==(const int& other) const;

    std::vector<std::string> to_row() const;

    int id;
    std::string dptname;
};