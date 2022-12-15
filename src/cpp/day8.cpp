/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 8                                     */

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cassert>
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

std::pair<int32_t, int32_t> solve(std::vector<std::vector<uint32_t>>& tree_map)
{
  const auto height = tree_map.size();
  const auto width = tree_map[0].size();

  int32_t visible_count = height * width;
  int32_t max_scenic_score = 0;
  for (int32_t y = 1; y < height - 1; y++)
  {
    for (int32_t x = 1; x < width - 1; x++)
    {
      // checking if tree_map[y][x] is visible
      bool is_visible[] = {true, true, true, true};
      // track viewing distances for scenic score
      int32_t view_distances[4] = {0};

      // check view up
      for (int32_t i = y; i >= 0; i--)
      {
        if (i == 0)
        {
          view_distances[0] = y;
          break;
        }
        if (tree_map[y][x] <= tree_map[i - 1][x])
        {
          is_visible[0] = false;
          view_distances[0] = abs(y - i) + 1;
          break;
        }
      }

      // check view down
      for (int32_t i = y; i < height; i++)
      {
        if (i == height - 1)
        {
          view_distances[1] = abs(y - i);
          break;
        }
        if (tree_map[y][x] <= tree_map[i + 1][x])
        {
          is_visible[1] = false;
          view_distances[1] = abs(y - i) + 1;
          break;
        }
      }

      // check view left
      for (int32_t j = x; j >= 0; j--)
      {
        if (j == 0)
        {
          view_distances[2] = x;
          break;
        }
        if (tree_map[y][x] <= tree_map[y][j - 1])
        {
          is_visible[2] = false;
          view_distances[2] = abs(x - j) + 1;
          break;
        }
      }

      // check view right
      for (int32_t j = x; j < width; j++)
      {
        if (j == width - 1)
        {
          view_distances[3] = abs(x - j);
          break;
        }

        if (tree_map[y][x] <= tree_map[y][j + 1])
        {
          is_visible[3] = false;
          view_distances[3] = abs(x - j) + 1;
          break;
        }
      }

      if (!(is_visible[0] || is_visible[1] || is_visible[2] || is_visible[3]))
        visible_count--;

      for (int i = 0; i < 4; i++) assert(view_distances[i] >= 0);

      max_scenic_score =
          std::max(max_scenic_score, view_distances[0] * view_distances[1] *
                                         view_distances[2] * view_distances[3]);
    }
  }

  return std::make_pair(visible_count, max_scenic_score);
}

int main()
{
  /*                               Input                                    */
  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day8.txt");

  if (!input_file.is_open()) return -1;

  std::string line;
  std::vector<std::vector<uint32_t>> tree_map;
  while (getline(input_file, line))
  {
    std::vector<uint32_t> row;
    for (char c : line) row.push_back(atoi(&c));
    tree_map.push_back(row);
  }

  input_file.close();
  /*                              Calculate                                  */
  auto res = solve(tree_map);
  auto res1 = res.first;
  auto res2 = res.second;
  /*                              Output                                     */

  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
