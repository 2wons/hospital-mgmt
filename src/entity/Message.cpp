#include "entity/Message.h"
using std::to_string;

Message::Message(int& senderID, int& receiverID, std::string& body)
{
    this->senderID = senderID;
    this->receiverID = receiverID;
    this->body = body;
}

std::vector<std::string> Message::to_row() const
{
    return {to_string(id), to_string(senderID), to_string(receiverID), body };
}

int Message::getReceiverID() const
{
    return receiverID;
}