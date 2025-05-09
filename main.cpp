#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void xorDecryptSkipJunk(const std::string& inputFile, const std::string& outputFile, char key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        std::cerr << "Error opening file: " << inputFile << " or " << outputFile << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(inFile, line)) {
        if (lineCount % 3 == 0) {
            for (char& c : line) c ^= key;
            outFile << line << '\n';
        }
        ++lineCount;
    }

    inFile.close();
    outFile.close();
    std::cout << "Decrypted (junk skipped): " << inputFile << " -> " << outputFile << std::endl;
}

void combineDecryptedFiles(const std::vector<std::string>& decryptedFiles, const std::string& outputFile) {
    std::ofstream outFile(outputFile);
    
    if (!outFile) {
        std::cerr << "Error creating output file: " << outputFile << std::endl;
        return;
    }

    for (const auto& file : decryptedFiles) {
        std::ifstream inFile(file);
        if (!inFile) {
            std::cerr << "Error reading file: " << file << std::endl;
            continue;
        }
        outFile << inFile.rdbuf();
        inFile.close();
    }

    outFile.close();
    std::cout << "Combined into: " << outputFile << std::endl;
}

int main() {
    const char key = 0xAA;

    xorDecryptSkipJunk("part1_encrypted.bin", "part1_decrypted.cpp", key);
    xorDecryptSkipJunk("part2_encrypted.bin", "part2_decrypted.cpp", key);

    std::vector<std::string> decryptedFiles = {
        "part1_decrypted.cpp",
        "part2_decrypted.cpp"
    };

    combineDecryptedFiles(decryptedFiles, "output.cpp");

    int result = std::system("g++ output.cpp -o finalProgram");
    if (result == 0) {
        std::cout << "Compiled successfully to 'finalProgram'" << std::endl;
    } else {
        std::cerr << "Compilation failed!" << std::endl;
    }

    return 0;
}
