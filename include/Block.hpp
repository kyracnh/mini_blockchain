#ifndef BLOCK_HPP
#define BLOCK_HPP

#pragma once

#include <string>
#include <thread>
#include <iostream>
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
        int nonce;
        int difficulty;

        
    public:
        Block(int idx, const std::string& d, const std::string& prevHash, int diff);
        
        std::string calculateHash() const;
        std::string getHash() const;
        std::string getPreviousHash() const;
        std::string getData() const;
        int getIndex() const;
        std::string getTimestamp() const;

        void mineBlock();
};

#endif