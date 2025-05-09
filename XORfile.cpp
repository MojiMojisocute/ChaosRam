#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string xorLine(const std::string& line, char key) {
    std::string result = line;
    for (char& c : result) {
        c ^= key;
    }
    return result;
}

std::string generateRandomJunkLine(int length) {
    std::string junk;
    for (int i = 0; i < length; ++i) {
        char c = static_cast<char>((rand() % 94) + 33); 
        junk += c;
    }
    return junk;
}

void xorEncryptWithJunk(const std::string& inputFile, const std::string& outputFile, char key) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Error opening file(s)." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {

        std::string encrypted = xorLine(line, key);
        outFile.write(encrypted.c_str(), encrypted.size());
        outFile.put('\n');

        for (int i = 0; i < 2; ++i) {
            std::string junk = generateRandomJunkLine(rand() % 20 + 10); 
            std::string junkEncrypted = xorLine(junk, key);
            outFile.write(junkEncrypted.c_str(), junkEncrypted.size());
            outFile.put('\n');
        }
    }

    inFile.close();
    outFile.close();
    std::cout << "Encrypted with random junk added to: " << outputFile << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    xorEncryptWithJunk("allocations.cpp", "part1_encrypted.txt", 0xAA);
    xorEncryptWithJunk("setpath.cpp", "part2_encrypted.txt", 0xAA);

    return 0;
}