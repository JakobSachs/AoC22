/*                 ___         ______   ___   ____ ___  ___                   */
/*                /   | ____  / ____/  |__ \ / __ \__ \|__ \                  */
/*               / /| |/ __ \/ /       __/ // / / /_/ /__/ /                  */
/*              / ___ / /_/ / /___    / __// /_/ / __// __/                   */
/*             /_/  |_\____/\____/   /____/\____/____/____/                   */
/*                                                                            */

/*                                  DAY 2                                     */

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <chrono>
#include <utility>
#include <vector>

int32_t get_score(char opponent, char player)
{
  int diff = ((int) opponent - (int) 'A') - ((int) player - (int) 'X');
  int32_t score = (int) player - (int) 'X' + 1;
  switch (diff)
  {
    case 0:
      score += 3;
      break;
    case -1:
      score += 6;
      break;
    case 1:
      score += 0;
      break;
    case -2:
      score += 0;
      break;
    case 2:
      score += 6;
      break;
  }

  return score;
}

int32_t get_fixed_score(char opponent, char fixed_result)
{
  char player_choice = 'X';
  const int offset = ('X' - 'A');

  switch (fixed_result)
  {
    case 'Y':  // draw
      player_choice = opponent + offset;
      break;
    case 'X':  // lose
      if (opponent == 'A') // cant think of a more generic solution on the spot
        player_choice = 'Z';
      else
        player_choice = opponent - 1 + offset;
      break;
    case 'Z':
      if (opponent == 'C')
        player_choice = 'X';
      else
        player_choice = opponent + 1 + offset;
  }

  return get_score(opponent, player_choice);
}

int32_t solve1(std::vector<std::pair<char, char>>
                   file_content)  // Solution for the second part
{
  int32_t total_score = 0;
  for (auto game : file_content)
    total_score += get_score(game.second, game.first);
  return total_score;
}

int32_t solve2(std::vector<std::pair<char, char>>
                   file_content)  // Solution for the second part

{
  int32_t total_score = 0;
  for (auto game : file_content)
    total_score += get_fixed_score(game.second, game.first);
  return total_score;
}

int main()
{
  /*                               Input                                    */

  auto start_time = std::chrono::high_resolution_clock::now();
  std::ifstream input_file("../../data/day2.txt");

  if (!input_file.is_open()) return -1;

  std::string line;
  std::vector<std::pair<char, char>> file_content;

  while (getline(input_file, line))
  {
    char player = line.back();
    char opponent = line[0];
    auto pair = std::make_pair(player, opponent);

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
