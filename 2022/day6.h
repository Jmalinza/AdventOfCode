#pragma once

#include "utility/cpp/utilities.h"

#include <algorithm>

using namespace utility;

int find_start_packet_index(std::string path) {
  std::vector<std::string> file(readAllLinesFrom(path));
  auto line = file.front();

  for (auto i = 0U; i < line.length() - 4U; i++) {
    auto window = line.substr(i, 4);
    std::ranges::sort(window);
    const auto [first, last] = std::ranges::unique(window);
    window.erase(first, last);
    if (window.length() == 4U)
      return i + 4;
  }

  return 0;
}

int find_start_message_index(std::string path) {
  std::vector<std::string> file(readAllLinesFrom(path));
  auto line = file.front();

  for (auto i = 0U; i < line.length() - 14U; i++) {
    auto window = line.substr(i, 14);
    std::ranges::sort(window);
    const auto [first, last] = std::ranges::unique(window);
    window.erase(first, last);
    if (window.length() == 14U)
      return i + 14;
  }

  return 0;
}