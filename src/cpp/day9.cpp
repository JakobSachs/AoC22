/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 9                                     */

#include <math.h>
#include <algorithm>
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

typedef std::pair<char, int> move;
typedef std::pair<int32_t, int32_t> position;

const int32_t sign(const int32_t x) { return (x > 0) - (x < 0); }

void update_knot(position& knot, const position previous,
                 const position previous_dir)
{
  int32_t dx = previous.first - knot.first;
  int32_t dy = previous.second - knot.second;

  if (!(abs(dx) > 1 || abs(dy) > 1))  // tail doesnt need to move
  {
    return;
  }

  // move tail in the direction of head
  if (abs(dx) > 0 && dy == 0)  // simple horiziontal move
  {
    knot.first += previous_dir.first;
  } else if (abs(dy) > 0 && dx == 0)  // simple vertical move
  {
    knot.second += previous_dir.second;
  } else if (abs(dx) > 0 && abs(dy) > 0)  // diagonal move
  {
    knot.first += 1 * sign(dx);
    knot.second += 1 * sign(dy);
  }
}

int32_t solve1(const std::vector<move>& moves)
{
  std::map<position, int32_t> heatmap;
  position head = std::make_pair(0, 0);
  position tail = std::make_pair(0, 0);

  heatmap[tail] = 1;

  for (move m : moves)
  {
    position dir;
    switch (m.first)
    {
      case 'L':
        dir = std::make_pair(-1, 0);
        break;
      case 'R':
        dir = std::make_pair(1, 0);
        break;
      case 'U':
        dir = std::make_pair(0, 1);
        break;
      case 'D':
        dir = std::make_pair(0, -1);
        break;
      default:
        std::cerr << "this rly shouldnt happen: " << m.first << std::endl;
    }

    for (int32_t step = 0; step < m.second; step++)
    {
      head.first += dir.first;
      head.second += dir.second;
      update_knot(tail, head, dir);
      heatmap[tail] += 1;
    }
  }

  return heatmap.size();
}
int32_t solve2(const std::vector<move>& moves)
{
  std::map<position, int32_t> heatmap;
  std::vector<position> rope(10, std::make_pair(0, 0));
  position head = std::make_pair(0, 0);

  for (move m : moves)
  {
    position dir;
    switch (m.first)
    {
      case 'L':
        dir = std::make_pair(-1, 0);
        break;
      case 'R':
        dir = std::make_pair(1, 0);
        break;
      case 'U':
        dir = std::make_pair(0, 1);
        break;
      case 'D':
        dir = std::make_pair(0, -1);
        break;
      default:
        std::cerr << "this rly shouldnt happen: " << m.first << std::endl;
    }

    for (int32_t step = 0; step < m.second; step++)
    {
      head.first += dir.first;
      head.second += dir.second;

      position previous = head;
      position previous_dir = dir;
      for (size_t idx = 0; idx < rope.size(); idx++)
      {
        position& p = rope[idx];
        const position p_previous = p;
        update_knot(p, previous, previous_dir);
        previous = p_previous;
        previous_dir = std::make_pair(p.first - p_previous.first,
                                      p.second - p_previous.second);
      }

      heatmap[rope[rope.size()-1]] += 1;
    }
  }

  return heatmap.size();
}

int main()
{
  /*                               Input                                    */
  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day9.txt");

  if (!input_file.is_open()) return -1;

  std::vector<move> moves;
  std::string line;
  while (getline(input_file, line))
  {
    char dir = line[0];
    int length = std::stoi(line.substr(1, line.length() - 1));

    moves.push_back(std::make_pair(dir, length));
  }

  input_file.close();
  /*                              Test                                       */
  std::string test_lines[] = {"R 5 ", "U 8 ", "L 8 ", "D 3 ",
                              "R 17", "D 10", "L 25", "U 20"};

  std::vector<move> test_moves;
  for (std::string line : test_lines)
  {
    char dir = line[0];
    int length = std::stoi(line.substr(1, line.length() - 1));

    test_moves.push_back(std::make_pair(dir, length));
  }

  int32_t test_result = solve2(test_moves);
  std::cout << "Test result: " << test_result << std::endl;

  /*                              Calculate                                  */
  auto res1 = solve1(moves);
  auto res2 = solve2(moves);

  /*                              Output                                     */

  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
