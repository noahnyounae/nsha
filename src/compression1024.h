#ifndef COMPRESSION1024_HXX
#define COMPRESSION1024_HXX

#include "K1024.hxx"
#include "buildMessageSchedule1024.hxx"
#include <cstdint>

// Compress a single 128-byte block for SHA-1024
void compressBlock1024(uint64_t state[16], const uint64_t W[128]);

#endif // COMPRESSION1024_HXX