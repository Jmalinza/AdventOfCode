#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace aoc::utility{
    std::vector<std::string> readAllLinesFrom(const std::string& path)
    {
        std::ifstream ifs;
        ifs.open(path);
    
        std::vector<std::string> result;
        if(ifs.is_open()){
            std::string line;
            while(std::getline(ifs, line))
                result.emplace_back(std::move(line));
        }

        ifs.close();
        return result;
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

    bool isDigit(const std::string& string)
    {
        std::string s(string);
        while(!s.empty() && std::isdigit(s.back()))
            s.pop_back();

        return s.empty();
    }
}