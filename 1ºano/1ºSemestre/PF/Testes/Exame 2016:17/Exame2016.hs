import Data.Char
import Debug.Trace
--               Exame 2016


--1ºa
unlines' :: [String] -> String
unlines' [] = ""
unlines' [x] = x
unlines' (h:t) = h ++ "\n" ++ unlines' t

--1ºb
delete :: (Eq a) => [a] -> [a] -> [a]
delete [] _ = []
delete x [] = x
delete l (x:xs) | elem x l = delete (remove' x l) xs
                | otherwise = delete l xs

remove' :: (Eq a) => a -> [a] -> [a]
remove' _ [] = []
remove' x (h:t) | x == h = t
                | otherwise = h : remove' x t

--2
data Seq a = Nil | Inicio a (Seq a) | Fim (Seq a) a deriving Show

--2ºa
primeiro :: Seq a -> a
primeiro (Inicio a x) = a
primeiro (Fim x a) = primeiro x

--2ºb
semUltimo :: Seq a -> Seq a
semUltimo Nil = Nil
semUltimo (Inicio a x) = (Inicio a (semUltimo x))
semUltimo (Fim x a) = auxiliar x

auxiliar :: Seq a -> Seq a
auxiliar Nil = Nil
auxiliar (Inicio a x) = (Inicio a (auxiliar x))
auxiliar (Fim x a) = (Fim (auxiliar x) a)

--3
data BTree a = Empty | Node a (BTree a) (BTree a) deriving Show

--3ºa
prune :: Int -> BTree a -> BTree a
prune 0 x = Empty
prune _ Empty = Empty
prune x (Node a ae ad) = (Node a (prune (x-1) ae) (prune (x-1) ad))

--3ºb
semMinimo :: (Ord a) => BTree a -> BTree a
semMinimo Empty = Empty
semMinimo (Node a ae ad) | minimo' (Node a ae ad) == a = ad
                         | otherwise = (Node a (semMinimo ae) ad)

minimo' :: (Ord a) =>  BTree a -> a
minimo' (Node a Empty ad) = a
minimo' (Node a ae ad) = minimo' ae 

--4
type Tabuleiro = [String]

--4ºa
posicoes :: Tabuleiro -> [(Int,Int)]
posicoes [] = []
posicoes l = pAuxiliar l 0 0

pAuxiliar :: Tabuleiro -> Int -> Int -> [(Int,Int)]
pAuxiliar [] _ _ = []
pAuxiliar (h:t) x y = (posicaoAux h x y) ++ pAuxiliar t x (y+1)

posicaoAux :: String -> Int -> Int -> [(Int,Int)]
posicaoAux [] _ _ = []
posicaoAux (h:t) x y | h == 'R' = (x,y) : posicaoAux t (x+1) y
                     | otherwise = posicaoAux t (x+1) y

--4ºb
valido :: Tabuleiro -> Bool
valido [] = False
valido l = verifica (posicoes l) 

verifica :: [(Int,Int)] -> Bool
verifica [] = True
verifica [x] = True
verifica ((a,b):t) | elem b (map (snd) t) || elem a (map (fst) t) || elem (a-b) (zipWith (-) (map (fst) t) (map (snd) t)) = False
                   | otherwise = verifica t

--4ºc
bemFormado :: Int -> Tabuleiro -> Bool 
bemFormado x [] = False
bemFormado x (h:t) | all (==True) (map (\l -> x==length l) (h:t)) && length (h:t) == x && length (concat (map (takeWhile' (=='R')) (h:t))) == x = True
                   | otherwise = False

takeWhile' :: (a->Bool) -> [a] -> [a]
takeWhile' f [] = []
takeWhile' f (h:t) | f h = h : takeWhile' f t
                   | otherwise = takeWhile' f t
