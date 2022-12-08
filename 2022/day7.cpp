#include "day7.h"

#include <iostream>

int main()
{
    auto fs = aoc::twenty22::build_directory("../../2022/inputs/day7.txt");
    auto result = aoc::twenty22::sum_folder_sizes_under_size(fs, 100000);
    std::cout << "Sum of directory sizes under 100,000: " << result << "\n";

    result = aoc::twenty22::smallest_file_to_delete(fs);
    std::cout << "Smallest file to delete: " << result << "\n";
    return 0;
}
