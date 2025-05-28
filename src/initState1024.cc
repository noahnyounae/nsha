#ifndef INITSTATE1024_CC
#define INITSTATE1024_CC

#include "initState1024.hxx"

// Initial SHA-1024 state values (first 16 64-bit words)
void initState1024(uint64_t H[16]) {
    const uint64_t H0[16] = {
        0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL,
        0x3c6ef372fe94f82bULL, 0xa54ff53a5f1d36f1ULL,
        0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL,
        0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL,
        0xcbbb9d5dc1059ed8ULL, 0x629a292a367cd507ULL,
        0x9159015a3070dd17ULL, 0x152fecd8f70e5939ULL,
        0x67332667ffc00b31ULL, 0x8eb44a8768581511ULL,
        0xdb0c2e0d64f98fa7ULL, 0x47b5481dbefa4fa4ULL
    };
    for (int i = 0; i < 16; ++i) {
        H[i] = H0[i];
    }
}

#endif // INITSTATE1024_CC