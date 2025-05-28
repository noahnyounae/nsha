cmake_minimum_required(VERSION 3.10)
project(sha1024 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

file(GLOB SRC_FILES src/*.cc)

# Remove main.cc and sha1024_test.cc from the list for each target
list(REMOVE_ITEM SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cc)
list(REMOVE_ITEM SRC_FILES ${CMAKE_SOURCE_DIR}/src/sha1024_test.cc)

add_executable(sha1024 src/main.cc ${SRC_FILES})
add_executable(sha1024_test src/sha1024_test.cc ${SRC_FILES})

target_include_directories(sha1024 PRIVATE src)
target_include_directories(sha1024_test PRIVATE src)

# Optional: install rules or test rules can be added here
