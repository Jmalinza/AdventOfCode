#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace aoc::utility{
    bool get_line_from_file(const std::string& path, std::string& outline)
    {
        static std::ifstream ifs{path};
        if(ifs){
            if(ifs.eof()) {
                ifs.close();
                ifs.open(path);
                return false;
            }

            std::getline(ifs, outline);
            return true;
        }

        ifs.close();
        return false;
    }

    auto split(const std::string& string, char delim = ' ')
    {
        std::stringstream s(string);
        std::string part;
        std::vector<std::string> result;
        while(std::getline(s, part, delim))
            result.push_back(part);

        return result;
    }
}