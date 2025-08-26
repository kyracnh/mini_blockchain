#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#pragma once

#include <string>
#include <chrono>
#include <ctime>

class Transaction
{
    private:
        std::string transactionID;
        std::string sender;
        std::string receiver;
        double amount;
        std::string timestamp;

        std::string generateTransactionID() const;

    public:
        Transaction(const std::string& senderKey, const std::string& receiverKey, double amt);

        std::string getTransactionID() const;
        std::string getSender() const;
        std::string getReceiver() const;
        double getAmount() const;
        std::string getTimestamp() const;

        std::string toString() const;
};

#endif