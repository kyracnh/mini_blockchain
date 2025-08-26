#include "Block.hpp"
#include <sstream>
#include <chrono>

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& prevHash, int diff)
    : index(idx), transactions(txs), previousHash(prevHash), nonce(0), difficulty(diff) {
    
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&now_time);
    timestamp.pop_back();
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << previousHash << nonce;
    for (const auto& tx : transactions) {
        ss << tx.getSender() << tx.getReceiver() << tx.getAmount();
    }
    return sha256(ss.str());
}

void Block::mineBlock() {
    std::string target(difficulty, '0');
    int printInterval = 1000;
    while (hash.substr(0, difficulty) != target)
    {
        nonce++;
        hash = calculateHash();

        if (nonce % printInterval == 0)
        {
            std::cout << "\rMining block " << index << ": " << hash << " (nonce: " << nonce << ")" << std::flush;
        }
    }
    std::cout << std::endl << "Block mined: " << hash << " with nonce: " << nonce << std::endl;
}

std::string Block::getHash() const { return hash; }
std::string Block::getPreviousHash() const { return previousHash; }
const std::vector<Transaction>& Block::getTransactions() const {return transactions;}
int Block::getIndex() const { return index; }
std::string Block::getTimestamp() const { return timestamp; }
