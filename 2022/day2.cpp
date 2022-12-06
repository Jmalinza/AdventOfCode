#include "day2.h"

#include <iostream>

int main()
{
    auto result = aoc::twenty22::find_score_from_strategy_guide("../../2022/inputs/day2.txt");
    std::cout << "Score: " << result << "\n";

    result = aoc::twenty22::find_score_from_fixing_guide("../../2022/inputs/day2.txt");
    std::cout << "Fixed score: " << result << "\n";
    return 0;
}
