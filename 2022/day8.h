#pragma once

#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <range/v3/all.hpp>

#include "utility.h"

#include <tuple>

using namespace aoc::utility;

namespace aoc::twenty22
{
    // rows, cols, storage
    using Forest = std::tuple<int, int, std::vector<int>>;

    Forest build_forest(std::string path)
    {
        std::vector<std::string> file(readAllLinesFrom(path));

        int rows = file.size();
        int cols = file.at(0).size();
        std::vector<int> data;
        data.reserve(rows*cols);
        for(auto& line: file)
        {
            auto trees = chunks(line, 1);
            auto heights = trees 
                            | ranges::views::transform( [](std::string t) { return std::stoi(t);} ) 
                            | ranges::to<std::vector>();
            data.insert(data.end(), heights.begin(), heights.end());
        }

        return {rows, cols, std::move(data)};
    }

    bool is_visible(const std::vector<int>& trees, int index)
    {
        auto test_tree  = trees.at(index);
        auto lower_side = std::vector<int>(trees.begin(), trees.begin() + index);
        auto upper_side = std::vector<int>(trees.begin() + index + 1, trees.end());

        auto shorter_than_test_tree = [&test_tree](int tree) { return tree < test_tree;};
        bool is_visible_lower = ranges::all_of(lower_side, shorter_than_test_tree);
        bool is_visible_upper = ranges::all_of(upper_side, shorter_than_test_tree);
        
        return is_visible_lower | is_visible_upper;
    }

    int count_visible_trees(const Forest& forest)
    {
        int height = std::get<0>(forest);
        int width  = std::get<1>(forest);
        auto& data = std::get<2>(forest);

        int result = 0;
        for(int r = 0; r < height; r++)
        {
            auto current_row = ranges::views::slice(data, r * height, r * height + width) | ranges::to<std::vector>();
            for(int c = 0; c < width; c++)
            {
                auto current_col = data | ranges::views::drop(c) | ranges::views::stride(width) 
                                        | ranges::to<std::vector>();
                bool is_visible_horizontal = is_visible(current_row, c);
                bool is_visible_vertical   = is_visible(current_col, r);

                result += (is_visible_horizontal | is_visible_vertical) ? 1:0;
            }
        }

        return result;
    }
}