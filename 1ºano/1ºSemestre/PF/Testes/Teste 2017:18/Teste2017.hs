import Data.Char
import Debug.Trace
import Data.List
import System.Random
--               Teste 2017

--1
insert' :: Ord a => a -> [a] -> [a]
insert' x [] = [x]
insert' x (h:t) | x <= h = x:h:t
                | otherwise = h : insert' x t

--2
catMaybe' :: [Maybe a] -> [a]
catMaybe' [] = []
catMaybe' (Nothing:t) =  catMaybe' t
catMaybe' ((Just x):t) = x : catMaybe' t

--3
data Exp a = Const a
           | Var String
           | Mais (Exp a) (Exp a)
           | Mult (Exp a) (Exp a)

infixe :: Show a => Exp a -> String
infixe (Const a) = show a
infixe (Var x) = "(" ++ x ++ ")"
infixe (Mais x y) = "(" ++ (infixe x) ++ " + " ++ (infixe y) ++ ")"
infixe (Mult x y) = "(" ++ (infixe x) ++ " * " ++ (infixe y) ++ ")"


instance Show a => Show (Exp a) where
 show x = infixe x

--4
sortOn' :: Ord b => (a->b) -> [a] -> [a]
sortOn' f [] = []
sortOn' f (h:t) = insertExp f h (sortOn' f t)
                where insertExp f x [] = [x]
                      insertExp f x (h:t) | f x <= f h = x:h:t
                                          | otherwise = h : insertExp f x t

--5a
amplitude :: [Int] -> Int
amplitude [] = 0
amplitude l = subtrai (separa l (0,0))

subtrai :: (Int,Int) -> Int
subtrai (x,y) = y-x

separa :: [Int] -> (Int,Int) -> (Int,Int)
separa [] (x,y) = (x,y)
separa (h:t) (0,0) = separa t (h,0)
separa (h:t) (x,0) = separa t (x,h)
separa (h:t) (x,y) | h <= x = separa t (h,y)
                   | h >= x && h <= y = separa t (x,y)
                   | otherwise = separa t (x,h)


--5b
parte :: [Int] -> ([Int],[Int])
parte [] = ([],[])
parte l = undefined


--6
data Imagem = Quadrado Int
              | Mover (Int,Int) Imagem
              | Juntar [Imagem]

ex :: Imagem
ex = Mover (5,5) (Juntar [Mover (0,1) (Quadrado 5),
                            Quadrado 4,
                            Mover (4,3) (Quadrado 2)])


--6a
conta :: Imagem -> Int
conta (Quadrado x) = 1
conta (Mover (x,y) a) = conta a
conta (Juntar a) = sum (map (conta) a)



