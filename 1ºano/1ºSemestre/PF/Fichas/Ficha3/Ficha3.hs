-- 1º
data Hora = H Int Int
          deriving Show
type Etapa = (Hora,Hora)
type Viagem = [Etapa]

-- 1ºa
testEtapa' :: Etapa -> Bool
testEtapa' (H x y , H w z) | (x<w && x>=0 && x<24 && y<60 && y>=0 && w>=0 && w<24 && z<60 && z>=0) = True
                           | (x==w && y<z && x>=0 && x<24 && y<60 && y>=0 && w>=0 && w<24 && z<60 && z>=0) = True
                           | otherwise = False

-- 1ºb
testViagem' :: Viagem -> Bool
testViagem' [] = False
testViagem' [(H x y , H w z)] = testEtapa' (H x y , H w z)
testViagem' ((H x y , H w z):(H a b , H c d):t) | (w<a && testViagem' ((H a b , H c d):t)) = True
                                                | (w==a && z<b && testViagem' ((H a b , H c d):t)) = True
                                                | otherwise = False

-- 1ºc
calcViagem' :: Viagem -> Etapa
calcViagem' ((H x y , H w z):t) = (H x y , snd (last t))

--1ºd
calcTempoViagem' :: Viagem -> Int
calcTempoViagem' [] = 0
calcTempoViagem' ((H x y , H w z):t) = abs (((60 * w + z) - (60 * x + y)) + calcTempoViagem' t)

--1ºe
calcTempoEspera' :: Viagem -> Int
calcTempoEspera' [] = 0
calcTempoEspera' [(H x y , H w z)] = 0 
calcTempoEspera' ((H x y , H w z):(H a b , H c d):t) = abs (((60 * a + b) - (60 * w + z)) + calcTempoEspera' ((H a b , H c d):t))

--1ºf
calcTempoTotal' :: Viagem -> Int
calcTempoTotal' [] = 0
calcTempoTotal' ((H x y , H w z):t) = calcTempoEspera' ((H x y , H w z):t) + calcTempoViagem' ((H x y , H w z):t)

-- 2º
data Ponto = Cartesiano Double Double | Polar Double Double
             deriving (Show,Eq)

type Poligonal = [Ponto]

data Figura = Circulo Ponto Double
            | Rectangulo Ponto Ponto
            | Triangulo Ponto Ponto Ponto
            deriving (Show,Eq)

-- 2ºa
comprPoligonal' :: Poligonal -> Double
comprPoligonal' [] = 0
comprPoligonal' [(Cartesiano x y)] = 0
comprPoligonal' ((Cartesiano x y):(Cartesiano w z):t) = sqrt ((x - w)^2 + (y - z)^2) + comprPoligonal' ((Cartesiano w z):t)

-- 2ºb
fechadaOuAberta' :: Poligonal -> Bool
fechadaOuAberta' [] = True
fechadaOuAberta' [(Cartesiano x y)] = False
fechadaOuAberta' ((Cartesiano x y):(Cartesiano w z):t) | fechadaOuAberta_aux (Cartesiano x y) ((Cartesiano w z):t) = True
                                                       | otherwise = fechadaOuAberta' ((Cartesiano w z):t)

fechadaOuAberta_aux :: Ponto -> Poligonal -> Bool
fechadaOuAberta_aux (Cartesiano x y) [] = False
fechadaOuAberta_aux (Cartesiano x y) ((Cartesiano z w):t) | x==z && y==w = True 
                                                          | otherwise = fechadaOuAberta_aux (Cartesiano x y) t 

-- 2ºc
triangula' :: Poligonal -> [Figura]
triangula' [] = []
triangula' [(Cartesiano x y)] = []
triangula' ((Cartesiano x y):(Cartesiano a b):[]) = []
triangula' ((Cartesiano x y):(Cartesiano a b):(Cartesiano c d):t) = (Triangulo (Cartesiano x y) (Cartesiano a b) (Cartesiano c d)):triangula' ((Cartesiano x y):(Cartesiano c d):t)

-- 2ºd
calcArea' :: Poligonal -> Float
calcArea' [] = 0
calcArea' [(Cartesiano x y)] = 0
calcArea' ((Cartesiano x y):(Cartesiano a b):[]) = 0
calcArea' ((Cartesiano x y):(Cartesiano a b):(Cartesiano c d):t) = auxArea (triangula' ((Cartesiano x y):(Cartesiano a b):(Cartesiano c d):t))

auxArea :: [Figura] -> Float
auxArea [] = 0
auxArea ((Triangulo (Cartesiano x y) (Cartesiano a b) (Cartesiano c d)):t) =  realToFrac((abs ((x*b) + (y*c) + (a*d) - (y*a) - (x*d) - (b*c))) / 2) + (auxArea t)

{-
	|x y 1 x y|    (abs (x*b + y*c + a*d - y*a - x*d - b*c)) / 2
	|a b 1 a b|    (abs (1*-2 + 2*-2 + 2*-1 - (2*2) - (1*-1) - (-2*-2)) / 2
	|c d 1 c d|    (abs ((-2) - 4 - 2 - 4 + 1 - 4)) /2
				   (abs (-15)) / 2 
				   15 / 2 
				   7.5
-}

-- 2ºe
mover' :: Poligonal -> Ponto -> Poligonal
mover' [] (Cartesiano x y) = [(Cartesiano x y)]
mover' ((Cartesiano x y):t) (Cartesiano w z) = ((Cartesiano w z):(Cartesiano x y):t)

-- 2ºf
zoom' :: Double -> Poligonal -> Poligonal
zoom' x [] = []
zoom' x [(Cartesiano a b)] = [(Cartesiano (a) (b))]
zoom' x ((Cartesiano y z):(Cartesiano a b):t) = (Cartesiano y z):zoom' x ((Cartesiano (x*a) (x*b)):t)

-- 3º
data Contacto = Casa Integer
                     | Trab Integer
                     | Tlm Integer
                     | Email String
                     deriving Show
type Nome = String
type Agenda = [(Nome, [Contacto])]

-- 3ºa
acrescEmail' :: Nome -> String -> Agenda -> Agenda
acrescEmail' n e [] = [(n,[Email e])]
acrescEmail' n e ((x,y):t) | n==x = (n,y++[Email e]):t
                           | otherwise = acrescEmail' n e t

-- 3ºb
verEmails' :: Nome -> Agenda -> Maybe [String]
verEmails' n [] = Nothing
verEmails' n ((x,y):t) | n==x = Just (selectEmail y) 
                       | otherwise = verEmails' n t

selectEmail :: [Contacto] -> [String]
selectEmail [] = []
selectEmail (h:t) = case h of
                             (Email a) -> a:selectEmail t

-- 3ºc
consTelefs :: [Contacto] -> [Integer]
consTelefs [] = []
consTelefs (c:ls) = case c of
                             (Casa nt) -> nt:(consTelefs ls)
                             (Trab nt) -> nt:(consTelefs ls)    
                             (Email nt) -> consTelefs ls

-- 3ºd
casa :: Nome -> Agenda -> Maybe Integer
casa n [] = Nothing
casa n ((x,y):t) | n==x = Just (selectNumber y)
                 | otherwise = casa n t

selectNumber :: [Contacto] -> Integer
selectNumber (h:t) = case h of
                              (Casa a) -> a
                              (Trab a) -> selectNumber t
                              (Email a) -> selectNumber t
                              (Tlm a) -> selectNumber t

--4º
type Dia = Int
type Mes = Int
type Ano = Int

--data Data = D Dia Mes Ano
--            deriving Show

type TabDN = [(Nome,Data)]

--4ºa
procura' :: Nome -> TabDN -> Maybe Data
procura' n [] = Nothing
procura' n ((x,D a b c):t) | n == x = Just (D a b c)
                           | otherwise = procura' n t

--4ºb
idade' :: Data -> Nome -> TabDN -> Maybe Int
idade' (D a b c) n [] = Nothing
idade' (D a b c) n ((k,D x y z):t) | n==k = Just (idadeValida' (D a b c) (D x y z))
                                   | otherwise = idade' (D a b c) n t

idadeValida' :: Data -> Data -> Int
idadeValida' (D a b c) (D x y z) | a>=x && b==y && c>=z = c-z
                                 | b>y && c>=z = c-z
                                 | b<y && c>=z = (c-z)-1
                                 | a<x && b==y && c>z = (c-z)-1
                                 | otherwise = 0

--4ºc
anterior' :: Data -> Data -> Bool
anterior' (D a b c) (D x y z) | c>z = False
                              | c==z && b>y = False
                              | c==z && b==y && a>=x = False
                              | otherwise = True

--4ºd
ordena' :: TabDN -> TabDN
ordena' [] = []
ordena' (h:t) = auxord h (ordena' t)

auxord :: (Nome,Data) -> TabDN -> TabDN
auxord (x,D a b c) [] = [(x,D a b c)]
auxord (x,D a b c) ((y,D d e f):t) | anterior' (D a b c) (D d e f) = ((x,D a b c):(y,D d e f):t)
                                   | otherwise = (y,D d e f):auxord (x,D a b c) t

--4ºe
porIdade' :: Data -> TabDN -> [(Nome,Int)]
porIdade' (D x y z) [] = []
porIdade' (D a b c) ((x,D d e f):t) = auxpor (D a b c) (ordena' ((x,D d e f):t))

auxpor :: Data -> TabDN -> [(Nome,Int)]
auxpor (D x y z) [] = []
auxpor (D a b c) ((x,D d e f):t) | anterior' (D a b c) (D d e f) = (x, idadeValida' (D d e f) (D a b c) ) : auxpor (D a b c) t
                                 | otherwise = auxpor (D a b c) t

--5
data Movimento = Credito Float | Debito Float
                deriving Show

data Data = D Int Int Int
           deriving Show

data Extracto = Ext Float [(Data, String, Movimento)]
                deriving Show

--5ºa
extValor' :: Extracto -> Float -> [Movimento]
extValor' (Ext a []) x = []
extValor' (Ext a ((D b c d,n,Debito k):t)) x | x<=k = Debito k : extValor' (Ext a t) x
                                             | otherwise = extValor' (Ext a t) x                                               
extValor' (Ext a ((D b c d,n,Credito k):t)) x | x<=k = Credito k : extValor' (Ext a t) x
                                              | otherwise = extValor' (Ext a t) x

--5ºb
filtro' :: Extracto -> [String] -> [(Data,Movimento)]
filtro' (Ext x []) _ = []
filtro' (Ext x ((D a b c,n,Debito k):t)) [] = []
filtro' (Ext x ((D a b c,n,Credito k):t)) [] = []
filtro' (Ext x ((D a b c,n,Credito k):t)) (y:ys) | elem n (y:ys) = (D a b c,Credito k) : filtro' (Ext x t) (y:ys)
                                                 | otherwise = filtro' (Ext x t) (y:ys)
filtro' (Ext x ((D a b c,n,Debito k):t)) (y:ys) | elem n (y:ys) = (D a b c,Debito k) : filtro' (Ext x t) (y:ys)
                                                | otherwise = filtro' (Ext x t) (y:ys)
--5ºc
creDeb' :: Extracto -> (Float,Float)
creDeb' (Ext x []) = (0,0)
creDeb' (Ext x ((D a b c,n,Credito k):t)) = (k+auxCred (Ext x t) ,0+auxDeb (Ext x t))
creDeb' (Ext x ((D a b c,n,Debito k):t)) = (0+auxCred (Ext x t) ,k+auxDeb (Ext x t))

auxCred :: Extracto -> Float
auxCred (Ext m []) = 0
auxCred (Ext m ((D a b c,n,Credito k):t)) = k+auxCred (Ext m t)
auxCred (Ext m ((D a b c,n,Debito k):t)) = 0+auxCred (Ext m t)

auxDeb :: Extracto -> Float
auxDeb (Ext m []) = 0
auxDeb (Ext m ((D a b c,n,Debito k):t)) = k+auxDeb (Ext m t)
auxDeb (Ext m ((D a b c,n,Credito k):t)) = 0+auxDeb (Ext m t)

--5ºd
saldo' :: Extracto -> Float
saldo' (Ext m []) = m
saldo' (Ext m ((D a b c,n,Credito k):t)) = k + (auxCred (Ext m t)) + (auxDeb (Ext m t)) + m