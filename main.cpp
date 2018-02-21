#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

//unsigned int Factorial( unsigned int number ) {
//    return number <= 1 ? number : Factorial(number-1)*number;
//}
//
//template <class T>
//using Rule = std::function<std::optional<std::string> (T)>;
//
//template <class T>
//auto operator + (Rule<T> const& lhs, Rule<T> const& rhs)
//{
//    return [=] (T value) {
//        auto const l1 = lhs (value);
//        auto const l2 = rhs (value);
//
//        if (! l1)
//          return l2;
//
//        if (! l2)
//          return l1;
//
//        return std::make_optional (*l1 + *l2);
//    };
//}
//
//template <class T>
//auto operator || (Rule<T> const& lhs, Rule<T> const& rhs)
//{
//    return [=](T value) {
//        auto const ret = lhs(value);
//        return ret ? ret : rhs(value);
//    };
//}
//
//template <class T>
//auto fizz (T value)
//{
//    if (value % 3)
//      return std::make_optional ();
//
//}

auto fizzBuzz(int number)
{
  using namespace std::string_literals;
  using std::to_string;

  if ((number % 3) == 0 && (number % 5) == 0)
    return "FizzBuzz"s;

  if ((number % 3) == 0)
    return "Fizz"s;

  if ((number % 5) == 0)
    return "Buzz"s;

  return to_string(number);
}

auto ints(int first, size_t count)
{
  auto v = std::vector<int>( count );
  std::iota(begin(v), end(v), first);

  return v;
}

auto ints(size_t count)
{
  return ints(0, count);
}

auto is_multiple_of(int factor)
{
  return [=](auto value) { return (value % factor) == 0; };
}

using namespace std::string_literals;

auto const is_multiple_of_three = is_multiple_of(3);
auto const is_multiple_of_five = is_multiple_of(5);

auto contains(std::string const& text, std::string pattern)
{
  return text.find(pattern) != std::string::npos;
}

auto count(std::string const& text, std::string pattern, size_t pos = 0)
{
  auto const matchingPos = text.find(pattern, pos);
  if (matchingPos == std::string::npos)
    return 0;

  return 1 + count(text, pattern, matchingPos + 1);
}

TEST_CASE( "Fizz is equivalent to a multiple of 3" ) {

  for (auto const value : ints(100))
    CHECK(contains (fizzBuzz(value), "Fizz"s) == is_multiple_of_three(value));
}

TEST_CASE("Buzz is equivalent to a multiple of 5") {

  for (auto const value : ints(100))
    CHECK(contains(fizzBuzz(value), "Buzz"s) == is_multiple_of_five(value));
}

TEST_CASE("Fizz appears before Buzz") {
}
