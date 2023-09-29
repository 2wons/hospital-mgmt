#pragma once

#include <string>
#include <vector>

#include "json.hpp"
#include "Entity.h"

using namespace nlohmann;

class Message : public Entity
{
public:
    Message() = default;

    Message(int& senderID, int& receiverID, std::string& body);

    std::vector<std::string> to_row() const;

    int getReceiverID() const;


private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ORDERED(Message, id, senderID, receiverID, body);

    int senderID;
    int receiverID;
    std::string body;
};