import Data.List.Split (splitOn)

get_id ('G':'a':'m':'e':' ':x:':':_) = [x]
get_id ('G':'a':'m':'e':' ':x:y:':':_) = [x, y]
get_id ('G':'a':'m':'e':' ':x:y:z:':':_) = [x, y, z]
get_id (_) = "0"

split_ :: String -> [[String]]
split_ text = map (splitOn ",") (splitOn ";" text)

remv_space (_:t) = t
remv_space t = t
remv_all_space [] = []
remv_all_space (h:t) = (map remv_space h):(remv_all_space t)

split_num_color [] = []
split_num_color (h:t) = (map (splitOn " ") h):(split_num_color t)

to_num x = read x :: Int

check [] = True
check ([""]:t) = False
check ([num,color]:t)
  | color == "blue" && (to_num num) > 14 = False
  | color == "red" && (to_num num) > 12 = False
  | color == "green" && (to_num num) > 13 = False
  | otherwise = (check t)


checkall l = [(check c) | c <- l]

game s = (checkall (split_num_color (remv_all_space (split_ s))))
allgames l = (map game l)

remove_game [] = []
remove_game (_:_:_:_:_:_:':':t) = t
remove_game (_:_:_:_:_:_:_:':':t) = t
remove_game (_:_:_:_:_:_:_:_:':':t) = t

all_true [] = True
all_true (True:t) = all_true t
all_true (False:t) = False

main = do
  cont <- getContents
  let res = sum [read a :: Int | (a, b) <- (zip (map get_id (splitOn "\n" cont)) (allgames (map remove_game (splitOn "\n" cont)))), all_true b]
  print res
