// #include "Blockchain.hpp"

// int main() {
//     Blockchain bchain(4); // difficulty = 4

//     bchain.addBlock(Block(1, "Alice pays Bob 10 coins", ""));
//     bchain.addBlock(Block(2, "Bob pays Charlie 5 coins", ""));
//     bchain.addBlock(Block(3, "Charlie pays Dave 2 coins", ""));

//     std::cout << "Is blockchain valid? "
//               << (bchain.isChainValid() ? "Yes" : "No") << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <string>

// // Make sure your sha256 function is declared somewhere
// std::string sha256(const std::string& input);

// int main() {
//     // Test 1: simple text
//     std::string text1 = "Hello Blockchain";
//     std::cout << "Input: " << text1 << std::endl;
//     std::cout << "SHA256: " << sha256(text1) << std::endl << std::endl;

//     // Test 2: empty string
//     std::string text2 = "";
//     std::cout << "Input: (empty string)" << std::endl;
//     std::cout << "SHA256: " << sha256(text2) << std::endl << std::endl;

//     // Test 3: longer text
//     std::string text3 = "The quick brown fox jumps over the lazy dog";
//     std::cout << "Input: " << text3 << std::endl;
//     std::cout << "SHA256: " << sha256(text3) << std::endl << std::endl;

//     // Test 4: same input twice (should match)
//     std::cout << "Repeat Test (same input as Test 3)" << std::endl;
//     std::cout << "SHA256: " << sha256(text3) << std::endl;

//     return 0;
// }


#include <iostream>
#include "Blockchain.hpp"

int main() {
    Blockchain myChain(4);

    myChain.addBlock(Block(1, "Ahmed pays Aboubaker 10 coins", "", 1));
    myChain.addBlock(Block(2, "Aboubaker pays Lahbib 5 coins", "", 1));
    myChain.addBlock(Block(3, "Lahbib pays Diwana 2 coins", "", 1));

    myChain.printChain();

    std::cout << "Is blockchain valid? "
              << (myChain.isChainValid() ? "Yes" : "No") << std::endl;

    return 0;
}


// int main() {
//     Block b1(0, "Genesis Block", "0", 4);
//     std::cout << "Mining block 1..." << std::endl;
//     b1.mineBlock();
//     return 0;
// }
