#include <iostream>
#include <cassert>
#include <set>
#include "sha1024.hxx"

void test_consistency() {
    std::string h1 = sha1024("hello world");
    std::string h2 = sha1024("hello world");
    assert(h1 == h2 && "Same input should produce same hash");
    std::cout << "[✓] Consistency test passed.\n";
}

void test_difference() {
    std::string h1 = sha1024("hello world");
    std::string h2 = sha1024("hello worle");
    assert(h1 != h2 && "Different input should produce different hash");
    std::cout << "Difference test passed.\n";
}

void test_empty_input() {
    std::string h = sha1024("");
    assert(h.size() == 256 && "Hash of empty string should be 1024 bits (256 hex chars)");
    std::cout << "Empty input test passed.\n";
}

void test_length_variation() {
    std::set<std::string> hashes;
    for (int i = 1; i <= 10; ++i) {
        std::string input(i, 'a');
        hashes.insert(sha1024(input));
    }
    assert(hashes.size() == 10 && "All hashes for different lengths must be unique");
    std::cout << "Length variation test passed.\n";
}

int main() {
    test_consistency();
    test_difference();
    test_empty_input();
    test_length_variation();
    std::cout << "All tests passed successfully!\n";
    return 0;
}
