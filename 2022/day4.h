#pragma once

#include "utility/cpp/utilities.h"

using namespace utility;

int find_fully_overlapping_ranges(std::string path) {
  std::vector<std::string> file(readAllLinesFrom(path));
  int result = 0;
  for (const auto &line : file) {
    auto ranges = split(line, ',');
    auto r1 = split(ranges.front(), '-');
    auto r2 = split(ranges.back(), '-');

    int r1s = std::stoi(r1.front());
    int r1e = std::stoi(r1.back());
    int r2s = std::stoi(r2.front());
    int r2e = std::stoi(r2.back());

    if ((r1s <= r2s && r1e >= r2e) || (r2s <= r1s && r2e >= r1e))
      result++;
  }

  return result;
}

int find_overlapping_ranges(std::string path) {

  std::vector<std::string> file(readAllLinesFrom(path));
  int result = 0;
  std::string line;
  for (const auto &line : file) {
    auto ranges = split(line, ',');
    auto r1 = split(ranges.front(), '-');
    auto r2 = split(ranges.back(), '-');

    int r1s = std::stoi(r1.front());
    int r1e = std::stoi(r1.back());
    int r2s = std::stoi(r2.front());
    int r2e = std::stoi(r2.back());

    if (r2s <= r1e && r2e >= r1s)
      result++;
  }

  return result;
}