#include <iostream>
#include <string>
#include "sha1024.hxx"

int main() {
    std::string input;
    std::cout << "Enter a string to hash: ";
    std::getline(std::cin, input);
    std::string hash = sha1024(input);
    std::cout << "\nSHA-1024:\n" << hash << std::endl;
    return 0;
}
