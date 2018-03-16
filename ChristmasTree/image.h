#pragma once
#include <string>
#include <vector>

namespace christmas_tree
{
  using Image = std::vector<std::string>;

  auto operator + (Image a, Image b)
  {
    a.insert(end(a), cbegin(b), cend(b));
    return a;
  }

  auto space()
  {
    return std::string{ " " };
  }

  auto indent(Image image, std::string s = space ())
  {
    for (auto& line : image)
      line = s + line;

    return image;
  }

  auto bottom(Image image)
  {
    return image.back();
  }
}
