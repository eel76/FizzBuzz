#pragma once
#include <numeric>
#include <vector>

namespace range
{
  auto ints(int first, size_t count)
  {
    auto v = std::vector<int>(count);
    std::iota(begin(v), end(v), first);

    return v;
  }

  auto ints(size_t count)
  {
    return ints(0, count);
  }
}

//auto add(int offset)
//{
//  return [=](auto value) { return value + offset; };
//}
//
//auto multiply(int factor)
//{
//  return [=](auto value) { return value * factor; };
//}
