main = do
    print (mergesort [1, 4, 2, -10, 6, 7, 2])
    print (quicksort [1, 4, 2, -10, 6, 7, 2])

mergesort :: (Ord a) => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge_list (mergesort left) (mergesort right)
    where mid = length xs `div` 2
          left = take mid xs
          right = drop mid xs

merge_list :: (Ord a) => [a] -> [a] -> [a]
merge_list xs [] = xs
merge_list [] ys = ys
merge_list (x:xs) (y:ys)
    | x < y     = x:(merge_list xs (y:ys))
    | otherwise = y:(merge_list (x:xs) ys)

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort [x] = [x]
quicksort (x:xs) = (quicksort lower) ++ [x] ++ (quicksort upper)
    where lower = [l | l <- xs, l < x]
          upper = [l | l <- xs, l >= x]
