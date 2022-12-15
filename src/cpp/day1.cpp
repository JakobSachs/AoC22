/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 1                                     */

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int32_t solve1(
    std::vector<int32_t>& file_content)  // Solution for the first part
{
  int32_t max_calories = 0;
  int32_t sum = 0;
  for (int32_t cal : file_content)
  {
    if (cal == -1)
    {
      max_calories = std::max(max_calories, sum);
      sum = 0;
    } else
      sum += cal;
  }

  return max_calories;
}

int32_t solve2(
    std::vector<int32_t>& file_content)  // Solution for the second part

{
  int32_t sum = 0;
  std::vector<int32_t> elfs;
  for (int32_t cal : file_content)
  {
    if (cal == -1)
    {
      elfs.push_back(sum);
      sum = 0;
    } else
      sum += cal;
  }

  std::sort(elfs.begin(), elfs.end());

  int32_t sum_of_top_three = std::accumulate(elfs.end() - 3, elfs.end(), 0);

  return sum_of_top_three;
}

int main()
{
  /*                               Input                                    */

  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day1.txt");

  if (!input_file.is_open()) return -1;

  std::string line;
  std::vector<int32_t> file_content;

  while (getline(input_file, line))
  {
    int32_t calories = -1;

    if (line.length() != 0) calories = std::stoi(line);

    file_content.push_back(calories);
  }

  input_file.close();
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
