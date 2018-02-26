cmake_minimum_required (VERSION 3.9)

project (FizzBuzz CXX)

add_executable (
  ${PROJECT_NAME}
  main.cpp
  game.h
  # Readme.md
  )

file (DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.1.1/catch.hpp "${CMAKE_CURRENT_BINARY_DIR}/include/catch.hpp")

target_compile_options (
  ${PROJECT_NAME}
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-std:c++latest>
  PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-std:c++17>
  )

target_include_directories (
  ${PROJECT_NAME}
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/include"
  )
  