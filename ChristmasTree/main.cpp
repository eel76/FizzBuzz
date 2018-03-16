#include "gtest/gtest.h"

#include "catalog.h"
#include <iostream>

namespace christmas_tree
{
  auto wood()
  {
    return std::string{ "I" };
  }

  auto needles()
  {
    return std::string{ "X" };
  }

  auto treetop(int height)
  {
    if (height <= 1)
      return catalog(1, Image{ needles () })[height];

    auto const tree = treetop(height - 1);
    return indent (tree) + Image { needles () + bottom (tree) + needles () };
  }

  auto trunk(int height)
  {
    if (height <= 1)
      return catalog(1, Image{ wood () })[height];

    return indent (trunk(height - 1));
  }

  auto image(int height)
  {
    return treetop(height) + trunk(height);
  }
}

TEST(christmasTree, isPrintable) {

  auto const image = christmas_tree::image(7);

  for (auto&& line : image)
    std::cout << line << '\n';
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
