#include <iostream>
#include <string>
#include "sha1024.hxx"

int main(int argc, char* argv[]) {
    std::string input;
    if (argc > 1) {
        input = argv[1];
    } else {
        std::cout << "Enter a string to hash: ";
        std::getline(std::cin, input);
    }
    std::string hash = sha1024(input);
    std::cout << "SHA-1024(" << input << "):\n" << hash << std::endl;
    return 0;
}
