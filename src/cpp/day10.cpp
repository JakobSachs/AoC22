/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 10                                    */

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
enum class operation_type
{
  addx,
  noop
};
struct operation
{
  const operation_type type;
  const int value;
};

typedef pair<int32_t, int32_t> state;  // first is X, second is cycle count

constexpr operation parse_op(const string& line)
{
  if (line[0] == 'a')  // is addx
  {
    return {operation_type::addx, stoi(line.substr(4))};
  }
  return {operation_type::noop, 0};  // is noop
}

constexpr state apply_op(const operation& op, const state& s)
{
  switch (op.type)
  {
    case operation_type::addx:
      return {s.first + op.value, s.second + 2};
    case operation_type::noop:
      return {s.first, s.second + 1};
  }
  return {-1, -1};  // should never happen
}

int32_t solve1(const vector<operation>& ops)
{
  int32_t sum_signal_strengths = 0;
  state s = {1, 0};

  for (const auto& op : ops)
  {
    if (((s.second + 1) - 20) % 40 == 0)
      sum_signal_strengths += (s.second + 1) * s.first;
    s = apply_op(op, s);
  }

  return sum_signal_strengths;
}

void solve2(const vector<operation>& ops)
{
  array<array<char, 40>, 6> screen;
  for (auto& row : screen) row.fill('.');

  state s = {1, 0};
  for (const auto& op : ops)
  {
    switch (op.type)
    {
      case operation_type::addx: {
        int32_t x = (s.second % 40);
        int32_t y = (s.second / 40);

        if (s.first == x || s.first == x + 1 || s.first == x - 1)
          screen[y][x] = '#';
        s.second++;
        // second  cycle
        x = (s.second % 40);
        y = (s.second / 40);

        if (s.first == x || s.first == x + 1 || s.first == x - 1)
          screen[y][x] = '#';
        s.second++;
        s.first += op.value;
        break;
      }
      case operation_type::noop:
        int32_t x = (s.second % 40);
        int32_t y = (s.second / 40);

        if (s.first == x || s.first == x + 1 || s.first == x - 1)
          screen[y][x] = '#';

        s.second++;
        break;
    }
  }

  cout << "Result 2:\n";
  // output screen
  for (const auto& row : screen)
  {
    for (const auto& c : row) cout << c;
    cout << endl;
  }
}

int main()
{
  /*                               Input                                    */
  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day10.txt");

  if (!input_file.is_open()) return -1;

  vector<operation> ops;
  std::string line;
  while (getline(input_file, line)) ops.push_back(parse_op(line));

  /*                              Calculate */
  auto res1 = solve1(ops);
  std::cout << "Result 1:\t" << res1 << std::endl;

  solve2(ops);  // output is on stdout

  /*                              Output */

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
