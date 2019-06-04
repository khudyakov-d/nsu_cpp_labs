cmake_minimum_required(VERSION 3.12)
project(HashTableTest)


add_subdirectory(lib/googletests)
include_directories(lib/googletests/googletest/include)
include_directories(lib/googletests/googlemock/include)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTableTest main.cpp lib/HashTable.cpp lib/HashTable.h lib/tests.cpp)
target_link_libraries(HashTableTest gtest gtest_main)
