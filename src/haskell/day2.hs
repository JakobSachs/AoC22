--                   ___         ______   ___   ____ ___  ___                --
--                  /   | ____  / ____/  |__ \ / __ \__ \|__ \               --
--                 / /| |/ __ \/ /       __/ // / / /_/ /__/ /               --
--                / ___ / /_/ / /___    / __// /_/ / __// __/                -- 
--               /_/  |_\____/\____/   /____/\____/____/____/                --
--                                                                           -- 


--                                   Day 2                                   --

import Data.List
import Data.List.Split

newtype Game = Game (Char, Char)


main :: IO ()
main = do
  input <- fmap lines $ readFile "../../data/day2.txt"
  putStrLn $ "Solution 1:\t" 
  putStrLn $ "Solution 2:\t"
