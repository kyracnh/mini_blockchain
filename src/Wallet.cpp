#include "Wallet.hpp"
// #pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>

namespace fs = std::filesystem;

std::string Wallet::generateRandomKey(int length)
{
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);
    std::string key;
    for (int i = 0; i < length; ++i) {
        key += chars[dis(gen)];
    }
    return key;
}

Wallet::Wallet() {
    publicKey = generateRandomKey(16);
    privateKey = generateRandomKey(32);
    balance = 0.0;
}

Wallet::Wallet(const std::string& pub, const std::string& priv, double bal) 
    : publicKey(pub), privateKey(priv), balance(bal) {}

std::string Wallet::getPublicKey() const { return publicKey; }
std::string Wallet::getPrivateKey() const { return privateKey; }
double Wallet::getBalance() const { return balance; }

void Wallet::addBalance(double amount) { balance += amount; }
void Wallet::subtractBalance(double amount) { balance -= amount; }

void Wallet::saveToFile() const {
    fs::create_directories("wallets");
    std::ofstream file("wallets/" + publicKey + ".txt");
    if (file.is_open()) {
        file << publicKey << "\n" << privateKey << "\n" << balance << "\n";
        file.close();
        std::cout << "Wallet saved: " << publicKey << std::endl;
    } else {
        std::cerr << "Error saving wallet!" << std::endl;
    }
}

// Load wallet from file
Wallet Wallet::loadFromFile(const std::string& pubKey)
{
    std::ifstream file("wallets/" + pubKey + ".txt");
    if (!file.is_open()) {
        throw std::runtime_error("Wallet not found: " + pubKey);
    }
    std::string pub, priv;
    double bal;
    file >> pub >> priv >> bal;
    file.close();
    return Wallet(pub, priv, bal);
}
