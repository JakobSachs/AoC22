import Data.List
import Data.List.Split

main :: IO ()
main = do
  input <- fmap lines $ readFile "../../data/day1.txt"
  let chunks = splitOn [""] input
  let calories = reverse . sort $ map (sum . map read) chunks :: [Int]

  putStrLn $ "Solution 1:\t" ++ show (head calories)
  putStrLn $ "Solution 2:\t"++ show (sum $ take 3 calories)
