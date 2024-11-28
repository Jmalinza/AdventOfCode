#pragma once

#include "utility/cpp/utilities.h"

#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <string>

using namespace utility;

using Item = char;
using Bag = std::string;
std::map<Item, int> _item_priority_map{
    {'a', 1},  {'b', 2},  {'c', 3},  {'d', 4},  {'e', 5},  {'f', 6},  {'g', 7},
    {'h', 8},  {'i', 9},  {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14},
    {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21},
    {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}};

std::vector<char> find_common_items_in_bags(Bag bag1, Bag bag2) {
  std::set<char> pocket1(bag1.begin(), bag1.end());
  std::set<char> pocket2(bag2.begin(), bag2.end());
  std::vector<char> common_items;
  std::set_intersection(pocket1.begin(), pocket1.end(), pocket2.begin(),
                        pocket2.end(),
                        std::inserter(common_items, common_items.begin()));

  return common_items;
}

std::vector<char> find_common_item_in_pockets(Bag contents) {
  if (contents.empty())
    return {"", ""};

  auto number_of_items = contents.size();
  auto pocket1 = contents.substr(0, number_of_items / 2);
  auto pocket2 = contents.substr(number_of_items / 2, number_of_items);

  return find_common_items_in_bags(pocket1, pocket2);
}

int find_priority_of_common_items(std::string path) {
  std::vector<std::string> file(readAllLinesFrom(path));
  int total_priority = 0;
  for (const auto &bag : file) {
    auto items = find_common_item_in_pockets(bag);
    for (const Item &item : items) {
      if (std::isupper(item))
        total_priority += _item_priority_map[std::tolower(item)] + 26;
      else
        total_priority += _item_priority_map[item];
    }
  }

  return total_priority;
}

int find_priority_of_badges(std::string path) {
  std::vector<std::string> file(readAllLinesFrom(path));
  int total_priority = 0;
  for (auto i = 0U; i < file.size(); i += 3U) {
    Bag bag1 = file[i];
    Bag bag2 = file[i + 1];
    Bag bag3 = file[i + 2];

    auto bag1_bag2_common = find_common_items_in_bags(bag1, bag2);
    Bag temp_bag(bag1_bag2_common.begin(), bag1_bag2_common.end());
    auto badge = find_common_items_in_bags(temp_bag, bag3);

    if (std::isupper(badge.front()))
      total_priority += _item_priority_map[std::tolower(badge.front())] + 26;
    else
      total_priority += _item_priority_map[badge.front()];
  }

  return total_priority;
}
