#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "game.h"
#include "range.h"

#include <iostream>

using namespace std::string_literals;

TEST_CASE("Print all results") {

  constexpr auto fizz_buzz = fizz_buzz::game();

  for (auto const value : range::ints(1, 100))
    std::cout << fizz_buzz(value) << '\n';
}

TEST_CASE("Fizz is equivalent to a multiple of 3") {
}

TEST_CASE("Buzz is equivalent to a multiple of 5") {
}

TEST_CASE("Fizz appears before Buzz") {
}

