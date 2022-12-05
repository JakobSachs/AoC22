--                   ___         ______   ___   ____ ___  ___                --
--                  /   | ____  / ____/  |__ \ / __ \__ \|__ \               --
--                 / /| |/ __ \/ /       __/ // / / /_/ /__/ /               --
--                / ___ / /_/ / /___    / __// /_/ / __// __/                --
--               /_/  |_\____/\____/   /____/\____/____/____/                --
--                                                                           --

--                                   Day 5                                   --

import Data.List

initStacks :: [[Char]]
initStacks =
  [ ['C', 'F', 'B', 'L', 'D', 'P', 'Z', 'S'],
    ['B', 'W', 'H', 'P', 'G', 'V', 'N'],
    ['G', 'J', 'B', 'W', 'F'],
    ['S', 'C', 'W', 'L', 'F', 'N', 'J', 'G'],
    ['H', 'S', 'M', 'P', 'T', 'L', 'J', 'W'],
    ['S', 'F', 'G', 'W', 'C', 'B'],
    ['W', 'B', 'Q', 'M', 'P', 'T', 'H'],
    ['T', 'W', 'S', 'F'],
    ['R', 'C', 'N']
  ]

replaceElement :: Int -> [Char] -> [[Char]] -> [[Char]]
replaceElement idx elem lst =
  let (prev, _ : after) = splitAt idx lst
   in prev ++ [elem] ++ after

performMove9000er :: [[Char]] -> (Int, Int, Int) -> [[Char]]
performMove9000er stacks (crateCount, from, to) =
  let cratesBeingMoved = reverse $ take crateCount $ stacks !! from
      newFromStack = drop crateCount $ stacks !! from
      newToStack = cratesBeingMoved ++ stacks !! to
      semiNewStacks = replaceElement from newFromStack stacks
   in replaceElement to newToStack semiNewStacks

performMove9001er :: [[Char]] -> (Int, Int, Int) -> [[Char]]
performMove9001er stacks (crateCount, from, to) =
  let cratesBeingMoved = take crateCount $ stacks !! from
      newFromStack = drop crateCount $ stacks !! from
      newToStack = cratesBeingMoved ++ stacks !! to
      semiNewStacks = replaceElement from newFromStack stacks
   in replaceElement to newToStack semiNewStacks

parseMove :: String -> (Int, Int, Int)
parseMove txt =
  let [_, crateCount, _, from, _, to] = words txt
   in (read crateCount, read from -1, read to -1)

getTopBoxes :: [[Char]] -> [Char]
getTopBoxes stacks =
  map head stacks

main :: IO ()
main = do
  input <- fmap lines $ readFile "../../data/day5.txt"
  let moves = map parseMove input

  putStrLn $ "Solution 1:\t" ++ ( getTopBoxes $ foldl performMove9000er initStacks moves )
  putStrLn $ "Solution 2:\t" ++ ( getTopBoxes $ foldl performMove9001er initStacks moves )

