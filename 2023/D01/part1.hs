import Data.List.Split

onlydigits s = [c | c <- s, c >= '0' && c <= '9']

combine s = if s == [] 
               then "0"
               else [(head s), (last s)]

to_num s = read s :: Int

suma l = sum [to_num (combine (onlydigits x)) | x <- l]

main = do
  cont <- getContents
  let res = suma (splitOn "\n" cont)
  print res
