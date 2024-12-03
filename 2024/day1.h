#pragma once

#include "utility/cpp/file-util.h"
#include "utility/cpp/string-util.h"

#include <algorithm>
#include <string>
#include <vector>

std::vector<std::vector<int>> form_lists_from(const std::string &path) {
  std::vector<std::string> file{utility::readAllLinesFrom(path)};
  std::vector<int> list0;
  std::vector<int> list1;
  list0.reserve(file.size());
  list1.reserve(file.size());
  for (const auto &line : file) {
    const std::vector<std::string> values{utility::split(line)};
    if (!values.empty()) {
      list0.emplace_back(std::stoi(values.front()));
      list1.emplace_back(std::stoi(values.back()));
    }
  }
  std::sort(list0.begin(), list0.end());
  std::sort(list1.begin(), list1.end());

  return {list0, list1};
}

int find_distance_between(const std::vector<std::vector<int>> &lists) {
  int distance = 0;
  const auto &list0 = lists.at(0);
  const auto &list1 = lists.at(1);
  for (auto i = 0U; i < list0.size(); ++i) {
    distance += abs(list0.at(i) - list1.at(i));
  }

  return distance;
}

int find_similarity_between(const std::vector<std::vector<int>> &lists) {
  int similarity = 0;
  const auto &list0 = lists.at(0);
  const auto &list1 = lists.at(1);
  for (auto i = 0U; i < list0.size(); ++i) {
    similarity +=
        list0.at(i) * std::count(list1.begin(), list1.end(), list0.at(i));
  }

  return similarity;
}