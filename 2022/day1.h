#include "utility.h"

#include <set>
#include <string>

using namespace aoc::utility;

namespace aoc::twenty22
{
    std::set<int> find_calories_per_elf(std::string path){
        std::vector<std::string> file(readAllLinesFrom(path));
        std::set<int> result;
        int current_sum = 0;
        std::string number;
        for(const auto& number: file)
        {
            if(number.empty())
            {
                result.insert(current_sum);
                current_sum = 0;
                continue;
            }
            current_sum += std::stoi(number);
        }

        return result;
    }
}
