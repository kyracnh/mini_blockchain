#include "Blockchain.hpp"

int main() {
    Blockchain bchain(4); // difficulty = 4

    bchain.addBlock(Block(1, "Alice pays Bob 10 coins", ""));
    bchain.addBlock(Block(2, "Bob pays Charlie 5 coins", ""));
    bchain.addBlock(Block(3, "Charlie pays Dave 2 coins", ""));

    std::cout << "Is blockchain valid? "
              << (bchain.isChainValid() ? "Yes" : "No") << std::endl;

    return 0;
}
