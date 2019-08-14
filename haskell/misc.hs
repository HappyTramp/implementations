main = do
    -- print (maximum [x * y | x <- [0..999], y <- [0..999], is_palindrome (x * y)])
    -- print (take 10 [1,10..])
    -- print (bsearch (take 10 [1,10..]) 82)
    -- print (count_in_sorted [1,2,3,3,5,5,5,5,5,9,9,11] 5)
    print (bsearch [1,2,3,3,5,5,5,5,5,9,9,11] 5)
    -- print (bsearchr [1,2,3,3,5,5,5,5,5,9,9,11] 2)

is_palindrome :: Int -> Bool
is_palindrome x = (show x) == (rev' (show x))

rev' :: [a] -> [a]
rev' [] = []
rev' (x:xs) = (rev' xs) ++ [x]

bsearch :: (Ord a) => [a] -> a -> Int
bsearch haystack needle = bsearch_range 0 (length haystack)
    where bsearch_range lo hi | lo >= hi = -1
          bsearch_range lo hi = case haystack !! mid `compare` needle of
                GT -> bsearch_range lo (mid - 1)
                LT -> bsearch_range (mid + 1) hi
                EQ -> mid
            where mid = (hi + lo) `div` 2

-- bsearchr :: (Ord a) => [a] -> a -> Int
-- bsearchr haystack needle = bsearchr_range 0 (length haystack)
--     where bsearchr_range :: Int -> Int -> Int
--           bsearchr_range lo hi
--             | lo >= hi = -1
--             | haystack_mid > needle = bsearchr_range lo (mid - 1)
--             | haystack_mid < needle = bsearchr_range (mid + 1) hi
--             | haystack_mid == needle = if mid_1 == -1 then mid else mid_1 + 1
--             where haystack_mid = haystack !! mid
--                   mid = (hi + lo) `div` 2
--                   mid_1 = bsearchr_range (mid + 1) hi

-- count_in_sorted :: (Ord a) => [a] -> a -> Int
-- count_in_sorted haystack needle = (bsearch haystack needle) - (bsearchr haystack needle) + 1
