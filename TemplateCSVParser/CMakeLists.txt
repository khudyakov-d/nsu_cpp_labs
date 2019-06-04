cmake_minimum_required(VERSION 3.12)
project(CSVParser)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSVParser main.cpp tuplePrinter.h CSVParser.h tupleFiller.h CSVIterator.h)