#include "day1.h"

#include <iostream>

int main()
{
    std::ifstream ifs{"../../2022/inputs/day1.txt"};
    auto result = aoc::day1::find_calories_per_elf(ifs);
    auto biggest = result.rbegin();
    std::cout << "Max: " << *biggest << std::endl;
    std::cout << "Top3: " << *(biggest++) + *(biggest++) + *(biggest++) << std::endl;

    return 0;
}