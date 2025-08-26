#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include <vector>
#include "Block.hpp"

class Blockchain
{
    private:
        std::vector<Block> chain;
        int difficulty;

        Block createGenesisBlock();
        std::vector<Transaction> pendingTransactions;

    public:
        Blockchain(int diff = 4);

        void addBlock(const Block &newBlock);
        bool isChainValid() const;
        Block getLatestBlock() const;
        void printChain() const;

        void addTransaction(const Transaction& tx);
        void minePendingTransactions(const std::string& minerAddress);
        double getBalance(const std::string& address) const;
        void print() const;
};

#endif