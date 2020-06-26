module Ficha5 where

import Data.Char
import Debug.Trace


--1ºa
any' :: (a -> Bool) -> [a] -> Bool 
any' f [] = False
any' f (h:t) | (f h) = True
             | otherwise = any' f t

--1ºb
zipWith' :: (a->b->c) -> [a] -> [b] -> [c]
zipWith' f [] _ = []
zipWith' f _ [] = []
zipWith' f (h:t) (x:xs) = (f h x) : zipWith' f t xs   

--1ºc
takeWhile' :: (a->Bool) -> [a] -> [a]
takeWhile' f [] = []
takeWhile' f (h:t) | f h = h : takeWhile' f t
                   | otherwise = takeWhile' f t

--1ºd
dropWhile' :: (a->Bool) -> [a] -> [a]
dropWhile' f [] = []
dropWhile' f (h:t) | f h = dropWhile' f t
                   | otherwise = h: dropWhile' f t

--1ºe
span' :: (a-> Bool) -> [a] -> ([a],[a])
span' f [] = ([],[])
span' f (h:t) | f h = (h:l,ls)
              | otherwise = (l,h:ls)
              where (l,ls) = span' f t

--1ºf
deleteBy' :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteBy' f x [] = []
deleteBy' f x (h:t) | f x h = deleteBy' f x t
                    | otherwise = h : deleteBy' f x t

--1ºg 
sortOn' :: Ord b => (a -> b) -> [a] -> [a]
sortOn' f [] = []
sortOn' f (h:t) = insert' h (sortOn' f t)
                  where insert' h [] = [h]
                        insert' h (x:xs) | f h <= f x = h:x:xs
                                         | otherwise = x:insert' h xs

--2º
type Polinomio = [Monomio]
type Monomio = (Float,Int)

--2ºa
selgrau' :: Int -> Polinomio -> Polinomio
selgrau' a [] = []
selgrau' a l = filter (aux) l
               where aux (x,y) = y==a

--2ºb
conta' :: Int -> Polinomio -> Int
conta' a [] = 0
conta' a l = length (filter (aux) l)
             where aux (x,y) = y==a

--2ºc
grau' :: Polinomio -> Int
grau' [] = 0
grau' l = snd (last (sortOn' snd l))

--2ºd
deriv' :: Polinomio -> Polinomio
deriv' [] = []
deriv' l =  map (derivAux) l

derivAux :: Monomio -> Monomio
derivAux (h1,h2) = (h1*fromIntegral h2,h2-1)

--2ºe
calcula :: Float -> Polinomio -> Float
calcula n [] = 0
calcula n l = sum (map (\(x,y) -> (x * (n^y))) l)

--2ºf
simp' :: Polinomio -> Polinomio
simp' [] = []
simp' l = dropWhile' (simpAux) l

simpAux :: Monomio -> Bool
simpAux (x,y) | y == 0 = True
              | otherwise = False

--2ºg
mult' :: Monomio -> Polinomio -> Polinomio
mult' _ [] = []
mult' (x,y) l = map (\(a,b) -> (x*a,y*b)) l

--2ºh
ordena' :: Polinomio -> Polinomio
ordena' [] = []
ordena' l = sortOn' snd l

--2ºi
normaliza'' :: Polinomio -> Polinomio
normaliza'' [] = []
normaliza'' ((x,y):t) = let p = filter (\(a,b) -> b==y) ((x,y):t)
                            c = sum (map fst p)
                            l = filter (\(a,b) -> b/=y) ((x,y):t) 
                        in (c,y) : normaliza'' l

--2º
soma' :: Polinomio -> Polinomio -> Polinomio
soma' [] [] = []
soma' [] x = x
soma' x [] = x
soma' x y = normaliza'' (x++y)

--2ºk
produto' :: Polinomio -> Polinomio -> Polinomio
produto' [] [] = []
produto' x [] = x
produto' [] x = x
produto' x l = produto' (tail x) (mult' (head x) l)

--2º
equiv' :: Polinomio -> Polinomio -> Bool
equiv' [] [] = True
equiv' x [] = False
equiv' [] x = False
equiv' p l | elem' (head p) l = equiv' (tail p) (filter (/=(head p)) l)
           | otherwise = False

elem' :: Monomio -> Polinomio -> Bool
elem' x [] = False
elem' x (h:t) | x==h = True
              | otherwise = elem' x t

--3
type Mat a = [[a]]

--3ºa
dimOk' :: Mat a -> Bool
dimOk' [x] = True
dimOk' m | length (head m) == length (head (tail m)) = dimOk' (tail m)
         | otherwise = False

--3ºb
dimMat :: Mat a -> (Int,Int)
dimMat[] = (0,0)
dimMat l = (nLi l , length (head l))

nLi :: [[a]] -> Int
nLi [] = 0
nLi (h:t) | length h == 0 = 0
          | otherwise = 1 + nLi t

--3ºc
addMat' :: Num a => Mat a -> Mat a -> Mat a
addMat' [] [] = []
addMat' [] x = x
addMat' x [] = x
addMat' m l = (zipWith (+) (head m) (head m)) : addMat' (tail m) (tail l)

--3ºd
transpose' :: Mat a -> Mat a
transpose' ([]:_) = []
transpose' m = (map (head) m) : transpose' (map (tail) m)

--3ºe
multMat' :: Num a => Mat a -> Mat a -> Mat a
multMat' ([]:_) m = []
multMat' m ([]:_) = []
multMat' m l | length m /= 0 = (multAux (head m) l) : multMat' (tail m) l
             | otherwise = []

multAux :: Num a => [a] -> Mat a -> [a]
multAux [] x = []
multAux x ([]:_) = []
multAux x l = let k = map (head) l
              in (sum (zipWith (*) x k)) : multAux x (map (tail) l)

--3ºf
zipWMat' :: (a -> b -> c) -> Mat a -> Mat b -> Mat c 
zipWMat' f _ [] = []
zipWMat' f [] _ = []
zipWMat' f m l = zipWMatAux f (head m) (head l) : zipWMat' f (tail m) (tail l) 

zipWMatAux :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWMatAux f [] _ = []
zipWMatAux f _ [] = []
zipWMatAux f (h:t) (a:b) = (f h a) : zipWMatAux f t b 

--3ºg
triSup' :: (Eq a,Num a) => Mat a -> Bool
triSup' [] = False
triSup' l = all (==0) (triAux 0 l)

triAux :: (Num a) => Int -> Mat a -> [a]
triAux _ [] = []
triAux x (h:t) = (take x h) ++ triAux (x+1) t

--3ºh
rotateLeft' :: Mat a -> Mat a
rotateLeft' [] = []
rotateLeft' m = transpose' (map (reverse) m)


