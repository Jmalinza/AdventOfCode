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

    std::vector<std::string> split(const std::string& string, char delim = ' ')
    {
        std::stringstream s(string);
        std::string part;
        std::vector<std::string> result;
        while(std::getline(s, part, delim))
            result.push_back(part);

        return result;
    }

    std::vector<std::string> chunks(const std::string& string, int chunk_size)
    {
        std::vector<std::string> result;
        int current_position = 0;
        auto size = string.size();
        while( (current_position + chunk_size) <= size)
        {
            result.emplace_back(string.substr(current_position, chunk_size));
            current_position += chunk_size;
        }

        if(current_position < size)
            result.emplace_back(string.substr(current_position, size));

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