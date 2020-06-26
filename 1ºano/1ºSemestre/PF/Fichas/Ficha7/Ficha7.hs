module Ficha7 where

import Data.List
import Debug.Trace 
import Ficha6

--1º
data ExpInt = Const Int
            | Simetrico ExpInt
            | Mais ExpInt ExpInt
            | Menos ExpInt ExpInt
            | Mult ExpInt ExpInt

--1ºa
calcula' :: ExpInt -> Int
calcula' (Const x) = x
calcula' (Simetrico x) = - (calcula' x)
calcula' (Mais x y) = (calcula' x) + (calcula' y)
calcula' (Menos x y) = (calcula' x) - (calcula' y)
calcula' (Mult x y) = (calcula' x) * (calcula' y)

--1ºb
infixa' :: ExpInt -> String
infixa' (Const x) = show x
infixa' (Simetrico x) = "- (" ++ infixa' x ++ ")"
infixa' (Mais x y) = "(" ++ (infixa' x) ++ " + " ++ (infixa' y) ++ ")"
infixa' (Menos x y) = "(" ++ (infixa' x) ++ " - " ++ (infixa' y) ++ ")"
infixa' (Mult x y) = "(" ++ (infixa' x) ++ " * " ++ (infixa' y) ++ ")"

--1ºc
posfixa' :: ExpInt -> String
posfixa' (Const x) = show x
posfixa' (Simetrico x) = (posfixa' x) ++ "-"
posfixa' (Mais x y) = (posfixa' x) ++ " " ++ (posfixa' y) ++ "+"
posfixa' (Menos x y) = (posfixa' x) ++ " " ++ (posfixa' y) ++ "+"
posfixa' (Mult x y) = (posfixa' x) ++ " " ++ (posfixa' y) ++ "*"

--2º
data RTree a = R a [RTree a] deriving Show

--2ºa
soma'' :: (Num a,Show a) => RTree a -> a
soma'' (R a []) = trace (show a) $ a
soma'' (R a l) = trace (show a) $ a + (sum (map (soma'') l))

--2ºb
altura :: RTree a -> Int 
altura (R a []) = 1
altura (R a l) = 1 + (sum $ map (altura) l)

--2ºc
prune :: Int -> RTree a -> RTree a
prune _ (R a []) = (R a [])
prune 0 (R a l) = (R a [])
prune x (R a l) = (R a $ map (prune (x-1)) l)

--2ºd
mirror :: RTree a -> RTree a
mirror (R a []) = (R a [])
mirror (R a l) = (R a $ reverse $ map (mirror) l)

--2ºe
postorder' :: RTree a -> [a]
postorder' (R a []) = [a]
postorder' (R a l) = concat (map (postorder') l) ++ [a]

--3º
data LTree a = Tip a | Fork (LTree a) (LTree a) deriving Show

--3ºa
ltSum' :: (Num a,Show a) => LTree a -> a
ltSum' (Tip a) = trace (show a) $ a
ltSum' (Fork e r) = (ltSum' e) + (ltSum' r)

--3ºb
listaLT' :: LTree a -> [a]
listaLT' (Tip a) = [a]
listaLT' (Fork e r) = (listaLT' e) ++ (listaLT' r)

--3ºc
ltHeight' :: (Show a) => LTree a -> Int
ltHeight' (Tip a) = 1
ltHeight' (Fork e r) = trace (show (show e,show r)) $ let p = ltHeight' e
                                                          l = ltHeight' r
                                                      in if p>l then 1+p else 1+l

--4º
data FTree a b = Leaf b | No a (FTree a b) (FTree a b) deriving Show

--4ºa
splitFTree' :: FTree a b -> (BTree a, LTree b)
splitFTree' (Leaf a) = (Empty,Tip a)
splitFTree' (No a e r) = let (b,c) = splitFTree' e
                             (p,l) = splitFTree' r
                         in (Node a b p,Fork c l)

--4ºb
joinTrees' :: BTree a -> LTree b -> Maybe (FTree a b)
joinTrees' Empty _ = Nothing
joinTrees' _ (Tip a) = Just (Leaf a)
joinTrees' (Node a e r) (Fork ae ar) = let p = joinTrees' e ae
                                           l = joinTrees' r ar
                                       in case p of
                                               Nothing -> Nothing
                                               (Just k) -> case l of
                                                                 Nothing -> Nothing
                                                                 (Just z) -> Just (No a k z)


