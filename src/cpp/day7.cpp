/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 7                                     */

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

int32_t solve1(const std::string& signal)
{

  return -1;
}

int32_t solve2(std::string signal)
{
  return -1;
}

int main()
{
  /*                               Input                                    */
  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day7.txt");

  if (!input_file.is_open()) return -1;

  std::string line;
  

  input_file.close();

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
