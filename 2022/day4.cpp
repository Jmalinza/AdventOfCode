#include "day4.h"

#include <iostream>

int main()
{
    auto result = aoc::twenty22::find_fully_overlapping_ranges("../../2022/inputs/day4.txt");
    std::cout << "#completely overlapping ranges: " << result << "\n";

    result = aoc::twenty22::find_overlapping_ranges("../../2022/inputs/day4.txt");
    std::cout << "#partially overlapping ranges: " << result << "\n";
    return 0;
}