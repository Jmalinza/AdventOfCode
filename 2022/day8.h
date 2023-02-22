#pragma once

#include <range/v3/all.hpp>

#include "utility.h"

using namespace aoc::utility;

namespace aoc::twenty22
{
    // row major
    using Forest = std::vector<std::vector<int>>;

    Forest build_forest(std::string path)
    {
        std::vector<std::string> file(readAllLinesFrom(path));

        Forest forest;
        for(auto& line: file)
        {
            auto trees = chunks(line, 1);
            auto heights = trees | ranges::views::transform( [](std::string t) { return std::stoi(t);} ) | ranges::to<std::vector>();
            forest.emplace_back(heights);
        }

        return forest;
    }
}