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

  auto const fizz_buzz = fizz_buzz::game();

  //for (auto const value : range::ints(100))
  //  CHECK(oneMatch(fizz_buzz(value), "Fizz"s) == is_multiple_of(3)(value));
}

TEST_CASE("Buzz is equivalent to a multiple of 5") {

  auto const fizz_buzz = fizz_buzz::game();

  //for (auto const value : range::ints(100))
  //  CHECK(oneMatch(fizz_buzz(value), "Buzz"s) == is_multiple_of(5)(value));
}

TEST_CASE("Fizz appears before Buzz") {
}
