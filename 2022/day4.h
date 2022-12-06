#pragma once

#include "utility.h"

using namespace aoc::utility;

namespace aoc::twenty22
{
    int find_fully_overlapping_ranges(std::string path)
    {
        int result = 0;
        std::string line;
        while(get_line_from_file(path, line))
        {
            auto ranges = split(line, ',');
            auto r1 = split(ranges.front(),'-');
            auto r2 = split(ranges.back(),'-');

            int r1s = std::stoi(r1.front());
            int r1e = std::stoi(r1.back());
            int r2s = std::stoi(r2.front());
            int r2e = std::stoi(r2.back());

            if((r1s <= r2s && r1e >= r2e) || (r2s <= r1s && r2e >= r1e))
                result++;
        }

        return result;
    }

    int find_overlapping_ranges(std::string path)
    {
        int result = 0;
        std::string line;
        while(get_line_from_file(path, line))
        {
            auto ranges = split(line, ',');
            auto r1 = split(ranges.front(),'-');
            auto r2 = split(ranges.back(),'-');

            int r1s = std::stoi(r1.front());
            int r1e = std::stoi(r1.back());
            int r2s = std::stoi(r2.front());
            int r2e = std::stoi(r2.back());

            if(r2s <= r1e && r2e >= r1s)
                result++;
        }

        return result;
    }
}