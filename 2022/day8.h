#pragma once

#include "utility/cpp/utilities.h"

#include <algorithm>
#include <ranges>
#include <tuple>

using namespace utility;

// rows, cols, storage
using Forest = std::tuple<int, int, std::vector<int>>;

Forest build_forest(std::string path) {
  std::vector<std::string> file(readAllLinesFrom(path));

  int rows = file.size();
  int cols = file.at(0).size();
  std::vector<int> data;
  data.reserve(rows * cols);

  for (auto &line : file) {
    auto trees = chunks(line, 1);
    auto heights = std::ranges::transform_view(
        trees, [](std::string t) { return std::stoi(t); });

    data.insert(data.end(), heights.begin(), heights.end());
  }

  return {rows, cols, std::move(data)};
}

bool is_outside_visible(const std::vector<int> &trees, int index) {
  auto test_tree = trees.at(index);
  auto lower_side = std::vector<int>(trees.begin(), trees.begin() + index);
  auto upper_side = std::vector<int>(trees.begin() + index + 1, trees.end());

  auto shorter_than_test_tree = [&test_tree](int tree) {
    return tree < test_tree;
  };
  bool is_visible_lower =
      std::ranges::all_of(lower_side, shorter_than_test_tree);
  bool is_visible_upper =
      std::ranges::all_of(upper_side, shorter_than_test_tree);

  return is_visible_lower | is_visible_upper;
}

int count_outside_visible_trees(const Forest &forest) {
  int height = std::get<0>(forest);
  int width = std::get<1>(forest);
  auto &data = std::get<2>(forest);

  int result = 0;
  for (int r = 0; r < height; r++) {
    auto current_row = std::vector<int>(data.begin() + r * height,
                                        data.begin() + r * height + width);
    // auto current_row = data | ranges::views::slice(r * height, r * height +
    // width) | ranges::to<std::vector>();
    for (int c = 0; c < width; c++) {
      auto current_col_view = data | std::views::drop(c);
      auto current_col = std::vector<int>(current_col_view.begin(),
                                          current_col_view.begin() + width);
      // auto current_col = data | ranges::views::drop(c) |
      // ranges::views::stride(width) | ranges::to<std::vector>();

      bool is_visible_horizontal = is_outside_visible(current_row, c);
      bool is_visible_vertical = is_outside_visible(current_col, r);

      result += (is_visible_horizontal | is_visible_vertical) ? 1 : 0;
    }
  }

  return result;
}

int find_scenic_score(const std::vector<int> &trees, int index) {
  auto test_tree = trees.at(index);
  auto lower_side = std::vector<int>(trees.begin(), trees.begin() + index);
  auto upper_side = std::vector<int>(trees.begin() + index + 1, trees.end());

  int upper_visible = 0;
  int lower_visible = 0;

  while (!lower_side.empty()) {
    lower_visible++;
    if (lower_side.back() >= test_tree)
      break;

    lower_side.pop_back();
  }

  std::reverse(upper_side.begin(), upper_side.end());
  while (!upper_side.empty()) {
    upper_visible++;
    if (upper_side.back() >= test_tree)
      break;

    upper_side.pop_back();
  }

  return upper_visible * lower_visible;
}

int find_best_scenic_score(const Forest &forest) {
  int height = std::get<0>(forest);
  int width = std::get<1>(forest);
  auto &data = std::get<2>(forest);

  std::vector<int> scores;
  scores.reserve(height * width);
  for (int r = 0; r < height; r++) {
    auto current_row = std::vector<int>(data.begin() + r * height,
                                        data.begin() + r * height + width);
    // auto current_row = data | ranges::views::slice(r * height, r * height +
    // width) | ranges::to<std::vector>();

    for (int c = 0; c < width; c++) {
      auto current_col_view = data | std::views::drop(c);
      auto current_col = std::vector<int>(current_col_view.begin(),
                                          current_col_view.begin() + width);
      // auto current_col = data | ranges::views::drop(c) |
      // ranges::views::stride(width) | ranges::to<std::vector>();

      auto row_score = find_scenic_score(current_row, c);
      auto col_score = find_scenic_score(current_col, r);
      scores.emplace_back(row_score * col_score);
    }
  }

  std::ranges::sort(scores);
  return scores.back();
}