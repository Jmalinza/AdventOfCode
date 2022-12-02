#pragma once

#include <fstream>
#include <set>

namespace aoc::day1
{
    std::set<int> find_calories_per_elf(std::ifstream &stream);
}