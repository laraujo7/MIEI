module Ficha1 where

import Data.Char

-- 1ºa
perimetro :: Double -> Double
perimetro x = 2*pi*x

-- 1ºb
dist :: (Double,Double) -> (Double,Double) -> Double
dist (x,y) (z,w) = sqrt (((x-z)^2) + ((y-w)^2))

-- 1ºc
primUlt :: [a] -> (a,a)
primUlt a = (head (a),last (a))

-- 1ºd
multiplo :: Int -> Int -> Bool
multiplo x y | (mod x y) == 0 = True
             | otherwise = False

-- 1ºe
truncaImpar :: [a] -> [a]
truncaImpar l@(h:t) | (mod(length l) 2) == 0 = l
                    | otherwise = t

--1ºf
max2 :: Int -> Int -> Int
max2 x y | (x > y) = x
         | otherwise = y

-- 1ºg
max3 :: Int -> Int -> Int -> Int
max3 x y z = (max2 (max2 x y) z)

-- 2ºa
nRaizes :: Double -> Double -> Double -> Int
nRaizes x y z | y^2-4 * x * z > 0 = 2
              | y^2-4 * x * z == 0 = 1
              | otherwise = 0

-- 2ºb
raizes' :: Double -> Double -> Double -> [Double]
raizes' a b c | (a == 0 || delta < 0) = []
              | delta == 0 = [r]
              | otherwise = [r1,r2]
              where delta = (b)^2 - 4 * a * c
                    r = (-b)/(2 * a)
                    r1 = ((-b) + (sqrt delta))/(2 * a)
                    r2 = ((-b) - (sqrt delta))/(2 * a)

-- 3º
type Hora = (Int,Int)

--3ºa
hcheck' :: Hora -> Bool
hcheck' (x,y) | ((x >= 0) && (x <24) && (y >= 0) && (y < 60)) = True
              | otherwise = False

-- 3ºb
hourcheck' :: Hora -> Hora -> Bool
hourcheck' (x,y) (z,w) | (x > z) = True
                       | ((x == z) && (y > w)) = True
                       | otherwise = False

-- 3ªc
conversor' :: Hora -> Int
conversor' (x,y) = x * 60 + y

-- 3ºd
conversorm' :: Int -> Hora
conversorm' x = (div x 60 , mod x 60)

-- 3ºe
diferenca' :: Hora -> Hora -> Int
diferenca' (x,y) (z,w) = abs ((x * 60 + y) - (z * 60 + w))

-- 3ºf
addmin' :: Hora -> Int -> Hora
addmin' (x,y) w = (div ((x * 60 + y) + w) 60 , mod ((x * 60 + y) + w) 60)

-- 4º 
data Hora_ = H Int Int deriving (Show,Eq)

-- 4ºa
hcheck'' :: Hora_ -> Bool
hcheck'' (H x y) | (x >= 0) && (x <24) && (y >= 0) && (y < 60) = True
               | otherwise = False

-- 4ºb
hourcheck'' :: Hora_ -> Hora_ -> Bool
hourcheck'' (H x y) (H z w) | (x > z) = True
                           | ((x == z) && (y > w)) = True
                           | otherwise = False

-- 4ºc
conversor'' :: Hora_ -> Int
conversor'' (H x y) = x * 60 + y

-- 4ºd
conversorm'' :: Int -> Hora_
conversorm'' x = H (div x 60) (mod x 60)

-- 4ºe
diferenca'' :: Hora_ -> Hora_ -> Int
diferenca'' (H x y) (H z w) = abs ((x * 60 + y) - (z * 60 + w))

-- 4ºf
addmin'' :: Hora_ -> Int -> Hora_
addmin'' (H x y) w = H (div ((x * 60 + y) + w) 60) (mod ((x * 60 + y) + w) 60)


-- 5º
data Semaforo = Verde | Amarelo | Vermelho deriving (Show,Eq)

-- 5ªa
next' :: Semaforo -> Semaforo
next' Verde = Amarelo
next' Vermelho = Verde
next' Amarelo = Vermelho

-- 5ºb
stop' :: Semaforo -> Bool
stop' Verde = False
stop' Vermelho = True
stop' Amarelo = False

-- 5ºc
safe' :: Semaforo -> Semaforo -> Bool
safe' Verde Vermelho = True
safe' Verde Amarelo = False
safe' Verde Verde = False
safe' Amarelo Vermelho = True
safe' Amarelo Amarelo = False
safe' Amarelo Verde = False
safe' Vermelho Verde = True
safe' Vermelho Amarelo = True
safe' Vermelho Vermelho = False 

-- 6º
data Ponto = Cartesiano Double Double | Polar Double Double
             deriving (Show,Eq)

-- 6ºa
prosx' :: Ponto -> Double
prosx' (Cartesiano x y) = abs (x)
prosx' (Polar z w) = z * (cos w)

-- 6ºb
prosy' :: Ponto -> Double
prosy' (Cartesiano x y) = abs (y)
prosy' (Polar z w) = z * (sin w)

-- 6ºc
raio' :: Ponto -> Double
raio' (Cartesiano x y) = abs (sqrt (x^2 + y^2))
raio' (Polar z w) = z

-- 6ºd
angulo' :: Ponto -> Double
angulo' (Polar z w) = z
angulo' (Cartesiano x y) | (quad (x,y)) == 1 = atan (y/x)
                         | (quad (x,y)) == 2 = pi - (atan (abs(y/x)))
                         | (quad (x,y)) == 4 = 2 * pi - atan (abs(y/x))
                         | (quad (x,y)) == 4 = pi + atan (abs(y/x))

quad :: (Double,Double) -> Int
quad (x,y) | x >= 0 && y >= 0 = 1
           | x < 0 && y > 0 = 2
           | x <= 0 && y < 0 = 3
           | otherwise = 4

-- 6ºe
dist' :: Ponto -> Ponto -> Double
dist' (Cartesiano x y) (Cartesiano w z) = sqrt ((x-w)^2 + (y-z)^2)

-- 7º
data Figura = Circulo Ponto Double
              | Rectangulo Ponto Ponto
              | Triangulo Ponto Ponto Ponto
              deriving (Show,Eq)

-- 7ºa
poligono' :: Figura -> Bool
poligono' (Circulo (Cartesiano x y) z) = True
poligono' (Rectangulo x y) = True
poligono' (Triangulo x y z) = True

--7ºb
vertices' :: Figura -> [Ponto]
vertices' (Circulo (Cartesiano x y) z) = []
vertices' (Rectangulo (Cartesiano x y) (Cartesiano w z)) = [(Cartesiano x y)]++[(Cartesiano w z)]++[(Cartesiano x z)]++[(Cartesiano w z)]
vertices' (Triangulo (Cartesiano x y) (Cartesiano w z) (Cartesiano a b)) = [(Cartesiano x y)]++[(Cartesiano w z)]++[(Cartesiano a b)]

-- 8ºa
isLower' :: Char -> Bool
isLower' x = if (x>='a' && x<='z') then True else False

-- 8ºb
isDigit' :: Char -> Bool
isDigit' x = x >= '0' && x <= '9'

-- 8ºc
isAlpha' :: Char -> Bool
isAlpha' x = (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')

-- 8ºd   (Aconselho a consulta do codigo ascii)
toUpper' :: Char -> Char
toUpper' x | (isLower' x) = chr $ (ord x) - 32
           | otherwise = x

-- 8ºe
intToDigit' :: Int -> Char
intToDigit' x = chr $ 48 + x

-- 8º
digitToInt' :: Char -> Int
digitToInt' x = (ord x) - 48
