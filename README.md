# SHA-1024 Implementation in C++

This project provides a modular implementation of the SHA-1024 cryptographic hash function in C++.

## Features
- Clean, modular C++ code
- Follows the structure of the SHA-2 family
- Easy to build and use as a library or CLI

## File Structure
- `sha1024.cpp` — Main hash function and CLI
- `K1024.cpp/h` — Round constants
- `initState1024.cpp/h` — Initial state values
- `padMessage1024.cpp/h` — Message padding
- `buildMessageSchedule1024.cpp/h` — Message schedule
- `compression1024.cpp/h` — Compression function

## Build

### Simple build (single file, using g++)
```sh
g++ -std=c++17 sha1024.cpp buildMessageSchedule1024.cpp compression1024.cpp initState1024.cpp padMessage1024.cpp K1024.cpp -o sha1024
```

### With Makefile
A sample `Makefile` is provided. To build:
```sh
make
```

## Usage
Run the CLI:
```sh
./sha1024
```

## License
MIT
