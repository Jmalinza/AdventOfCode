#include "day1.h"

#include <iostream>

int main() {
  std::vector<std::vector<int>> lists{form_lists_from("2024/inputs/day1.txt")};
  std::cout << "Distance between the lists: " << find_distance_between(lists)
            << "\n";
  std::cout << "Similarity between the lists: "
            << find_similarity_between(lists) << "\n";
  return 0;
}