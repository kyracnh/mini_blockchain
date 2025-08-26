#include "Transaction.hpp"
#include <sstream>
#include <random>

Transaction::Transaction(const std::string& senderKey, const std::string& receiverKey, double amt)
    : sender(senderKey), receiver(receiverKey), amount(amt)
{
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&now_time);
    timestamp.pop_back();

    transactionID = generateTransactionID();
}

std::string Transaction::generateTransactionID() const {
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);
    std::string id;
    for (int i = 0; i < 16; ++i)
        id += chars[dis(gen)];
    return id;
}

std::string Transaction::getTransactionID() const { return transactionID; }
std::string Transaction::getSender() const { return sender; }
std::string Transaction::getReceiver() const { return receiver; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getTimestamp() const { return timestamp; }

std::string Transaction::toString() const
{
    std::stringstream ss;
    ss << transactionID << "|" << sender << "|" << receiver << "|" << amount << "|" << timestamp;
    return ss.str();
}
