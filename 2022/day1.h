#include "utility.h"

#include <set>
#include <string>

using namespace aoc::utility;

namespace aoc::day1
{
    std::set<int> find_calories_per_elf(std::string path){
        std::set<int> result;
        int current_sum = 0;
        std::string number;
        while(get_line_from_file(path, number))
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
