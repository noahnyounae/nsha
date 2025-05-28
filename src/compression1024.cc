#ifndef COMPRESSION1024_CC
#define COMPRESSION1024_CC

#include "compression1024.hxx"
#include "K1024.hxx"
#include "buildMessageSchedule1024.hxx"

// SHA-1024 Sigma0 function
uint64_t Sigma0(uint64_t x) {
    return ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39);
}

// SHA-1024 Sigma1 function
uint64_t Sigma1(uint64_t x) {
    return ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41);
}

// SHA-1024 Ch function
uint64_t Ch(uint64_t x, uint64_t y, uint64_t z) {
    return (x & y) ^ (~x & z);
}

// SHA-1024 Maj function
uint64_t Maj(uint64_t x, uint64_t y, uint64_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

// Compression function for one 128-byte block
void compressBlock1024(uint64_t state[16], const uint64_t W[128]) {
    // Copy initial state into working variables
    uint64_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint64_t e = state[4], f = state[5], g = state[6], h = state[7];
    uint64_t i_ = state[8], j = state[9], k = state[10], l = state[11];
    uint64_t m = state[12], n = state[13], o = state[14], p = state[15];

    for (int t = 0; t < 128; ++t) {
        uint64_t T1 = p + Sigma1(m) + Ch(m, n, o) + K[t] + W[t];
        uint64_t T2 = Sigma0(a) + Maj(a, b, c);
        // Rotate working variables
        p = o;
        o = n;
        n = m;
        m = l + T1;
        l = k;
        k = j;
        j = i_;
        i_ = h;
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }
    // Update state
    state[0] += a; state[1] += b; state[2] += c; state[3] += d;
    state[4] += e; state[5] += f; state[6] += g; state[7] += h;
    state[8] += i_; state[9] += j; state[10] += k; state[11] += l;
    state[12] += m; state[13] += n; state[14] += o; state[15] += p;
}

#endif // COMPRESSION1024_CC