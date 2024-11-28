#include "day8.h"

#include <iostream>

int main() {
  auto forest = build_forest("2022/inputs/day8.txt");
  auto result = count_outside_visible_trees(forest);
  std::cout << "Number of visible trees: " << result << "\n";

  result = find_best_scenic_score(forest);
  std::cout << "Best scenic score: " << result << "\n";
  return 0;
}
