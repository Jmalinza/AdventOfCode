#pragma once

#include "utility.h"

#include <range/v3/action/sort.hpp>
#include <range/v3/action/unique.hpp>

using namespace aoc::utility;

namespace aoc::day6
{
    int find_start_packet_index(std::string path)
    {
        std::vector<std::string> file(readAllLinesFrom(path));
        auto line = file.front();

        for(auto i = 0; i < line.length() - 4; i++)
        {
            auto window = line.substr(i, 4);
            window |= ranges::action::sort | ranges::action::unique;
            if(window.length() == 4)
                return i + 4;
        }

        return 0;
    }

    int find_start_message_index(std::string path)
    {
        std::vector<std::string> file(readAllLinesFrom(path));
        auto line = file.front();

        for(auto i = 0; i < line.length() - 14; i++)
        {
            auto window = line.substr(i, 14);
            window |= ranges::action::sort | ranges::action::unique;
            if(window.length() == 14)
                return i + 14;
        }

        return 0;
    }
}