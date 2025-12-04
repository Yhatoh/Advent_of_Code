import Data.List.Split

onlydigits s = [c | c <- s, c >= '0' && c <= '9']

combine s = if s == [] 
               then "0"
               else [(head s), (last s)]

to_num s = read s :: Int

replace :: String -> String
replace ('o':'n':'e':'i':t) = '1':'e':'i':replace t
replace ('o':'n':'e':t) = '1':replace t
replace ('t':'w':'o':'n':t) = '2':'o':'n':replace t
replace ('t':'w':'o':t) = '2':replace t

replace ('t':'h':'r':'e':'e':'i':t) = '3':'e':'i':replace t
replace ('t':'h':'r':'e':'e':t) = '3':replace t

replace ('f':'o':'u':'r':t) = '4':replace t

replace ('f':'i':'v':'e':'i':t) = '5':'e':'i':replace t
replace ('f':'i':'v':'e':t) = '5':replace t

replace ('s':'i':'x':t) = '6':replace t

replace ('s':'e':'v':'e':'n':'i':t) = '7':'n':'i':replace t
replace ('s':'e':'v':'e':'n':t) = '7':replace t

replace ('e':'i':'g':'h':'t':'h':t) = '8':'t':'h':replace t
replace ('e':'i':'g':'h':'t':'w':t) = '8':'t':'w':replace t
replace ('e':'i':'g':'h':'t':t) = '8':replace t

replace ('n':'i':'n':'e':'i':t) = '9':'e':'i':replace t
replace ('n':'i':'n':'e':t) = '9':replace t

replace (h:t) = h:replace t
replace "" = ""

suma l = sum [to_num (combine (onlydigits (replace (replace x)))) | x <- l]

main = do
  cont <- getContents
  let res = suma (splitOn "\n" cont)
  print res
