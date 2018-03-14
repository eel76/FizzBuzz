#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

namespace christmas_tree
{
  using namespace std::string_literals;
  using Image = std::vector<std::string>;

  template <class... Images>
  auto combine(Images&&... images)
  {
    auto ret = Image{};
    ((ret.insert (ret.end (), images.begin (), images.end ())), ...);
    return ret;
  }

  auto needles(int height)
  {
    if (height <= 0)
      return Image{};

    if (height == 1)
      return Image{ "X"s };

    auto const image = needles(height - 1);

    auto newImage = Image{};
    newImage.emplace_back(" "s + image.front());

    for (auto const& needles : image)
      newImage.emplace_back(needles + "XX"s);

    return newImage;
  }

  auto trunk(int height)
  {
    if (height <= 0)
      return Image{};

    if (height == 1)
      return Image{ "I"s };

    return Image{ " "s + trunk(height - 1).back() };
  }

  auto draw(int height)
  {
    return combine (needles(height), trunk(height));
  }
}

TEST_CASE("Print tree") {

  auto const image = christmas_tree::draw(7);

  for (auto&& line : image)
    std::cout << line << '\n';
}
