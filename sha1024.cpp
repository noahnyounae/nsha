#ifndef SHA1024_H
#define SHA1024_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>

#include "K1024.h"
#include "initState1024.h"
#include "padMessage1024.h"
#include "buildMessageSchedule1024.h"
#include "compression1024.h"

// Compute SHA-1024 hash for a given input string
std::string sha1024(const std::string& input) {
    // 1. Initialization
    uint64_t H[16];
    initState1024(H);

    // 2. Padding
    std::vector<uint8_t> padded = padMessage1024(input);

    // 3. Process 128-byte blocks
    size_t numBlocks = padded.size() / 128;
    for (size_t i = 0; i < numBlocks; ++i) {
        std::vector<uint8_t> block(padded.begin() + i * 128, padded.begin() + (i + 1) * 128);
        uint64_t W[128];
        buildMessageSchedule1024(block, W);
        compressBlock1024(H, W);
    }

    // 4. Output final hash as hexadecimal string
    std::ostringstream oss;
    for (int i = 0; i < 16; ++i) {
        oss << std::hex << std::setw(16) << std::setfill('0') << H[i];
    }
    return oss.str();
}

#endif // SHA1024_H

#ifndef MAIN
#define MAIN

// Simple CLI for SHA-1024
int main() {
    std::string input;
    std::cout << "Enter a string to hash: ";
    std::getline(std::cin, input);
    std::string hash = sha1024(input);
    std::cout << "\nSHA-1024:\n" << hash << std::endl;
    hash = sha1024(input);
    std::cout << "\nSHA-1024:\n" << hash << std::endl;
    return 0;
}

#endif // MAIN