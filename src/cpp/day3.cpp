/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 3                                     */

#include <algorithm>
#include <cstddef>
#include <cstdint>
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

constexpr int32_t get_priority(const char item)
{
  if (item <= 'a')  // uppercase
    return (int) item - (int) 'A' + 27;
  else
    return (int) item - (int) 'a' + 1;
}

int32_t solve1(
    std::vector<std::string> file_content)  // Solution for the second part
{
  int32_t sum = 0;
  for (auto backpack : file_content)
  {
    // not verz pretty solution, but would rather use stdlib calls
    auto first = backpack.substr(0, backpack.length() / 2);
    auto second = backpack.substr(backpack.length() / 2);

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    std::vector<char> diff;
    std::set_intersection(first.begin(), first.end(), second.begin(),
                          second.end(), std::inserter(diff, diff.begin()));
    std::sort(diff.begin(), diff.end());
    diff.erase(std::unique(diff.begin(), diff.end()), diff.end());

    for (char c : diff) sum += get_priority(c);
  }
  return sum;
}

int32_t solve2(
    std::vector<std::string> file_content)  // Solution for the second part

{
  int32_t sum = 0;
  for (size_t i = 0; i < file_content.size(); i += 3)
  {
    // This aint pretty either but oh well
    std::vector<std::string> backpacks{file_content[i], file_content[i + 1],
                                       file_content[i + 2]};

    for (std::string &b : backpacks) std::sort(b.begin(), b.end());

    std::vector<char> diff;
    std::vector<char> tmp_diff;
    std::set_intersection(backpacks[0].begin(), backpacks[0].end(),
                          backpacks[1].begin(), backpacks[1].end(),
                          std::inserter(tmp_diff, tmp_diff.begin()));
    std::sort(tmp_diff.begin(), tmp_diff.end());

    std::set_intersection(tmp_diff.begin(), tmp_diff.end(),
                          backpacks[2].begin(), backpacks[2].end(),
                          std::inserter(diff, diff.begin()));

    std::sort(diff.begin(), diff.end());
    diff.erase(std::unique(diff.begin(), diff.end()), diff.end());

    for (char c : diff) sum += get_priority(c);
  }
  return sum;
}

int main()
{
  /*                               Input                                    */

  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day3.txt");

  if (!input_file.is_open()) return -1;

  std::string line;
  std::vector<std::string> file_content;

  while (getline(input_file, line))
  {
    file_content.push_back(line);
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
