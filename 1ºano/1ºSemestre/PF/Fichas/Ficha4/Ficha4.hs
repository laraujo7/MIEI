import Data.Char

--1ºa
firstA = [x | x <- [1..20], mod x 2 == 0, mod x 3 == 0] -- > [6,12,18]

num23 :: Int -> Int -> [Int]
num23 x y | x==y = []
          | x/=y && mod x 2 == 0 && mod x 3 == 0 = x : num23 (x+1) y
          | otherwise = num23 (x+1) y

--1ºb
firstB = [x | x <- [y | y <- [1..20], mod y 2 == 0], mod x 3 == 0] -- > [6,12,18]

--1ºc
firstC = [(x,y) | x <- [0..20], y <- [0..20], x+y == 30] -- > [(10,20),(20,10),(15,15),(14,16),(13,17),(12,18),(11,19),(16,14),(17,13),(18,12),(19,11)]

--1ºd
firstD = [sum [y | y <- [1..x], odd y] | x <- [1..10]] -- > [1,1,4,4,9,9,16,16,25,25]

--2ºa --> [1,2,4,8,16,32,64,128,256,512,1024]
doisA = [2^x | x <- [0..10]]

--2ºb --> [(1,5),(2,4),(3,3),(4,2),(5,1)]
doisB = [(x,y) | x <- [1..5], y <- [1..5], x+y==6]

--2ºc --> [[1],[1,2],[1,2,3],[1,2,3,4],[1,2,3,4,5]]
doisC = [[1..x] | x <- [1..5]] 

--2ºd --> [[1],[1,1],[1,1,1],[1,1,1,1],[1,1,1,1,1]]
doisD = [[1 | y <- [1..x]] | x <- [1..5]]

--2ºe --> [1,2,6,24,120,720]
--doisE = [x*y | x <- [1] , y <- [1,2,6,24,12,720]]

--3º
digitAlpha :: String -> (String,String)
digitAlpha [] = ([],[])
digitAlpha (h:t) | isDigit h = (h:l1,l2)
                 | isAlpha h = (l1,h:l2)
                 | otherwise = digitAlpha t
                 where (l1,l2) = digitAlpha t 


--4º
nzp :: [Int] -> (Int,Int,Int)
nzp [] = (0,0,0)
nzp (h:t) | h < 0 = ((x+1),y,z)
          | h==0 = (x,(y+1),z)
          | h > 0 = (x,y,(z+1))
          where (x,y,z) = nzp t 

--5º
divMod' :: Integral a => a -> a -> (a, a) 
divMod' x y = (divisao x y,resto x y)

divisao :: Integral a => a -> a -> a
divisao x y | x<y = 0
            | otherwise = 1 + divisao (x-y) y

resto :: Integral a => a -> a -> a
resto x y | x<y = x
          | x>y = resto (x-y) y

--6º
fromDigits :: [Int] -> Int
fromDigits [] = 0
fromDigits (h:t) = fromDaux h (length t) + fromDigits t

fromDaux :: Int -> Int -> Int
fromDaux x 0 = x
fromDaux x y = x*10^y

--7º
maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit l = sum (last (inits' l))

inits' :: [a] -> [[a]]
inits' l = reverse (auxin l)

auxin :: [a] -> [[a]]
auxin [] = [[]]
auxin l = l:auxin (take (length l-1) l)

--8º
--fib :: Int -> Int
--fib 0 = 0
--fib 1 = 1
--fib n = fibAux 0 n
















