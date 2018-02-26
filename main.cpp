#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "game.h"

#include <algorithm>
#include <functional>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

using namespace std::string_literals;

template <class T>
using Rule = std::function<std::string(std::string, T)>;

auto is_multiple_of(int factor)
{
  return [=](auto value) { return (value % factor) == 0; };
}

auto multiple(int factor, std::string text)
{
  return Rule<int> {[=](auto output, auto value) {
    auto mapping = std::map<bool, std::string>{ { true, text } };
    return output + mapping[is_multiple_of(factor)(value)];
  }};
}

namespace range
{
  auto ints(int first, size_t count)
  {
    auto v = std::vector<int>(count);
    std::iota(begin(v), end(v), first);

    return v;
  }

  auto ints(size_t count)
  {
    return ints(0, count);
  }
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

TEST_CASE("Fizz is equivalent to a multiple of 3") {

  // ints() | multiplyWith(3) | delimit (99)
  for (auto const value : range::ints(100))
    CHECK(oneMatch(game::fizzBuzz(value), "Fizz"s) == is_multiple_of(3)(value));
}

TEST_CASE("Buzz is equivalent to a multiple of 5") {

  for (auto const value : range::ints(100))
    CHECK(oneMatch(game::fizzBuzz(value), "Buzz"s) == is_multiple_of(5)(value));
}

TEST_CASE("Fizz appears before Buzz") {
}
