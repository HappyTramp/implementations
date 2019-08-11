main = do
    print (factorial' 4)
    print (2 `pow` 4)
    print (fibonacci 6)
    -- print (is_prime 4)

factorial' :: Int -> Int
factorial' 0 = 1
factorial' x = x * (factorial' (x - 1))

pow :: Int -> Int -> Int
pow base 0 = 1
pow base exp = base * pow base (exp - 1)

fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci 2 = 1
fibonacci x =  fibonacci (x - 1) + fibonacci (x - 2)

-- is_prime :: Int -> Bool
-- is_prime x
--     | x <= 1 = False
--     | x <= 3 = True
--     | x `mod` 2 == 0 = False
--     | x `mod` 3 == 0 = False
-- is_prime x =
