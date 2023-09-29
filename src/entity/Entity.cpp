#include "entity/Entity.h"

int Entity::getID() const
{
    return id;
}

void Entity::setID(const int& id)
{
    this->id = id;
}

bool Entity::operator==(const int& other) const
{
    return this->id == other;
}