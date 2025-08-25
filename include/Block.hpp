#ifndef BLOCK_HPP
#define BLOCK_HPP

#pragma once

#include <string>
#include <ctime>
#include "SHA256.hpp"

class Block
{
    private:
        int index;
        std::string timestamp;
        std::string data;
        std::string previousHash;
        std::string hash;

        std::string calculateHash() const;

    public:
        Block(int idx, const std::string &d, const std::string &prevHqsh);

        std::string getHash() const;
        std::string getPreviousHash() const;
        std::string getData() const;
        int getIndex() const;
        std::string getTimestamp() const;
};

#endif