#pragma once
#include <string>
#include <utility>

namespace fizz_buzz
{
  inline namespace version1
  {
    namespace rules
    {
      template <class... Rules>
      auto compile(Rules&&... rules)
      {
        return[=](auto number) {
          auto value = std::string{};
          return ((value = std::invoke(rules, value, number)), ...);
        };
      }

      auto is_multiple_of(int number)
      {
        return [=](auto value) {
          return (value % number) == 0;
        };
      }

      auto fizz()
      {
        return [](auto result, auto number) {
          if (is_multiple_of(3)(number))
            return result + std::string{ "Fizz" };

          return result;
        };
      }

      auto buzz()
      {
        return [](auto result, auto number) {
          if (is_multiple_of(5)(number))
            return result + std::string{ "Buzz" };

          return result;
        };
      }

      auto stringify()
      {
        return [](auto result, auto number) {
          if (result.empty())
            return std::to_string(number);

          return result;
        };
      }
    }

    auto game()
    {
      using namespace rules;
      return compile(fizz(), buzz(), stringify());
    }
  }
}
