/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 5                                     */

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

std::string solve1(std::vector<std::vector<int32_t>> moves,
                   std::vector<std::deque<char>> stacks)
{
  for (auto move : moves)
  {
    std::vector<char> crates_being_moved;

    for (size_t crate_counter = 0; crate_counter < move[0]; crate_counter++)
    {
      crates_being_moved.push_back(stacks[move[1] - 1].front());
      stacks[move[1] - 1].pop_front();
    }

    for (char crate : crates_being_moved) stacks[move[2] - 1].push_front(crate);
  }
  std::string output;

  for (size_t stack_idx = 0; stack_idx < 9; stack_idx++)
  {
    if (!stacks[stack_idx].empty())
    {
      char c = stacks[stack_idx].front();
      output.push_back(c);
    }
  }
  return output;
}

std::string solve2(std::vector<std::vector<int32_t>> moves,
                   std::vector<std::deque<char>> stacks)
{
  for (auto move : moves)
  {
    std::vector<char> crates_being_moved;

    for (size_t crate_counter = 0; crate_counter < move[0]; crate_counter++)
    {
      crates_being_moved.push_back(stacks[move[1] - 1].front());
      stacks[move[1] - 1].pop_front();
    }

    // easy and lazy way to reuse solution
    std::reverse(crates_being_moved.begin(), crates_being_moved.end());

    for (char crate : crates_being_moved) stacks[move[2] - 1].push_front(crate);
  }
  std::string output;

  for (size_t stack_idx = 0; stack_idx < 9; stack_idx++)
  {
    if (!stacks[stack_idx].empty())
    {
      char c = stacks[stack_idx].front();
      output.push_back(c);
    }
  }
  return output;
}

int main()
{
  /*                               Input                                    */

  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day5.txt");

  if (!input_file.is_open()) return -1;

  const std::vector<std::deque<char>> stacks = {
      {'C', 'F', 'B', 'L', 'D', 'P', 'Z', 'S'},
      {'B', 'W', 'H', 'P', 'G', 'V', 'N'},
      {'G', 'J', 'B', 'W', 'F'},
      {'S', 'C', 'W', 'L', 'F', 'N', 'J', 'G'},
      {'H', 'S', 'M', 'P', 'T', 'L', 'J', 'W'},
      {'S', 'F', 'G', 'W', 'C', 'B'},
      {'W', 'B', 'Q', 'M', 'P', 'T', 'H'},
      {'T', 'W', 'S', 'F'},
      {'R', 'C', 'N'}};

  std::string line;
  std::vector<std::vector<int32_t>> moves;

  while (getline(input_file, line))
  {
    std::vector<int32_t> move(3);

    sscanf(line.c_str(), "move %d from %d  to %d", &move[0], &move[1],
           &move[2]);

    moves.push_back(move);
  }

  input_file.close();
  /*                              Calculate                                  */
  auto res1 = solve1(moves, stacks);
  auto res2 = solve2(moves, stacks);

  /*                              Output                                     */

  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;

  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return 0;
}
