/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 6                                     */

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
#include <deque>

bool is_marker(const std::string& marker)
{
  // simple brute force
  for (int i = 0; i < marker.length() - 1; i++)
  {
    for (int j = i + 1; j < marker.length(); j++)
    {
      if (marker[i] == marker[j]) return false;
    }
  }

  return true;
}

int32_t solve1(const std::string& signal)
{
  for (size_t i = 0; i < signal.length() - 4; i++)
  {
    if (is_marker(signal.substr(i, 4))) return i + 4;
  }

  return -1;
}

int32_t solve2(std::string signal)
{
  for (size_t i = 0; i < signal.length() - 14; i++)
  {
    if (is_marker(signal.substr(i, 14))) return i + 14;
  }
  return -1;
}

int main()
{
  /*                               Input                                    */
  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day6.txt");

  if (!input_file.is_open()) return -1;

  std::string line;

  getline(input_file, line);

  /*                              Calculate                                  */
  auto res1 = solve1(line);
  auto res2 = solve2(line);

  /*                              Output                                     */

  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
