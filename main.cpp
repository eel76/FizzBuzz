#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "game.h"
#include "range.h"

#include <iostream>

using namespace std::string_literals;

auto is_multiple_of(int factor)
{
  return [=](auto value) { return (value % factor) == 0; };
}

auto count(std::string const& text, std::string pattern, size_t pos = 0)
{
  auto const matchingPos = text.find(pattern, pos);
  if (matchingPos == std::string::npos)
    return 0;

  return 1 + count(text, pattern, matchingPos + 1);
}

auto oneMatch(std::string const& text, std::string pattern)
{
  return count(text, pattern) == 1;
}

TEST_CASE("Print all results") {

  auto const fizz_buzz = fizz_buzz::game();

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
