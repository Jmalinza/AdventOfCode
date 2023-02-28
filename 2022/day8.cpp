#include "day8.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

int main()
{
    auto forest = aoc::twenty22::build_forest("../../2022/inputs/day8.txt");
    auto result = aoc::twenty22::count_outside_visible_trees(forest);
    fmt::print("Number of visible trees: {}\n", result);

    result = aoc::twenty22::find_best_scenic_score(forest);
    fmt::print("Best scenic score: {}\n", result);
    return 0;
}
