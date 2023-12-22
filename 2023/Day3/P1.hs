import Data.List.Split (splitOn)

is_digit h
  | h == '0' = True
  | h == '1' = True
  | h == '2' = True 
  | h == '3' = True 
  | h == '4' = True 
  | h == '5' = True 
  | h == '6' = True 
  | h == '7' = True 
  | h == '8' = True 
  | h == '9' = True 
  | otherwise = False

get_y pos [] = []
get_y pos (h:t)
  | (is_digit h) = pos:(get_y (pos + 1) t)
  | otherwise = (get_y (pos + 1) t)

get_coords pos [] = []
get_coords pos (h:t) =
  [[pos, y] | y <- (get_y 0 h)] ++ (get_coords (pos + 1) t)

get_y_symbol pos [] = []
get_y_symbol pos (h:t)
  | (is_digit h) = (get_y_symbol (pos + 1) t)
  | h /= '.' = pos:(get_y_symbol (pos + 1) t)
  | otherwise = (get_y_symbol (pos + 1) t)

get_coords_symbol pos [] = []
get_coords_symbol pos (h:t) =
  [[pos, y] | y <- (get_y_symbol 0 h)] ++ (get_coords_symbol (pos + 1) t)

get_x_ (x:_) = x
get_y_ (_:t) = (head t)

check_adyacent coord_sym coord_digit
  | (abs ((get_x_ coord_sym) - (get_x_ coord_digit))) <= 1 && (abs ((get_y_ coord_sym) - (get_y_ coord_digit))) <= 1 = True
  | otherwise = False

get_valid_coord coord_sym l =
  [coord_digit | coord_digit <- l, (check_adyacent coord_sym coord_digit)]

all_valid_coords [] l = []
all_valid_coords (h:t) l = (get_valid_coord h l) ++ (all_valid_coords t l)

get_num_in_row y pos num flag [] = num
get_num_in_row y pos num flag (h:t)
  | (is_digit h) =
    if pos == y && flag == False
      then (get_num_in_row y (pos + 1) (num ++ [h]) True t)
      else (get_num_in_row y (pos + 1) (num ++ [h]) flag t)
  | otherwise =
    if flag == True
      then num
      else (get_num_in_row y (pos + 1) [] flag t)

get_row_num x pos [] = []
get_row_num x pos (h:t)
  | x == pos = h
  | otherwise = (get_row_num x (pos + 1) t)

get_num_by_coord coord l =
  (get_num_in_row (get_y_ coord) 0 [] False (get_row_num (get_x_ coord) 0 l))

check_same_num y1 y2 pos flag (h:t)
  | y1 == pos = (check_same_num y1 y2 (pos + 1) True t)
  | flag == True && (is_digit h) && y2 == pos = True
  | flag == True && (is_digit h) = (check_same_num y1 y2 (pos + 1) flag t)
  | flag == True = False
  | otherwise = (check_same_num y1 y2 (pos + 1) flag t)

check_same_num_coords coord1 coord2 l
  | (get_x_ coord1) /= (get_x_ coord2) = False
  | otherwise =
    if (get_y_ coord1) < (get_y_ coord2)
      then (check_same_num (get_y_ coord1) (get_y_ coord2) 0 False (get_row_num (get_x_ coord1) 0 l))
      else (check_same_num (get_y_ coord2) (get_y_ coord1) 0 False (get_row_num (get_x_ coord1) 0 l))

unique_coords [] l result = result
unique_coords (h:t) l result
  | [x | x <- result, (check_same_num_coords h x l)] == [] =
    (unique_coords t l (result ++ [h]))
  | otherwise = (unique_coords t l result)

main = do
  cont <- getContents
  let cont_split = (init (splitOn "\n" cont))
  let res = sum [read (get_num_by_coord x cont_split) :: Int | x <- (unique_coords (all_valid_coords (get_coords_symbol 0 cont_split) (get_coords 0 cont_split)) cont_split [])]
  print res
