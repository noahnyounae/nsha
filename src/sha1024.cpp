#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>

#include "K1024.hxx"
#include "initState1024.hxx"
#include "padMessage1024.hxx"
#include "buildMessageSchedule1024.hxx"
#include "compression1024.hxx"

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