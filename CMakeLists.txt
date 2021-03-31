cmake_minimum_required(VERSION 3.14)
project(Matrices VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_library(FractionLib Fraction.cpp)

add_executable(FractionTest Tests/FractionTest.cpp)

add_executable(Main main.cpp)

target_link_libraries(FractionTest gtest_main FractionLib)
target_link_libraries(Main FractionLib)

include(GoogleTest)
gtest_discover_tests(FractionTest)
