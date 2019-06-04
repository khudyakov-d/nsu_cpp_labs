cmake_minimum_required(VERSION 3.12)
project(CalculatorTest)

add_subdirectory(lib/googletests)

include_directories(lib/googletests/googletest/include)
include_directories(lib/googletests/googlemock/include)

set(CMAKE_CXX_STANDARD 17)

include_directories(./)

add_executable(CalculatorTest main.cpp Operations/headers/Operations.h Operations/srs/MinusOperation.cpp Operations/headers/MinusOperation.h Operations/srs/PlusOperation.cpp
        Operations/headers/PlusOperation.h Context/Context.cpp Context/Context.h Calculator/Calculator.cpp Calculator/Calculator.h Operations/srs/PopOperation.cpp
        Operations/headers/PopOperation.h Operations/srs/PushOperation.cpp Operations/headers/PushOperation.h  Operations/srs/DivisionOperation.cpp
        Operations/headers/DivisionOperation.h Operations/srs/MulOperation.cpp Operations/headers/MulOperation.h
        Operations/srs/SqrtOperation.cpp Operations/headers/SqrtOperation.h Operations/srs/PrintOperation.cpp Operations/headers/PrintOperation.h
        Operations/srs/DefineOperation.cpp Operations/headers/DefineOperation.h  Operations/srs/Operation.cpp Exceptions/InvalidInput.cpp
        Exceptions/InvalidInput.h Exceptions/EmptyStack.cpp Exceptions/EmptyStack.h Exceptions/ZeroDivision.cpp Exceptions/ZeroDivision.h lib/tests.cpp)

target_link_libraries(CalculatorTest gtest gtest_main)
