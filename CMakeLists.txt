cmake_minimum_required (VERSION 3.9)

project (Katas CXX)
set (CMAKE_CXX_STANDARD 17)

file (DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.1.1/catch.hpp "${CMAKE_CURRENT_BINARY_DIR}/include/catch.hpp")
add_library(Catch INTERFACE)
target_include_directories (Catch INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")

add_subdirectory (FizzBuzz)
add_subdirectory (ChristmasTree)
