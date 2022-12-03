#include <fstream>
#include <sstream>
#include <set>
#include <string>

namespace aoc::day1
{
    bool get_line_from_file(std::string path, std::string& outline){
        static std::ifstream ifs{path};
        if(ifs){
            if(ifs.eof()) return false;

            std::getline(ifs, outline);
            return true;
        }
        return false;

    }

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
