#include "day1.h"

#include <iostream>

int main()
{
    auto result = aoc::day1::find_calories_per_elf("../../2022/inputs/day1.txt");
    auto biggest = result.rbegin();
    std::cout << "Max: " << *biggest << std::endl;
    std::cout << "Top3: " << *(biggest++) + *(biggest++) + *(biggest++) << std::endl;

    return 0;
}