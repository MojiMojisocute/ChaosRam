#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// ฟังก์ชัน XOR decryption
void xorDecrypt(const std::string& inputFile, const std::string& outputFile, char key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    char ch;
    while (inFile.get(ch)) {
        outFile.put(ch ^ key);  // ถอดรหัสโดยใช้ XOR
    }

    inFile.close();
    outFile.close();
    std::cout << "File " << inputFile << " has been decrypted into " << outputFile << std::endl;
}

// ฟังก์ชันเพื่อรวมไฟล์ที่ถอดรหัสแล้ว
void combineDecryptedFiles(const std::vector<std::string>& decryptedFiles, const std::string& outputFile) {
    std::ofstream outFile(outputFile, std::ios::out);
    
    for (const auto& file : decryptedFiles) {
        std::ifstream inFile(file);
        outFile << inFile.rdbuf();
        inFile.close();
    }

    outFile.close();
    std::cout << "Decrypted files have been combined into " << outputFile << std::endl;
}

int main() {
    // ถอดรหัสไฟล์ที่เข้ารหัส
    xorDecrypt("part1_encrypted.bin", "part1_decrypted.cpp", 0xAA);
    xorDecrypt("part2_encrypted.bin", "part2_decrypted.cpp", 0xAA);

    // รวมไฟล์ที่ถอดรหัสแล้ว
    std::vector<std::string> decryptedFiles = {"part1_decrypted.cpp", "part2_decrypted.cpp"};
    combineDecryptedFiles(decryptedFiles, "output.cpp");

    // คอมไพล์ไฟล์ที่ได้
    std::system("g++ output.cpp -o finalProgram");

    return 0;
}
