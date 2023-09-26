#include "entity/Entity.h"

int Entity::getID() const
{
    return id;
}

bool Entity::operator==(const int& other) const
{
    return this->id == other;
}