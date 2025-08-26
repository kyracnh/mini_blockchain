#ifndef CLI_HPP
#define CLI_HPP

#pragma once

#include "Blockchain.hpp"
#include "Wallet.hpp"
#include <map>

class CLI
{
    private:
        Blockchain blockchain;
        std::map<std::string, Wallet> wallets;

        void createWallet();
        void showWallets();
        void makeTransaction();
        void mineBlock();
        void showBlockchain();

    public:
        CLI();
        void run();
};

#endif
