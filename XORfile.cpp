#include <iostream>
#include <fstream>
#include <string>

void xorEncryptDecrypt(const std::string& inputFile, const std::string& outputFile, char key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    char ch;
    while (inFile.get(ch)) {
        outFile.put(ch ^ key); 
    }

    inFile.close();
    outFile.close();
    std::cout << "File " << inputFile << " has been encrypted/decrypted into " << outputFile << std::endl;
}

int main() {
    xorEncryptDecrypt("allocations.cpp", "part1_encrypted.bin", 0xAA);
    xorEncryptDecrypt("setpath.cpp", "part2_encrypted.bin", 0xAA);
    return 0;
}
