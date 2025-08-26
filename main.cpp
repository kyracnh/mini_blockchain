// #include "Blockchain.hpp"
// #include "Block.hpp"
// #include "Transaction.hpp"
#include "CLI.hpp"

// int main() {
//     Blockchain myChain(2);

//     std::vector<Transaction> txs1 { Transaction("Ahmed", "Aboubaker", 10) };
//     std::vector<Transaction> txs2 { Transaction("Abderrahim", "Ahakki", 20) };
//     std::vector<Transaction> txs3 { Transaction("Ayoub", "sahebto", 30) };
//     std::vector<Transaction> txs4 { Transaction("Aboubaker", "madame", 40) };

//     myChain.addBlock(Block(1, txs1, myChain.getLatestBlock().getHash(), 2));
//     myChain.addBlock(Block(2, txs2, myChain.getLatestBlock().getHash(), 2));
//     myChain.addBlock(Block(3, txs3, myChain.getLatestBlock().getHash(), 2));
//     myChain.addBlock(Block(4, txs4, myChain.getLatestBlock().getHash(), 2));

//     myChain.printChain();

//     return 0;
// }

int main() {
    CLI cli;
    cli.run(); // Start the CLI loop
    return 0;
}