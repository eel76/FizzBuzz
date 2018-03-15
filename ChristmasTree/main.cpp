#include "gtest/gtest.h"

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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
      line = s + line + s;

    return image;
  }

  auto bottom(Image image)
  {
    return image.back();
  }

  using Images = std::map<int, Image>;

  auto operator <= (std::string line, int heigth)
  {
    return std::pair<int, Image> { heigth, Image{line} };
  }

  auto treetop(int height)
  {
    if (height <= 1)
      return Images{ "X"s <= 1 }[height];

    auto const tree = treetop(height - 1);
    return indent (tree, " "s) + Image { "X"s + bottom (tree) + "X"s };
  }

  auto trunk(int height)
  {
    if (height <= 1)
      return Images{ "I"s <= 1 }[height];

    return Image{ " "s + trunk(height - 1).back() };
  }

  auto draw(int height)
  {
    return treetop(height) + trunk(height);
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
