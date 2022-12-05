#pragma once

#include "utility.h"

#include <cctype>
#include <map>

using namespace aoc::utility;

namespace aoc::day5
{
    std::vector<std::string> get_initial_stack_conditions(std::string path)
    {
        std::map<int, std::string> _stack_crates_map;
        std::string line;
        while(get_line_from_file(path, line))
        {
            if(std::isdigit(line[1])) break;

            int stack = 1;
            int whitespace = 0;
            for(const auto& item: split(line))
            {
                if(item.empty())
                {
                    bool no_crate = whitespace == 3;
                    whitespace = no_crate ? 0         : whitespace + 1;
                    stack      = no_crate ? stack + 1 : stack;
                } else
                {
                    _stack_crates_map[stack++] += item[1];
                }
            }
        }

        std::vector<std::string> stacks;
        for(auto& stack: _stack_crates_map)
        {
            std::reverse(stack.second.begin(), stack.second.end());
            stacks.emplace_back(stack.second);
        }

        return stacks;
    }

    std::string get_top_crates(const std::vector<std::string>& stacks)
    {
        std::string result;
        for(auto stack: stacks)
            result += stack.back();

        return result;
    }

    std::string run_crane9000_simulation(std::string path)
    {
        auto stacks = get_initial_stack_conditions(path);

        std::string line;
        while(get_line_from_file(path, line))
        {
            if(line.empty()) continue;

            auto instruction = split(line);
            int quantity = std::stoi(instruction[1]);
            int from     = std::stoi(instruction[3]) - 1;
            int to       = std::stoi(instruction[5]) - 1;

            while(quantity)
            {
                stacks[to] += stacks[from].back();
                stacks[from].pop_back();
                quantity--;
            }
        }

        return get_top_crates(stacks);
    }

    std::string run_crane9001_simulation(std::string path)
    {
        auto stacks = get_initial_stack_conditions(path);

        std::string line;
        while(get_line_from_file(path, line))
        {
            if(line.empty()) continue;

            auto instruction = split(line);
            int quantity = std::stoi(instruction[1]);
            int from     = std::stoi(instruction[3]) - 1;
            int to       = std::stoi(instruction[5]) - 1;

            std::string moving_crates;
            while(quantity)
            {
                moving_crates += stacks[from].back();
                stacks[from].pop_back();
                quantity--;
            }

            std::reverse(moving_crates.begin(), moving_crates.end());
            stacks[to] += moving_crates;
        }

        return get_top_crates(stacks);
    }
}