#pragma once

#include <range/v3/all.hpp>

#include "utility.h"

#include <map>
#include <memory>
#include <set>

using namespace aoc::utility;

namespace aoc::twenty22
{
    struct File
    {
        std::string name;
        int size;
    };

    bool operator<(const File &rhs, const File &lhs)
    {
        return rhs.size < lhs.size;
    }

    struct Directory
    {
        Directory(std::string name, std::shared_ptr<Directory> parent)
            : _name(std::move(name)), _parent(std::move(parent)){}

        Directory(std::string name): _name(std::move(name)){}

        std::string _name;
        std::shared_ptr<Directory> _parent;
        std::set<File> _files;
        std::set<std::shared_ptr<Directory>> _children;

        int size() const{
            auto result = ranges::accumulate(_children, 0, [](int sum, const std::shared_ptr<Directory>& d){return sum + d->size();});
            return ranges::accumulate(_files, result, [](int sum, const File& f){return sum + f.size;});
        }

        void add_child(const std::shared_ptr<Directory>& dir)
        {
            _children.insert(dir);
        }

        void add_file(std::string name, int size)
        {
            _files.insert({std::move(name), size});
        }
    };

    using FileSystem = std::map<std::string, std::shared_ptr<Directory>>;

    FileSystem build_directory(std::string path)
    {
        FileSystem fs;
        fs["/"] = std::make_shared<Directory>("/");
        fs["/"]->_parent = fs["/"];

        auto current_dir = fs["/"];
        std::vector<std::string> file(readAllLinesFrom(path));
        std::vector<std::string>(file.begin() + 1, file.end()).swap(file);
        for(const auto& line: file)
        {
            auto tokens = split(line);
            if(tokens.front() == "$")
            {
                if(tokens[1] == "ls")
                {
                    continue;
                }
                else if(tokens[1] == "cd")
                {
                    auto dir_to_move_to = tokens[2];

                    if(dir_to_move_to == "..")
                        current_dir = current_dir->_parent;
                    else
                        current_dir = fs[current_dir->_name + dir_to_move_to + "/"];
                }
            }
            else if(tokens.front() == "dir")
            {
                std::string name = current_dir->_name + tokens[1] +"/";
                auto dir = std::make_shared<Directory>(name, current_dir);
                current_dir->add_child(dir);
                fs[name] = dir;

            }
            else if(isDigit(tokens.front()))
            {
                int size = std::stoi(tokens.front());
                std::string name = tokens.back();
                current_dir->add_file(name, size);
            }
        }

        return fs;
    }

    int sum_folder_sizes_under_size(FileSystem fs, int limit)
    {
        int sum = 0;
        ranges::for_each(fs.begin(), fs.end(),
                         [&sum, limit](const auto& dir)
                         {
                            auto size = dir.second->size();
                            if(size < limit)
                                sum += size;
                         });
        return sum;
    }

    int smallest_file_to_delete(FileSystem fs)
    {
        constexpr int required = 30000000;
        constexpr int total    = 70000000;

        int need_to_free = required - (total- fs["/"]->size());

        if(need_to_free < 0)
            return 0;

        int result = total;
        ranges::for_each(fs.begin(), fs.end(),
                         [&result, need_to_free](const auto& dir)
                         {
                            auto size = dir.second->size();
                            if(size >= need_to_free && size < result)
                                result = size;
                         });

        return result;
    }
}