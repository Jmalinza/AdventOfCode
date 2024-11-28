#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace utility {

std::vector<std::string> readAllLinesFrom(const std::string &path) {
  std::ifstream ifs;
  ifs.open(path);

  std::vector<std::string> result;
  if (ifs.is_open()) {
    std::string line;
    while (std::getline(ifs, line))
      result.emplace_back(std::move(line));
  }

  ifs.close();
  return result;
}
} // namespace utility