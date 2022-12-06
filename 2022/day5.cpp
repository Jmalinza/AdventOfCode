#include "day5.h"

#include <iostream>

int main()
{
    auto result = aoc::twenty22::run_crane9000_simulation("../../2022/inputs/day5.txt");
    std::cout << "CrateMover 9000: " << result << "\n";

    result = aoc::twenty22::run_crane9001_simulation("../../2022/inputs/day5.txt");
    std::cout << "CrateMover 9001: " << result << "\n";

    return 0;
}