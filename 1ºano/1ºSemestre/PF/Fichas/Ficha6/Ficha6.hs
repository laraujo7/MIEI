module Ficha6 where

import Data.List

--1º
data BTree a = Empty
             | Node a (BTree a) (BTree a)
              deriving Show

--1ºa
altura' :: BTree a -> Int 
altura' Empty = 0
altura' (Node a e d) = let x = altura' e
                           z = altura' d
                        in 1 + max x z

--1ºb 
contaNodos' :: BTree a -> Int
contaNodos' Empty = 0
contaNodos' (Node a ae ad) = let x = contaNodos' ae 
                                 z = contaNodos' ad
                             in 1+x+z

--1ºc
folhas' :: BTree a -> Int
folhas' (Node a Empty Empty) = 1
folhas' (Node a Empty ad) = folhas' ad
folhas' (Node a ae Empty) = folhas' ae
folhas' (Node a ae ad) = let x = folhas' ae
                             z = folhas' ad
                         in x+z

--1ºd
prune' :: Int -> BTree a -> BTree a
prune' x Empty = Empty
prune' 0 (Node a ae ad) = Empty
prune' x (Node a ae ad) = (Node a (prune' (x-1) ae) (prune' (x-1) ad))

--1ºe
path' :: [Bool] -> BTree a -> [a]
path' _ Empty = []
path' [] (Node a _ _) = [a]
path' (True:t) (Node a ae ad) = a:path' t ad
path' (False:t) (Node a ae ad) = a:path' t ae

--1ºf
mirror' :: BTree a -> BTree a
mirror' (Node a Empty Empty) = (Node a Empty Empty)
mirror' (Node a Empty ad) = (Node a (mirror' ad) Empty)
mirror' (Node a ae Empty) = (Node a Empty (mirror' ae))
mirror' (Node a ae ad) = (Node a (mirror' ad) (mirror' ae)) 

--1ºg
zipWithBT' :: (a -> b -> c) -> BTree a -> BTree b -> BTree c
zipWithBT' f Empty _ = Empty
zipWithBT' f _ Empty = Empty
zipWithBT' f (Node a ae ad) (Node t te td) = let l = zipWithBT' f ae te
                                                 s = zipWithBT' f ad td
                                             in (Node (f a t) l s)

--1ºh
unzipBT' :: BTree (a,b,c) -> (BTree a,BTree b,BTree c)
unzipBT' Empty = (Empty,Empty,Empty)
unzipBT' (Node (a,b,c) ae ad) = let (a1,b1,c1) = unzipBT' ae
                                    (a2,b2,c2) = unzipBT' ad
                                in ((Node a a1 a2),(Node b b1 b2),(Node c c1 c2))

--2ºa
minimo' :: Ord a => BTree a -> a
minimo' (Node a Empty _) = a
minimo' (Node a ae _) = minimo' ae

--2ºb
semMinimo' :: Ord a => BTree a -> BTree a
semMinimo' Empty = Empty
semMinimo' (Node a ae ad) | a == minimo'(Node a ae ad) = ad
                          | otherwise = (Node a (semMinimo' ae) ad)

--2ºc
minSmin' :: Ord a => BTree a -> (a,BTree a) 
minSmin' (Node a Empty ad) = (a,ad)
minSmin' (Node a ae ad) = let (c,e) = minSmin' ae
                           in (c,Node a ae ad)

--2ºd
remove' :: Ord a => a -> BTree a -> BTree a
remove' _ Empty = Empty
remove' x b@(Node a ae ad) | x > a = (Node a ae (remove' x ad))
                         | x < a = (Node a (remove' x ae) ad)
                         | otherwise = removeRaiz b

removeRaiz :: Ord a => BTree a -> BTree a
removeRaiz (Node a ae Empty) = ae
removeRaiz (Node a Empty ad) = ad
removeRaiz (Node a ae ad) = let m = maior ae
                                s = semMaior ae
                            in (Node m s ad)

maior :: Ord a => BTree a -> a
maior (Node a ae Empty) = a
maior (Node _ _ ad) = maior ad

semMaior :: Ord a => BTree a -> BTree a
semMaior (Node a ae Empty) = ae
semMaior (Node a ae ad) = (Node a ae (semMaior ad))

--3
type Aluno = (Numero,Nome,Regime,Classificacao)
type Numero = Int
type Nome = String
data Regime = ORD | TE | MEL deriving Show
data Classificacao = Aprov Int
                   | Rep
                   | Faltou
                    deriving Show
type Turma = BTree Aluno -- ´arvore bin´aria de procura (ordenada por n´umero)

--3ºa
inscNum' :: Numero -> Turma -> Bool
inscNum' x Empty = False
inscNum' x (Node (a,b,c,d) ae ad) | x<a = inscNum' x ae
                                  | x>a = inscNum' x ad
                                  | otherwise = True

--3ºb
inscNome' :: Nome -> Turma -> Bool
inscNome' x Empty = False
inscNome' x b = elem x (inscAux b)

inscAux :: Turma -> [Nome]
inscAux Empty = []
inscAux (Node (a,b,c,d) ae ad) = let l = inscAux ae
                                     u = inscAux ad
                                 in b:(l++u)

--3ºc
trabEst' :: Turma -> [(Numero,Nome)]
trabEst' Empty = []
trabEst g@(Node (a,b,c,d) ae ad) = sortOn fst (trabAux g)

trabAux :: Turma -> [(Numero,Nome)]
trabAux Empty = []
trabAux (Node (a,b,c,d) ae ad) = let l = trabAux ae
                                     u = trabAux ad
                                 in (a,b):(l++u)

--3ºd
nota' :: Numero -> Turma -> Maybe Classificacao
nota' x Empty = Nothing
nota' x (Node (a,b,c,d) ae ad) | x<a = nota' x ae
                               | x>a = nota' x ad
                               | otherwise = Just d

--3ºe
percFaltas' :: Turma -> Float
percFaltas' t = ((/) (numT t) (totalT t)) * 100

numT :: Turma -> Float
numT Empty = 0
numT (Node (a,b,c,Faltou) ae ad) = 1 + (numT ae) + (numT ad)
numT (Node (a,b,c,_) ae ad) = (numT ae) + (numT ad)

totalT :: Turma -> Float
totalT Empty = 0
totalT (Node a ae ad) = let l = totalT ae
                            u = totalT ad
                        in 1+l+u

--3ºf
mediaAprov' :: Turma -> Float
mediaAprov' t = ((/) (convertFloat(mediaAux t)) (aprovado t))

mediaAux :: Turma -> Int
mediaAux Empty = 0
mediaAux (Node (a,b,c,Aprov x) ae ad) = let l = mediaAux ae
                                            u = mediaAux ad
                                        in  (x+l+u) 
mediaAux (Node (a,b,c,_) ae ad) = 0

convertFloat :: Int -> Float
convertFloat x = fromIntegral x :: Float


--3ºg
aprovAv' :: Turma -> Float
aprovAv' t = ((/) (aprovado t) (apareceu t)) * 100

aprovado :: Turma -> Float
aprovado Empty = 0
aprovado (Node (a,b,c,Aprov x) ae ad) = 1 + (aprovado ae) + (aprovado ad)
aprovado (Node (a,b,c,_) ae ad) = 0

apareceu :: Turma -> Float
apareceu Empty = 0
apareceu (Node (a,b,c,Rep) ae ad) = 1 + (apareceu ae) + (apareceu ad)
apareceu (Node (a,b,c,Aprov x) ae ad) = 1 + (apareceu ae) + (apareceu ad)











