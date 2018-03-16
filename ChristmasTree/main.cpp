#include "gtest/gtest.h"

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
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

  using ImageCatalog = std::map<int, Image>;

  template <size_t... Is, class Tuple>
  auto image_catalog_impl(std::index_sequence<Is...>, Tuple tuple) {
    return ImageCatalog{
      std::make_pair(std::get<2 * Is>(tuple), std::get<2 * Is + 1>(tuple))...
    };
  }
  template <class... Args>
  auto image_catalog(Args... args)
  {
    return image_catalog_impl (std::make_index_sequence<sizeof...(Args) / 2>{}, std::make_tuple (args...));
  }

  auto treetop(int height)
  {
    if (height <= 1)
      return image_catalog(1, Image{ "X"s })[height];

    auto const tree = treetop(height - 1);
    return indent (tree, " "s) + Image { "X"s + bottom (tree) + "X"s };
  }

  auto trunk(int height)
  {
    if (height <= 1)
      return image_catalog(1, Image{ "I"s })[height];

    return indent (trunk(height - 1), " "s);
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
