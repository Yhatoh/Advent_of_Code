import Data.List.Split (splitOn)

split_ :: String -> [[String]]
split_ text = map (splitOn ",") (splitOn ";" text)

remv_space (_:t) = t
remv_space t = t
remv_all_space [] = []
remv_all_space (h:t) = (map remv_space h):(remv_all_space t)

split_num_color [] = []
split_num_color (h:t) = (map (splitOn " ") h):(split_num_color t)

to_num x = read x :: Int

num_by_color c [] = 0
num_by_color c ([""]:t) = 0
num_by_color c ([num,color]:t)
  | color == c = (to_num num)
  | color == c = (to_num num)
  | color == c = (to_num num)
  | otherwise = (num_by_color c t)

maximum_color c s =
  maximum [num_by_color c x | x <- (split_num_color (remv_all_space (split_ s)))]

all_max s = [(maximum_color "green" x) * (maximum_color "blue" x) * (maximum_color "red" x) | x <- s]

remove_game [] = []
remove_game (_:_:_:_:_:_:':':t) = t
remove_game (_:_:_:_:_:_:_:':':t) = t
remove_game (_:_:_:_:_:_:_:_:':':t) = t

main = do
  cont <- getContents
  let res = sum (all_max (map remove_game (splitOn "\n" cont)))
  print res
