#ifndef PADMESSAGE1024_H
#define PADMESSAGE1024_H

#include <vector>
#include <string>
#include <cstdint>

std::vector<uint8_t> padMessage1024(const std::string& input);
std::vector<uint8_t> safePadMessage1024(const std::string& input, uint64_t maxInputBytes);

#endif // PADMESSAGE1024_H