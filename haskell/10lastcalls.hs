store :: Eq a => a -> [a] -> [a]
store c l = take 10 (c : filter (/=c) l)