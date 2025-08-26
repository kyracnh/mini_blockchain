#include "CLI.hpp"
#include <iostream>

CLI::CLI() : blockchain(3) {

    Wallet defaultWallet;
    std::string defaultAddress = defaultWallet.getAddress();
    wallets[defaultAddress] = defaultWallet;

    blockchain.addTransaction(Transaction("network", defaultAddress, 100.0));

    blockchain.minePendingTransactions("network");

    std::cout << "✅ Default wallet created with address: " << defaultAddress 
              << " | Initial Balance: 100 BTC\n";
}

void CLI::createWallet() {
    Wallet wallet;
    std::string address = wallet.getAddress();
    wallets[address] = wallet;
    std::cout << "✅ Wallet created with address: " << address << std::endl;
}

void CLI::showWallets() {
    if (wallets.empty()) {
        std::cout << "⚠️ No wallets available.\n";
        return;
    }
    for (auto &w : wallets) {
        std::cout << "Wallet: " << w.first << " | Balance: " << blockchain.getBalance(w.first) << std::endl;
    }
}

void CLI::makeTransaction()
{
    std::string from, to;
    double amount;

    std::cout << "Sender address: ";
    std::cin >> from;
    std::cout << "Receiver address: ";
    std::cin >> to;
    std::cout << "Amount: ";
    std::cin >> amount;

    if (wallets.find(from) == wallets.end() || wallets.find(to) == wallets.end()) {
        std::cout << "⚠️ Invalid wallet address.\n";
        return;
    }

    blockchain.addTransaction(Transaction(from, to, amount));
    std::cout << "✅ Transaction added!\n";
}

void CLI::mineBlock() {
    blockchain.minePendingTransactions("miner-reward-wallet");
    std::cout << "⛏️ Block mined successfully!\n";
}

void CLI::showBlockchain() {
    blockchain.print();
}

void CLI::run() {
    int choice;
    while (true) {
        std::cout << "\n=== Blockchain CLI Menu ===\n";
        std::cout << "1. Create Wallet\n";
        std::cout << "2. Show Wallets\n";
        std::cout << "3. Make Transaction\n";
        std::cout << "4. Mine Block\n";
        std::cout << "5. Show Blockchain\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: createWallet(); break;
            case 2: showWallets(); break;
            case 3: makeTransaction(); break;
            case 4: mineBlock(); break;
            case 5: showBlockchain(); break;
            case 0: std::cout << "👋 Exiting...\n"; return;
            default: std::cout << "❌ Invalid choice.\n"; break;
        }
    }
}
