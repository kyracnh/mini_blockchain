#include "Blockchain.hpp"
#include <iostream>

Blockchain::Blockchain(int diff) : difficulty(diff) {
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
    std::vector<Transaction> genesisTxs;
    return Block(0, genesisTxs, "0", difficulty);
}

void Blockchain::addBlock(const Block& newBlock)
{
    try
    {
        if (chain.empty())
        {
            throw std::runtime_error("The blockchain is empty. Cannot add a new block.");
        }

        // if (newBlock.getPreviousHash() != getLatestBlock().getHash())
        // {
        //     throw std::runtime_error("The new block's previous hash does not match the latest block's hash.");
        // }
        Block block(newBlock.getIndex(), newBlock.getTransactions(), getLatestBlock().getHash(), difficulty);

        // block.mineBlock();
        chain.push_back(block);
    }

    catch (const std::exception &e)
    {
        std::cerr << "Error adding block: " << e.what() << std::endl;
    }
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

bool Blockchain::isChainValid() const {
    if (chain.empty())
    {
        throw std::runtime_error("The blockchain is empty. Cannot validate the chain.");
    }
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& current = chain[i];
        const Block& previous = chain[i - 1];

        if (current.getHash() != current.calculateHash())
            return false;

        if (current.getPreviousHash() != previous.getHash())
            return false;
    }
    return true;
}

void Blockchain::printChain() const {
    for (const auto& block : chain) {
        std::cout << "Block #" << block.getIndex() << "\n";

        std::cout << "Transactions:\n";
        for (const auto& tx : block.getTransactions()) {
            std::cout << "  " << tx.toString() << "\n";
        }
        
        std::cout << "Hash: " << block.getHash() << "\n";
        std::cout << "Prev Hash: " << block.getPreviousHash() << "\n";
        std::cout << "Timestamp: " << block.getTimestamp() << "\n\n";
    }
}
