#include "day3.h"

#include <iostream>

int main()
{
    auto result = aoc::twenty22::find_priority_of_common_items("../../2022/inputs/day3.txt");
    std::cout << "Summed priorities of common items: " << result << std::endl;

    result = aoc::twenty22::find_priority_of_badges("../../2022/inputs/day3.txt");
    std::cout << "Summed priorities of badges: " << result;
    return 0;

}