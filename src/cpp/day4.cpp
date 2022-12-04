/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 4                                     */

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <chrono>
#include <utility>
#include <set>
#include <vector>

int32_t solve1(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>
                   file_content)  // Solution for the second part

{
  int32_t count = 0;

  for (auto pair : file_content)
  {
    if (pair.first.first <= pair.second.first &&
        pair.first.second >= pair.second.second)
      count++;
    else if (pair.first.first >= pair.second.first &&
             pair.first.second <= pair.second.second)
      count++;
    else
      continue;
  }

  return count;
}

int32_t solve2(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>
                   file_content)  // Solution for the second part

{
  int32_t count = 0;

  for (auto pair : file_content)
  {
    if (std::max(pair.first.first, pair.second.first) <=
        std::min(pair.first.second, pair.second.second))
      count++;
  }

  return count;
}

int main()
{
  /*                               Input                                    */

  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day4.txt");

  if (!input_file.is_open()) return -1;

  std::string line;
  std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> file_content;

  while (getline(input_file, line))
  {
    std::pair<std::pair<int, int>, std::pair<int, int>> pair;

    sscanf(line.c_str(), "%d - %d,%d - %d", &pair.first.first,
           &pair.first.second, &pair.second.first, &pair.second.second);
    file_content.push_back(pair);
  }

  /*                              Calculate                                  */
  auto res1 = solve1(file_content);
  auto res2 = solve2(file_content);

  /*                              Output                                     */

  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
