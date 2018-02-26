#pragma once
#include <functional>
#include <map>
#include <string>

namespace game
{
  using match = std::map<bool, std::string>;

  auto fizzText()
  {
    using namespace std::string_literals;
    return "Fizz"s;
  }

  auto buzzText()
  {
    using namespace std::string_literals;
    return "Buzz"s;
  }

  auto fizzRule(std::string value, int number)
  {
    return value + match{ { false, fizzText () } }[number % 3];
  }

  auto buzzRule(std::string value, int number)
  {
    return value + match{ { false, buzzText() } }[number % 5];
  }

  auto toStringRule(std::string value, int number)
  {
    return match{ { false, value },{ true, std::to_string(number) } }[value.empty()];
  }

  template <class... Rules>
  auto compile(Rules&&... rules)
  {
    return[=](int number) {
      std::string value;
      return ((value = std::invoke(rules, value, number)), ...);
    };
  }

  inline namespace version1
  {
    auto fizzBuzz(int number)
    {
      return std::invoke(compile(&fizzRule, &buzzRule, &toStringRule), number);
    }
  }

  namespace version2
  {
    auto fizzBuzz(int number)
    {
      return std::invoke(compile(&fizzRule, &buzzRule, &toStringRule), number);
    }
  }
}
