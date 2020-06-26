import Data.List
import Data.Char
import Debug.Trace


{-------------------- 50 Questões PF --------------------}

--1
enumFromTo' :: Int -> Int -> [Int]
enumFromTo' x y | x == y = [x]
                | otherwise = (min x y) : enumFromTo' ((min x y)+1) (max x y)

--2 
enumFromThenTo' :: Int -> Int -> Int -> [Int]
enumFromThenTo' x y z | (min x y) > z = []
                      | (min x y) == z = [min x y]
                      | otherwise = (min x y) : enumFromThenTo' (x + ((max x y) - (min x y))) (y + ((max x y) - (min x y))) z

--3
junta :: [a] -> [a] -> [a]
junta [] l = l
junta l [] = l
junta l ls = l++ls

--4
posicao :: [a] -> Int -> a
posicao (h:t) 0 = h
posicao (h:t) x = posicao t (x-1)

--5
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (h:t) = reverse' t ++ [h]

--6
take' :: Int -> [a] -> [a]
take' _ [] = []
take' 0 _ = []
take' x (h:t) = h : take' (x-1) t

--7
drop' :: Int -> [a] -> [a]
drop' _ [] = []
drop' 0 l = l
drop' x (h:t) = drop' (x-1) t

--8
zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (h:t) (x:xs) = (h,x) : zip' t xs

--9
elem' :: Eq a => a -> [a] -> Bool
elem' _ [] = False
elem' x (h:t) | x == h = True
              | otherwise = elem' x t

--10
replicate' :: Int -> a -> [a]
replicate' 0 a = []
replicate' x a = a : replicate (x-1) a

--11
intersperse' :: a -> [a] -> [a]
intersperse' a [] = [a]
intersperse' a [x] = [x]
intersperse' a (h:t) = h:a : intersperse' a t

--12
group' :: Eq a => [a] -> [[a]]
group' [] = []
group' l@(h:t) = l1 : group' l2 where (l1,l2) = span (==h) l

--13
concat' :: [[a]] -> [a]
concat' [] = []
concat' (h:t) = h ++ concat' t

--14
inits' :: [a] -> [[a]]
inits' [] = [[]]
inits' l = inits' (take' (length l - 1) l) ++ [l]

--15
tails' :: [a] -> [[a]]
tails' [] = []
tails' l = [l] ++ tails' (drop' 1 l)

--16
isPrefixOf' :: Eq a => [a] -> [a] -> Bool
isPrefixOf' [] _ = True
isPrefixOf' _ [] = False
isPrefixOf' (h:t) (x:xs) | h == x = isPrefixOf' t xs
                         | otherwise = False

--17
isSufixOf' :: Eq a => [a] -> [a] -> Bool
isSufixOf' l ls = isPrefixOf' (reverse' l) (reverse' ls)

isSufixOf'' :: Eq a => [a] -> [a] -> Bool
isSufixOf'' l ls = isPrefixOf' l (drop (length ls - length l) ls)

--18
isSubsequenceOf' :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf' [] _ = True
isSubsequenceOf' _ [] = False
isSubsequenceOf' l@(h:t) (x:xs) | h == x = isSubsequenceOf' t xs
                              | otherwise = isSubsequenceOf' l xs

--19
elemIndices' :: Eq a => a -> [a] -> [Int]
elemIndices' x [] = []
elemIndices' x l = elemIAux x 0 l

elemIAux :: Eq a => a -> Int -> [a] -> [Int]
elemIAux x y [] = []
elemIAux x y (h:t) | x == h = y : elemIAux x (y+1) t
                   | otherwise = elemIAux x (y+1) t

--20
nub' :: Eq a => [a] -> [a]
nub' [] = []
nub' (h:t) = h : nub' (filter (/=h) (h:t))

--21
delete' :: Eq a => a -> [a] -> [a]
delete' _ [] = []
delete' x (h:t) | x == h = t
                | otherwise = h : delete' x t

--22
remove' :: Eq a => [a] -> [a] -> [a]
remove' [] l = []
remove' l [] = l  
remove' l (x:xs) = remove' (delete' x l) xs

--23
union' :: Eq a => [a] -> [a] -> [a]
union' [] l = l
union' l [] = l
union' l (h:t) | elem' h l = union' l t
               | otherwise = union' l t ++ [h]

--24
intersect' :: Eq a => [a] -> [a] -> [a]
intersect' [] _ = []
intersect' l [] = l
intersect' l (h:t) = filter (==h) l ++ intersect l t

--25
insert' :: Ord a => a -> [a] -> [a]
insert' x [] = [x]
insert' x (h:t) | x <= h = x:h:t
                | otherwise = h : insert' x t

--26
unwords' :: [String] -> String
unwords' [] = ""
unwords' [x] = x
unwords' (h:t) = h ++ " " ++ unwords' t

--27
unlines' :: [String] -> String
unlines' [] = ""
unlines' (h:t) = h ++ "\n" ++ unlines' t

--28
pMaior :: Ord a => [a] -> Int
pMaior l = pMaiorAux l 0

pMaiorAux :: Ord a => [a] -> Int -> Int
pMaiorAux l@(h:t) x | h == maximum l = x
                    | otherwise = pMaiorAux t (x+1)

--29
temRepetidos' :: Eq a => [a] -> Bool
temRepetidos' [] = False
temRepetidos' l@(h:t) | elem' h l = True
                    | otherwise = temRepetidos' t

--30
algarismos' :: [Char] -> [Char]
algarismos' [] = []
algarismos' (h:t) | isDigit h = h : algarismos' t
                  | otherwise = algarismos' t 

algarismos'' :: [Char] -> [Char]
algarismos'' l = filter (isDigit) l

--31
posImpares' :: [a] -> [a]
posImpares' [] = []
posImpares' [x] = []
posImpares' (h:x:t) = x : posImpares' t 

--32
posPares' :: [a] -> [a]
posPares' [] = []
posPares' [x] = [x]
posPares' (h:x:t) = h : posPares' t

--33
isSorted' :: Ord a => [a] -> Bool
isSorted' [] = True
isSorted' [x] = True
isSorted' (h:x:t) | h <= x = isSorted' t
                  | otherwise = False

--34
iSort' :: Ord a => [a] -> [a]
iSort' [] = []
iSort' (h:t) = insert' h (iSort' t)

--35
menor' :: String -> String -> Bool
menor' [] _ = True
menor' _ [] = False
menor' (h:t) (x:xs) | h == x = menor' t xs
                    | h < x = True
                    | otherwise = False

--36
elemMSet' :: Eq a => a -> [(a,Int)] -> Bool
elemMSet' x [] = False
elemMSet' x ((a,b):t) | x == a = True
                      | otherwise = elemMSet' x t

--37
lengthMSet' :: [(a,Int)] -> Int
lengthMSet' [] = 0
lengthMSet' l = sum (map (snd) l)
--lengthMSet' ((x,y):t) = y + lengthMSet' t

--38
convertMSet' :: [(a,Int)] -> [a]
convertMSet' [] = []
convertMSet' ((x,y):t) = (replicate' y x) ++ convertMSet' t

--39
insereMSet' :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet' a [] = [(a,1)]
insereMSet' a ((x,y):t) | a == x = (x,y+1):t
                        | otherwise = (x,y) : insereMSet' a t

--40
removeMSet' :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removeMSet' a [] = []
removeMSet' a ((x,y):t) | a == x && y == 1 = t
                        | a == x = (x,y-1):t
                        | otherwise = (x,y) : removeMSet' a t

--41
constroiMSet' :: Ord a => [a] -> [(a,Int)]
constroiMSet' [] = []
constroiMSet' (h:t) = (h,length (filter (==h) (h:t))) : constroiMSet' (filter (/=h) (h:t))

--42
partitionsEithers' :: [Either a b] -> ([a],[b])
partitionsEithers' [] = ([],[])
partitionsEithers' l = (leftAux l, rightAux l)
                      where leftAux ((Left x):t) = x : leftAux t
                            leftAux ((Right x):t) = leftAux t
                            leftAux _ = []
                            rightAux ((Left x):t) = rightAux t
                            rightAux ((Right x):t) = x : rightAux t
                            rightAux _ = [] 

--43
catMaybes' :: [Maybe a] -> [a]
catMaybes' [] = []
catMaybes' ((Just x):t) = x : catMaybes' t
catMaybes' ((Nothing):t) = catMaybes' t

--44
data Movimento = Norte | Sul | Este | Oeste
                  deriving Show

posicaoR :: (Int,Int) -> [Movimento] -> (Int,Int)
posicaoR (x,y) [] = (x,y)
posicaoR (x,y) (Norte:t) = posicaoR (x,y+1) t
posicaoR (x,y) (Sul:t) = posicaoR (x,y-1) t
posicaoR (x,y) (Este:t) = posicaoR (x+1,y) t
posicaoR (x,y) (Oeste:t) = posicaoR (x-1,y) t

--45
caminho' :: (Int,Int) -> (Int,Int) -> [Movimento]
caminho' (x,y) (a,b) | x < a = Este : caminho' (x+1,y) (a,b)
                     | x > a = Oeste : caminho' (x-1,y) (a,b)
                     | y < b = Norte : caminho' (x+1,y) (a,b)
                     | y > b = Sul : caminho' (x-1,y) (a,b)
                     | otherwise = []  

--46
vertical' :: [Movimento] -> Bool
vertical' [] = True
vertical' (Norte:t) = vertical' t
vertical' (Sul:t) = vertical' t
vertical _ = False

--47
data Posicao = Pos Int Int
                  deriving Show

maisCentral' :: [Posicao] -> Posicao
maisCentral' [x] = x
maisCentral' (h:x:t) | maisCAux h > maisCAux x = maisCentral' (h:t)
                     | otherwise = maisCentral' (x:t)

maisCAux :: Posicao -> Float
maisCAux (Pos x y) = sqrt (fromIntegral (x^2 + y^2))

--48
vizinhos' :: Posicao -> [Posicao] -> [Posicao]
vizinhos' x [] = []
vizinhos' (Pos x y) ((Pos a b):t) | (x,y) == (a+1,b) || (x,y) == (a-1,b) || (x,y) == (a,b+1) || (x,y) == (a,b-1) = (Pos a b) : vizinhos' (Pos x y) t
                                  | otherwise = vizinhos' (Pos x y) t

--49
mesmaOrdenada' :: [Posicao] -> Bool
mesmaOrdenada' [] = True
mesmaOrdenada' [x] = True
mesmaOrdenada' ((Pos x y):(Pos a b):t) | y == b = mesmaOrdenada' ((Pos x y):t)
                                       | otherwise = False

--50
data Semaforo = Verde | Amarelo | Vermelho
                   deriving Show

interseccaoOK' :: [Semaforo] -> Bool
interseccaoOK' [] = True
interseccaoOK' l = interAux l <= 1 

interAux :: [Semaforo] -> Int
interAux [] = 0
interAux (Verde:t) = 1 + interAux t
interAux (Amarelo:t) = 1 + interAux t
interAux (Vermelho:t) = interAux t



