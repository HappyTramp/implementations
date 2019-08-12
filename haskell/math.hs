main = do
    print (factorial' 4)
    print (2 `pow` 4)
    print (fibonacci 6)
    print (is_prime 41)

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

trial_division :: Int -> Int -> [Int]
trial_division by x
    | x <= 1 = []
    | x `mod` by == 0 = by:trial_division by (x `div` by)
    | otherwise = trial_division (by + 1) x

is_prime :: Int -> Bool
is_prime 0 = False
is_prime 1 = False
is_prime 2 = True
is_prime 3 = True
is_prime x
    | x `mod` 2 == 0 || x `mod` 3 == 0 = False
    | otherwise = div_check 5
    where div_check d
            | d * d > x = True
            | x `mod` d == 0 || x `mod` (d + 2) == 0 = False
            | otherwise = div_check (d + 6)

eratos_sieve :: [Int] -> [Int]
eratos_sieve [] = []
eratos_sieve (x:xs)
    | x * x > last xs = x:xs
    | otherwise = x:eratos_sieve [n | n <- xs, n `mod` x /= 0]

nth_prime :: Int -> Int
nth_prime n = nth_check n 0
    where nth_check n x
            | is_prime x = if n == 0 then x else nth_check (n - 1) (x + 1)
            | otherwise = nth_check n (x + 1)
