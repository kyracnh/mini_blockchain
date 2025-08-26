#ifndef WALLET_HPP
#define WALLET_HPP

#pragma once

#include <string>

class Wallet {
private:
    std::string publicKey;
    std::string privateKey;
    double balance;

    std::string generateRandomKey(int length);

public:
    Wallet();
    Wallet(const std::string& pub, const std::string& priv, double bal);

    std::string getPublicKey() const;
    std::string getPrivateKey() const;
    double getBalance() const;

    void addBalance(double amount);
    void subtractBalance(double amount);

    void saveToFile() const;
    static Wallet loadFromFile(const std::string& publicKey);
};

#endif
