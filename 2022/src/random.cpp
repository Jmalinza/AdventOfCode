#include "random.h"

#include <string>

std::set<int> aoc::day1::find_calories_per_elf(std::ifstream &stream){
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