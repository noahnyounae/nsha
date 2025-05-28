#ifndef BUILD_MESSAGE_SCHEDULE_1024_CPP
#define BUILD_MESSAGE_SCHEDULE_1024_CPP

#include "buildMessageSchedule1024.hxx"

// Right rotation for 64-bit values
uint64_t ROTR(uint64_t x, int n) {
    return (x >> n) | (x << (64 - n));
}

// SHA-1024 message schedule sigma0
uint64_t sigma0(uint64_t x) {
    return ROTR(x, 1) ^ ROTR(x, 8) ^ (x >> 7);
}

// SHA-1024 message schedule sigma1
uint64_t sigma1(uint64_t x) {
    return ROTR(x, 19) ^ ROTR(x, 61) ^ (x >> 6);
}

// Build the message schedule array W[0..127] from a 128-byte block
void buildMessageSchedule1024(const std::vector<uint8_t>& block, uint64_t W[128]) {
    // W[0..15] ← raw block (16 × 64 bits = 128 bytes)
    for (int i = 0; i < 16; ++i) {
        W[i] = 0;
        for (int j = 0; j < 8; ++j) {
            W[i] <<= 8;
            W[i] |= block[i * 8 + j];
        }
    }
    // W[16..127] ← extended with sigma functions
    for (int i = 16; i < 128; ++i) {
        W[i] = sigma1(W[i - 2]) + W[i - 7] + sigma0(W[i - 15]) + W[i - 16];
    }
}

#endif // BUILD_MESSAGE_SCHEDULE_1024_CPP