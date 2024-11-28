#include "day6.h"

#include <iostream>

int main() {
  auto result = find_start_packet_index("2022/inputs/day6.txt");
  std::cout << "Start of packet marker index: " << result << std::endl;

  result = find_start_message_index("2022/inputs/day6.txt");
  std::cout << "Start of message marker index: " << result << std::endl;

  return 0;
}