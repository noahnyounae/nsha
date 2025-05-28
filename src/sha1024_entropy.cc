#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <vector>
#include <string>
#include <numeric>
#include "sha1024.hxx"

double bit_entropy(const std::string& hexDigest) {
    std::bitset<1024> bits;
    for (size_t i = 0; i < 256; ++i) {
        uint8_t byte = std::stoi(hexDigest.substr(i, 1), nullptr, 16);
        for (int j = 0; j < 4; ++j) {
            bits[i * 4 + j] = (byte >> (3 - j)) & 1;
        }
    }

    double count1 = bits.count();
    double p1 = count1 / 1024.0;
    double p0 = 1.0 - p1;

    // Shannon entropy (H = -Σ pi * log2(pi))
    double entropy = 0;
    if (p1 > 0) entropy -= p1 * std::log2(p1);
    if (p0 > 0) entropy -= p0 * std::log2(p0);

    return entropy;
}

int max_corpus_length(const std::vector<std::string>& corpus) {
    // Calculate the number of characters of the longest string in the corpus + 1
    size_t max_length = 0;
    for (const auto& s : corpus) {
        if (s.length() > max_length) {
            max_length = s.length();
        }
    }
    max_length += 3; // Add 3 for padding in output formatting
    return static_cast<int>(max_length);
}

void analyze_entropy(const std::vector<std::string>& corpus) {
    double total_entropy = 0.0;
    int max_length = max_corpus_length(corpus);
    for (const std::string& input : corpus) {
        std::string hash = sha1024(input);
        double e = bit_entropy(hash);
        total_entropy += e;
        std::cout << std::left << std::setw(max_length) << input
                  << "Entropy: " << std::fixed << std::setprecision(5) << e << std::endl;
    }

    std::cout << "\nAverage entropy: " << std::fixed << std::setprecision(5)
              << total_entropy / corpus.size() << " bits" << std::endl;
}

int main() {
    std::vector<std::string> corpus = {
        "hello", "world", "cryptography", "blockchain", "hash",
        "a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg",
        "The quick brown fox jumps over the lazy dog",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        "ChatGPT", "SHA-1024", "entropy test", "random test",
    };
    analyze_entropy(corpus);
    return 0;
}