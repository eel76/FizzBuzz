#pragma once
#include <functional>
#include <map>
#include <string>

namespace fizz_buzz
{
  inline namespace version1
  {
    inline namespace detail
    {
      constexpr auto is_multiple_of(int number)
      {
        return [=](auto value) {
          return (value % number) == 0;
        };
      }

      constexpr auto operator "" _if_(char const* text, size_t)
      {
        return [=](bool condition) {
          return std::string{ condition ? text : "" };
        };
      }
    }

    namespace rules
    {
      template <class... Rules>
      constexpr auto combine(Rules&&... rules)
      {
        return[=](auto number) {
          auto value = std::string{};
          return ((value = std::invoke(rules, value, number)), ...);
        };
      }

      constexpr auto fizz()
      {
        return [](auto output, auto number) {
          return output + "Fizz"_if_(is_multiple_of(3)(number));
        };
      }

      constexpr auto buzz()
      {
        return [](auto output, auto number) {
          return output + "Buzz"_if_(is_multiple_of(5)(number));
        };
      }

      constexpr auto stringify()
      {
        return [](auto output, auto number) {
          return output.empty() ? std::to_string(number) : output;
        };
      }
    }

    constexpr auto game()
    {
      using namespace rules;
      return combine(fizz(), buzz(), stringify());
    }
  }
}
