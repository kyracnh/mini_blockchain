#include "Block.hpp"
#include <sstream>
#include <chrono>

Block::Block(int idx, const std::string& d, const std::string& prevHash)
    : index(idx), data(d), previousHash(prevHash)
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

std::string Block::getHash() const { return hash; }
std::string Block::getPreviousHash() const { return previousHash; }
std::string Block::getData() const { return data; }
int Block::getIndex() const { return index; }
std::string Block::getTimestamp() const { return timestamp; }
