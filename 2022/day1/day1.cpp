#include "random.h"

#include <iostream>

int main()
{
    std::ifstream ifs{"/home/jona/Projects/AdventOfCode/2022/inputs/test.txt"};
    auto result = aoc::find_max_calories(ifs);
    std::cout << result << std::endl;
    return 0;
}