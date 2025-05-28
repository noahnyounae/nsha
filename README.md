# SHA-1024 Implementation in C++

This project provides a modular implementation of the SHA-1024 cryptographic hash function in C++.

## Features
- Clean, modular C++ code
- Follows the structure of the SHA-2 family
- Easy to build and use as a library or CLI

## Directory Structure
- `src/` — All source and header files
- `build/` — CMake build output

## Build

### Using CMake (Recommended)
```sh
mkdir -p build
cd build
cmake ..
make sha1024
make sha1024_test
```

### Run
```sh
./sha1024
./sha1024_test
```

## License
MIT
