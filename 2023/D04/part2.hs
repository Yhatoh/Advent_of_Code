import Data.List.Split (splitOn)
import Data.List (group)
import qualified Data.Map as Map
import Data.Map.Strict (insertWith)
import Data.List (foldl')
import Data.List (sort, group)
import Data.Maybe (fromMaybe)

check_in num [] = False
check_in num (h:t)
  | h == num = True
  | otherwise = (check_in num t)

get_winners winners my_nums =
  [num | num <- my_nums, (check_in num winners)]

matching winners my_nums
  | (length (get_winners winners my_nums)) == 0 = 0
  | otherwise = (length (get_winners winners my_nums))

split_nums l = [read x :: Int | x <- (splitOn " " l)]

generate id winners my_nums =
  [(id+1)..(id + (matching winners my_nums))]

all_generate id [] = []
all_generate id (h:t) =
  [(generate id (split_nums (head h)) (split_nums (last h)))] ++ (all_generate (id + 1) t)

remove_card ('C':'a':'r':'d':' ':x:':':t) = t
remove_card ('C':'a':'r':'d':' ':x:y:':':t) = t
remove_card ('C':'a':'r':'d':' ':x:y:z:':':t) = t

removeExtraSpaces :: String -> String
removeExtraSpaces = unwords . words

countFrequency :: Ord a => [a] -> Map.Map a Int
countFrequency = foldl' (\accMap x -> Map.insertWith (+) x 1 accMap) Map.empty

updateValues :: Ord k => Map.Map k Int -> Int -> [k] -> Map.Map k Int
updateValues myMap amount keys = foldl (\accMap key -> Map.insertWith (+) key amount accMap) myMap keys

counting :: Int -> Map.Map Int Int -> [[Int]] -> Map.Map Int Int
counting card newMap generator
    | card > length generator = newMap
    | otherwise = counting (card + 1) updatedMap generator
    where
        currentList = generator !! (card - 1)
        updatedMap = updateValues newMap (Map.findWithDefault 0 card newMap) currentList

sumMapValues :: Map.Map Int Int -> Int
sumMapValues resultMap = Map.foldl' (+) 0 resultMap

main = do
  cont <- getContents
  let splited = all_generate 1 [(splitOn " | " (removeExtraSpaces (remove_card (removeExtraSpaces l)))) | l <- (init (splitOn "\n" cont))]
  let freq = (countFrequency [1..(length splited)])
  let res = (counting 1 freq splited)
  print (sumMapValues res)
