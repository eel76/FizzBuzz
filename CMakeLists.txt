cmake_minimum_required (VERSION 3.9)

project (FizzBuzz CXX)
set (CMAKE_CXX_STANDARD 17)

add_executable (
  ${PROJECT_NAME}
  main.cpp
  # Readme.md
  )

file (DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.1.1/catch.hpp "${CMAKE_CURRENT_BINARY_DIR}/include/catch.hpp")

target_compile_options (
  ${PROJECT_NAME}
  PRIVATE -std:c++latest
  )

target_include_directories (
  ${PROJECT_NAME}
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/include"
  )
  