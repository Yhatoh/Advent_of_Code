import Data.List.Split (splitOn)
import Data.List (group)

check_in num [] = False
check_in num (h:t)
  | h == num = True
  | otherwise = (check_in num t)

get_winners winners my_nums =
  [num | num <- my_nums, (check_in num winners)]

expo two e
  | e == 0 = two
  | otherwise = (expo (two * 2) (e - 1))

worth winners my_nums
  | (length (get_winners winners my_nums)) == 0 = 0
  | otherwise = (expo 1 ((length (get_winners winners my_nums)) - 1))

split_nums l = [read x :: Int | x <- (splitOn " " l)]

sum_worth cards =
  sum [(worth (split_nums (head card)) (split_nums (last card))) | card <- cards]

remove_card ('C':'a':'r':'d':' ':x:':':t) = t
remove_card ('C':'a':'r':'d':' ':x:y:':':t) = t
remove_card ('C':'a':'r':'d':' ':x:y:z:':':t) = t

removeExtraSpaces :: String -> String
removeExtraSpaces = unwords . words

main = do
  cont <- getContents
  let splited = sum_worth [(splitOn " | " (removeExtraSpaces (remove_card (removeExtraSpaces l)))) | l <- (init (splitOn "\n" cont))]
  print splited
