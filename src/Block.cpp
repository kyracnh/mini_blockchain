#include "Block.hpp"
#include <sstream>
#include <chrono>

Block::Block(int idx, const std::string& d, const std::string& prevHash, int diff)
    : index(idx), timestamp(""), data(d), previousHash(prevHash), hash(""), nonce(0), difficulty(diff)
{
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&now_time);
    timestamp.pop_back();
    hash = calculateHash();
}



std::string Block::calculateHash() const
{
    std::stringstream ss;
    ss << index << timestamp << data << previousHash;
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

        // std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::cout << std::endl << "Block mined: " << hash << " with nonce: " << nonce << std::endl;
    }
}

std::string Block::getHash() const { return hash; }
std::string Block::getPreviousHash() const { return previousHash; }
std::string Block::getData() const { return data; }
int Block::getIndex() const { return index; }
std::string Block::getTimestamp() const { return timestamp; }
