#include "day4.h"

#include <iostream>

int main(){
    auto result = aoc::day4::find_fully_overlapping_ranges("../../2022/inputs/day4.txt");
    std::cout << "#completely overlapping ranges: " << result << std::endl;

    result = aoc::day4::find_overlapping_ranges("../../2022/inputs/day4.txt");
    std::cout << "#partially overlapping ranges: " << result;
    return 0;
}