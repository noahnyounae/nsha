#ifndef PADMESSAGE1024_CC
#define PADMESSAGE1024_CC

#include "padMessage1024.hxx"

using namespace std;

vector<uint8_t> padMessage1024(const string& input) {
    vector<uint8_t> padded(input.begin(), input.end());

    // Étape 1 : ajouter le bit 1 (sous forme 0x80)
    padded.push_back(0x80);

    // Étape 2 : ajouter des zéros jusqu’à ce que le bloc soit à 128 bits de la fin
    while ((padded.size() % 128) != 112) {
        padded.push_back(0x00);
    }

    // Étape 3 : ajouter la taille du message en bits (sur 128 bits => 16 octets)
    uint64_t bitLength = static_cast<uint64_t>(input.size()) * 8;
    for (int i = 15; i >= 8; --i) {
        padded.push_back(0x00); // bits de poids fort (message trop court pour dépasser 64 bits)
    }
    for (int i = 7; i >= 0; --i) {
        padded.push_back((bitLength >> (i * 8)) & 0xFF);
    }

    return padded;
}

#include <stdexcept>

vector<uint8_t> safePadMessage1024(const string& input, uint64_t maxInputBytes = (1ULL << 30)) {
    if (input.size() > maxInputBytes) {
        throw runtime_error("Input too long for SHA-1024 padding");
    }
    return padMessage1024(input);
}

#endif // PADMESSAGE1024_CC