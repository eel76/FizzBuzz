#include "gtest/gtest.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>

namespace christmas_tree
{
  using namespace std::string_literals;
  using Image = std::vector<std::string>;

  auto operator + (Image a, Image b)
  {
    a.insert(end(a), cbegin(b), cend(b));
    return a;
  }

  //using Transform = std::function<std::string(std::string)>;

  //auto operator | (Image image, Transform transform)
  //{
  //  for (auto& line : image)
  //    line = transform(line);

  //  return image;
  //}

  //auto indent(std::string s)
  //{
  //  return Transform{ [=](auto line) { return s + line; } };
  //}

  auto indent(Image image, std::string s)
  {
    for (auto& line : image)
      line = s + line;

    return image;
  }

  auto bottom(Image image)
  {
    return image.back();
  }

  using Images = std::map<int, Image>;

  auto needles(int height)
  {
    if (height <= 1)
      return Images{ { 1, Image{ "X"s } } }[height];

    auto smaller = needles(height - 1);
    return indent (smaller, " "s) + Image { "X"s + bottom (smaller) + "X"s };
  }

  auto trunk(int height)
  {
    if (height <= 1)
      return Images{ { 1, Image { "I"s } } }[height];

    return Image{ " "s + trunk(height - 1).back() };
  }

  auto draw(int height)
  {
    return needles(height) + trunk(height);
  }
}

TEST(christmasTree, isPrintable) {

  auto const image = christmas_tree::draw(7);

  for (auto&& line : image)
    std::cout << line << '\n';
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
