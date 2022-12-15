/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 11                                    */

#include <math.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
struct monkey
{
  const vector<int32_t> starting_items;
  const function<int32_t(const int32_t)> operation;
  const int32_t divisor;
  const size_t next_monkey_true;
  const size_t next_monkey_false;
};

int32_t solve1();

int32_t solve2();

int main()
{
  /*                               Input                                    */
  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day11.txt");

  if (!input_file.is_open()) return -1;

  stringstream sstr;
  while (input_file >> sstr.rdbuf())
    ;

  input_file.close();

  /*                              Calculate */
  auto res1 = solve1();
  auto res2 = solve1();
  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;

  /*                              Output */

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
