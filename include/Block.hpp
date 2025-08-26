#ifndef BLOCK_HPP
#define BLOCK_HPP

#pragma once

#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <ctime>
#include "SHA256.hpp"
#include "Transaction.hpp"

class Block
{
private:
    int index;
    std::string timestamp;
    std::vector<Transaction> transactions;
    std::string previousHash;
    std::string hash;
    int nonce;
    int difficulty;

public:
    Block(int idx, const std::vector<Transaction>& txs, const std::string& prevHash, int diff);
    const std::vector<Transaction>& getTransactions() const;

    std::string calculateHash() const;
    std::string getHash() const;
    std::string getPreviousHash() const;
    int getIndex() const;
    std::string getTimestamp() const;

    void mineBlock();
};

#endif
