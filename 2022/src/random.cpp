#include "random.h"

#include <string>

int aoc::find_max_calories(std::ifstream &stream)
{
    int max = 0;
    int current_sum = 0;
    std::string number;
    while(std::getline(stream, number))
    {
        if(number.empty())
        {
            max = current_sum > max ? current_sum : max;
            current_sum = 0;
            continue;
        }
        current_sum += std::stoi(number);
    }
    return max;
}