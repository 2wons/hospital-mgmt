#pragma once
#include <string>
#include <vector>

#include "json.hpp"
#include "Entity.h"

class Department : public Entity
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Department, id, dptname);

public:
    Department() {}

    std::vector<std::string> to_row() const;

    std::string dptname;
};