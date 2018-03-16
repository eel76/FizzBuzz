#pragma once
#include "image.h"
#include <map>
#include <tuple>

namespace christmas_tree
{
  using Catalog = std::map<int, Image>;

  template <size_t... Is, class Tuple>
  auto catalog_impl(std::index_sequence<Is...>, Tuple tuple) {
    return Catalog{
      std::make_pair(std::get<2 * Is>(tuple), std::get<2 * Is + 1>(tuple))...
    };
  }
  template <class... Args>
  auto catalog(Args... args)
  {
    return catalog_impl(std::make_index_sequence<sizeof...(Args) / 2>{}, std::make_tuple(args...));
  }
}
