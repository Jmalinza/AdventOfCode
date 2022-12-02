#include <fstream>
#include <set>
#include <string>

namespace aoc::day1
{
    std::set<int> find_calories_per_elf(std::ifstream &stream){
        std::set<int> result;
        int current_sum = 0;
        std::string number;
        while(std::getline(stream, number))
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
