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

    public:
        Blockchain(int diff = 4);

        void addBlock(const Block &newBlock);
        bool isChainValid() const;
        Block getLatestBlock() const;
        void printChain() const;
};

#endif