#ifndef BUILD_MESSAGE_SCHEDULE_1024_H
#define BUILD_MESSAGE_SCHEDULE_1024_H

#include <cstdint>
#include <vector>

// Functions for building the SHA-1024 message schedule
uint64_t ROTR(uint64_t x, int n);
uint64_t sigma0(uint64_t x);
uint64_t sigma1(uint64_t x);
void buildMessageSchedule1024(const std::vector<uint8_t>& block, uint64_t W[128]);

#endif // BUILD_MESSAGE_SCHEDULE_1024_H