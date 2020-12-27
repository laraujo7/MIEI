import Debug.Trace
import Ficha5
import Debug.Trace

--1º
data Frac = F Integer Integer 
data Ordering = EQ | LT | GT

--1ºa
normaliza' :: Frac -> Frac
normaliza' (F x y) = let p = mdc (abs x) (abs y)
                     in sinal $ F (div x p) (div y p)

sinal :: Frac -> Frac
sinal (F x y) | (x<0 && y<0) || (x>=0 && y>=0) = (F (abs x) (abs y))
              | (x<0 && y>=0) = (F x y)
              | otherwise = (F (-x) (abs y))

mdc :: Integer -> Integer -> Integer
mdc x y | x == y = x
        | x<y = mdc x (y-x)
        | otherwise = mdc (x-y) y

--1ºb
instance Eq Frac where
     (==) (F x y) (F z w) = (x*w) == (z*y)

--1ºc
instance Ord Frac where
     (<=) (F x y) (F z w) = (x*w) <= (z*y)

--1ºd
instance Show Frac where
     show (F x y) = (show x) ++ "/" ++ (show y)

--1ºe
instance Num Frac where
     (+) (F x y) (F z w) = normaliza' (F (x*w + z*y) (y*w))
     (-) (F x y) (F z w) = normaliza' (F (x*w - z*y) (y*w))
     (*) (F x y) (F z w) = normaliza' (F (x*z) (y*w))
     negate (F x y) = (F (-1*x) y)
     abs (F x y) = (F (abs x) (abs y))
     fromInteger x = (F x 1)
     signum (F x y) | (x>0 && y>0) || (x<0 && y<0) = 1
                    | x==0 = 0
                    | otherwise = -1

--1ºf
dobro' :: Frac -> [Frac] -> [Frac]
dobro' _ [] = []
dobro' f l = filter (>2*f) l

--2º
data Exp a = Const a
           | Simetrico (Exp a)
           | Mais (Exp a) (Exp a)
           | Menos (Exp a) (Exp a)
           | Mult (Exp a) (Exp a)

infixa' :: (Show a) => Exp a -> String
infixa' (Const x) = show x
infixa' (Simetrico x) = "- (" ++ infixa' x ++ ")"
infixa' (Mais x y) = "(" ++ (infixa' x) ++ " + " ++ (infixa' y) ++ ")"
infixa' (Menos x y) = "(" ++ (infixa' x) ++ " - " ++ (infixa' y) ++ ")"
infixa' (Mult x y) = "(" ++ (infixa' x) ++ " * " ++ (infixa' y) ++ ")"

calcula' :: (Eq a,Num a) => Exp a -> a
calcula' (Const x) = x
calcula' (Simetrico x) = - (calcula' x)
calcula' (Mais x y) = (calcula' x) + (calcula' y)
calcula' (Menos x y) = (calcula' x) - (calcula' y)
calcula' (Mult x y) = (calcula' x) * (calcula' y)

--2ºa
instance (Show a) => Show (Exp a) where
 show x = (infixa' x)

--2ºb
instance (Eq a,Num a) => Eq (Exp a) where
 (==) x y = (calcula' x) == (calcula' y)

--2ºc
instance (Num a,Eq a) => Num (Exp a) where
 (+) x y = Const (calcula' x + calcula' y)
 (-) x y = Const (calcula' x - calcula' y)
 (*) x y = Const (calcula' x * calcula' y)
 negate x = Const (calcula' (Simetrico x))
 abs x = Const (abs (calcula' x))
 fromInteger x = Const (fromInteger x)
 signum x = Const (signum (calcula' x))

--3º
data Movimento = Credito Float | Debito Float
data Data = D Int Int Int
data Extracto = Ext Float [(Data, String, Movimento)]

--3ºa
instance Ord Data where
 (<=) (D a b c) (D x y z) = (c,b,a) <= (z,y,x)

instance Eq Data where
 (==) (D x y z) (D d m a) = (x,y,z) == (d,m,a)

--3ºb
instance Show Data where
 show (D a b c) = show a ++ "/" ++ show b ++ "/" ++ show c

--3ºc
ordena0' :: Extracto -> Extracto
ordena0' (Ext x []) = (Ext x [])
ordena0' (Ext x l) = Ext x $ sortOn' (\(a,b,c) -> a) l 

--3ºd
instance Show Movimento where
 show (Credito x) = show x
 show (Debito x) = show x

instance Eq Movimento where
 (==) (Credito x) (Credito y) = x == y
 (==) (Debito x) (Debito y) = x == y

instance Show Extracto where
 show (Ext x l) = "\n" ++ "\n" ++
                  "Saldo anterior : " ++ show x ++ "\n" ++
                  "----------------------------------------------------------"++ "\n" ++
                  "Data          Descrição          Credito          Debito " ++ "\n"++
                  (dataAux (ordena0' (Ext x l))) ++ "\n" ++
                  "----------------------------------------------------------"++ "\n" ++
                  "Saldo atual : " ++ show (calculaSaldo (Ext x l)) ++ "\n"

calculaSaldo :: Extracto -> Float
calculaSaldo (Ext x ((a,b,c):t)) = sum ([x]++operacao (Ext x ((a,b,c):t)))
--
operacao :: Extracto -> [Float]
operacao (Ext x []) = []
operacao (Ext x ((a,b,Credito k):t)) = k : operacao (Ext x t)
operacao (Ext x ((a,b,Debito k):t)) = (-k) : operacao (Ext x t)

dataAux :: Extracto -> String
dataAux (Ext x []) = ""
dataAux (Ext x ((a,b,c):t)) | (a,b,c) == (last ((a,b,c):t)) = (show a ++ tamanhoData a ++ depende b ++ "     " ++ creditoDebito c (depende b) )
                            | otherwise = (show a ++ tamanhoData a ++ depende b ++ "     " ++ creditoAux c (depende b) ) ++ dataAux (Ext x t)

depende :: String -> String
depende x | length x <= 10 = x
          | otherwise = (take 9 x) ++ "."

tamanhoData :: Data -> String
tamanhoData (D a b c) | a<10 && b<10 = "      " 
                      | (a<10 && b>=10) || (a>=10 && b<10) = "     "
                      | otherwise = "    "
 
creditoDebito :: Movimento -> String -> String
creditoDebito (Credito x) b = tamanhaString (Credito x) b ++ show x
creditoDebito (Debito x) b = tamanhaString (Debito x) b ++ show x

creditoAux :: Movimento -> String -> String
creditoAux (Credito x) b = tamanhaString (Credito x) b ++ show x ++ "\n"
creditoAux (Debito x) b = tamanhaString (Debito x) b ++ show x ++ "\n"

tamanhaString :: Movimento -> String -> String
tamanhaString (Credito x) b | length b == 0 = "              "
                            | length b == 1 = "             "
                            | length b == 2 = "            "
                            | length b == 3 = "           "
                            | length b == 4 = "          "
                            | length b == 5 = "         "
                            | length b == 6 = "        "
                            | length b == 7 = "       "
                            | length b == 8 = "      "
                            | length b == 9 = "     "
                            | length b == 10 = "    "
tamanhaString (Debito x) b  | length b == 0 = "                               "
                            | length b == 1 = "                              "
                            | length b == 2 = "                             "
                            | length b == 3 = "                            "
                            | length b == 4 = "                           "
                            | length b == 5 = "                          "
                            | length b == 6 = "                         "
                            | length b == 7 = "                        " 
                            | length b == 8 = "                       "
                            | length b == 9 = "                      "
                            | length b == 10 = "                     " 




-- Exemplo
exemplo = Ext 10 [((D 10 12 1990),"Comprassss",(Credito 20)), ((D 11 12 1990),"Outras comprdsadasdadas", (Debito 100))]








