import System.Random
import Data.List


--1ºa
inicio :: IO ()
inicio = do x <- bingo []
            print x

bingo :: [Int] -> IO [Int]
bingo l = if (length l == 90 ) then do {putStrLn "Ja sairam todas os numeros :";return l} 
          else do k <- getChar;
                  if (k == '.') then do x <- randomRIO (1,90)
                                        if (elem x l) then bingo l 
                                        else do {print (x:l);bingo (x:l)}
                  else bingo l


numeroBingo :: [Int] -> IO [Int]
numeroBingo l = do n <- randomRIO (1,90)
                   if (length l == 90) then return l
                   else if (elem n l) then numeroBingo l
                        else numeroBingo (n:l)

--1ºb                                    isto funcionar, porem o codigo esta muito confuso (e ha muita coisa desnecessaria)
mastermind :: IO ()
mastermind = do x <- geraChave
                ciclos x                    

ciclos :: (Int,Int,Int,Int) -> IO () 
ciclos x = do {p <- menu;
               case p of
                    "J" -> do {putStrLn "Introduza a sua chave :";ciclo x}
                    "G" -> do {putStrLn " -------------------- \n Nova Chave atribuida \n --------------------";h <- geraChave; ciclos h}
                    "S" -> putStrLn "Fim do Jogo"
                    "?" -> do {print x;ciclos x}
                    _  -> ciclos x }
            


menu :: IO String
menu = do {putStrLn menuText;
           putStrLn "Opção :" ;
           c <- getLine;
           return c}
       where menuText = unlines ["","-------(MASTERMIND)-------","","Jogar            --->  [J]","Gera Nova Chave  --->  [G]","","Sair             --->  [S]"]



ciclo :: (Int,Int,Int,Int) -> IO ()
ciclo s = do x <- kappa s
             case x of
              "menu" -> do {ciclos s}
              l -> do {putStrLn l;ciclo s}

kappa :: (Int,Int,Int,Int) -> IO String
kappa z = do x <- getChar
             y <- getChar
             l <- getChar
             p <- getChar
             if (isDigit' x) && (isDigit' y) && (isDigit' l) && (isDigit' p) then do if (certo (verificaChave z (convertInt x,convertInt y,convertInt l,convertInt p)))
                                                                                     then do {putStrLn "  ->  Congratulations U DID IT!!";return "menu"} else return (errado (verificaChave z (convertInt x,convertInt y,convertInt l,convertInt p)))
             else if (x=='r') || (y=='r') || (l=='r') || (p=='r') then do {return "menu"}
                   else do o <- kappa z
                           return o

isDigit' :: Char -> Bool
isDigit' x = x>= '0' && x<='9'     

errado :: (String,String,String,String) -> String
errado ("errado","errado","errado","errado") = "  ->  Todas as chaves estao erradas " 
errado (x,y,z,d) = erradoAuxiliar [x,y,z,d]


erradoAuxiliar :: [String] -> String
erradoAuxiliar l = escolheFrase (eVirou (outraAuxiliar 1 l))

escolheFrase :: String -> String
escolheFrase l | length l == 2 = "  ->  A chave na posicao " ++ l ++ " esta errada"
               | otherwise = "  ->  As chaves nas posições " ++ l ++ " estao erradas"


eVirou :: [Int] -> String
eVirou [] = ""
eVirou (h:t) = show h ++ "," ++ eVirou t

outraAuxiliar :: Int -> [String] -> [Int]
outraAuxiliar x [] = []
outraAuxiliar x (h:t) | h == "errado" = x : outraAuxiliar (x+1) t
                      | otherwise = outraAuxiliar (x+1) t 


certo :: (String,String,String,String) -> Bool
certo ("certo","certo","certo","certo") = True
certo (_,_,_,_) = False

verificaChave :: (Int,Int,Int,Int) -> (Int,Int,Int,Int) -> (String,String,String,String)
verificaChave (a,b,c,d) (x,y,z,w) = (auxil a x,auxil b y,auxil c z,auxil d w)

auxil :: Int -> Int -> String
auxil x y | x==y = "certo"
          | otherwise = "errado"


geraChave :: IO (Int,Int,Int,Int)
geraChave = do { do x <- randomRIO (0,9)
                    y <- randomRIO (0,9)
                    l <- randomRIO (0,9)
                    p <- randomRIO (0,9)
                    return (x,y,l,p)
                }

convertInt :: Char -> Int
convertInt x = (fromEnum x) - (fromEnum '0') 

--2º
data Aposta = Ap [Int] (Int,Int)

--2ºa
valida :: Aposta -> Bool
valida (Ap l (x,y)) | (length l == 5) && (all (saoNumeros) l) && (temRepetidos l) && (x>=1 && x<=9) && (y>=1 && y<=9) = True
                    | otherwise = False

temRepetidos :: [Int] -> Bool
temRepetidos [] = True
temRepetidos (h:t) | (elem h t) = False
                   | otherwise = temRepetidos t

saoNumeros :: Int -> Bool
saoNumeros x | x>=1 && x<=50 = True
             | otherwise = False

--2ºb
comuns :: Aposta -> Aposta -> (Int,Int)
comuns (Ap l (x,y)) (Ap ls (xs,ys)) = (numerosIguais l ls , numerosEstrelas (x,y) (xs,ys))

numerosIguais :: [Int] -> [Int] -> Int
numerosIguais [] _ = 0
numerosIguais (h:t) l | (elem h l) = 1 + numerosIguais t l
                        | otherwise = numerosIguais t l

numerosEstrelas :: (Int,Int) -> (Int,Int) -> Int
numerosEstrelas (x,y) (xs,ys) | (x==xs) && (y==ys) || (x==ys) && (y==xs) = 2
                              | (x==xs) && (y/=ys) || (x==ys) && (y/=xs) || (y==xs) && (x/=xs) || (y==ys) && (x/=xs) = 1
                              | otherwise = 0

--2ºc -> i)
instance Eq Aposta where
 (==) (Ap l (x,y)) (Ap ls (xs,ys)) | (valida (Ap l (x,y))) && (valida (Ap ls (xs,ys))) = (comuns (Ap l (x,y)) (Ap ls (xs,ys))) == (5,2)
                                   | otherwise = False

--2ºc -> ii)
premio :: Aposta -> Aposta -> Maybe Int
premio x y = let p = comuns x y
             in case p of
                     (5,2) -> (Just 1)
                     (5,1) -> (Just 2)
                     (5,0) -> (Just 3)
                     (4,2) -> (Just 4)
                     (4,1) -> (Just 5)
                     (4,0) -> (Just 6)
                     (3,2) -> (Just 7)
                     (2,2) -> (Just 8)
                     (3,1) -> (Just 9)
                     (3,0) -> (Just 10)
                     (1,2) -> (Just 11)
                     (2,1) -> (Just 12)
                     (2,0) -> (Just 13)
                     (1,1) -> (Just 14)
                     (1,0) -> (Just 15)
                     _ -> Nothing
--2ºd
leAposta :: IO Aposta
leAposta = do {putStrLn "Introduza os seu numeros (1 a 50)";
               x <- getLine;
               y <- getLine;
               l <- getLine;
               p <- getLine;
               u <- getLine;
               if (all (saoNumeros) (map (converti) [x,y,l,p,u])) && (temRepetidos (map (converti) [x,y,l,p,u]))
               then do {putStrLn ("Numeros selecionados : [" ++ x ++ "," ++  y ++ "," ++ l ++ "," ++ p ++ "," ++ u ++ "]");
                        z <- getLine;
                        w <- getLine;
                        if ((converti z) >= 1 && (converti z) <= 9) && ((converti w) >= 1 && (converti w) <= 9)
                        then do {putStrLn ("Aposta : Ap [" ++ x ++ "," ++ y ++ "," ++ l ++ "," ++ p ++"," ++ u ++"] (" ++ z ++ "," ++ w ++ ")"); 
                        return (Ap [converti x,converti y,converti l,converti p,converti u] (converti z,converti w))}
                        else do {putStrLn "Estrelas Invalidas";leAposta}}
               else do {putStrLn "Numeros Invalidos";leAposta}
               }
 
converti :: String -> Int
converti l = read l :: Int

--2ºe
geraChave' :: IO Aposta
geraChave' = do {x <- randomRIO (1,50);
                 y <- randomRIO (1,50);
                 l <- randomRIO (1,50);
                 p <- randomRIO (1,50);
                 u <- randomRIO (1,50);
                 q <- randomRIO (1,9);
                 w <- randomRIO (1,9);
                 if valida (Ap [x,y,l,p,u] (q,w)) then return (Ap [x,y,l,p,u] (q,w))
                                                   else geraChave'}

--2ºf
main :: IO ()
main = do x <- geraChave'
          cicloEuro x

cicloEuro :: Aposta -> IO ()
cicloEuro a = do {p <- menu';
                  case p of
                    "J" -> cicloJogo a
                    "G" -> do {putStrLn " -------------------- \n Nova Aposta atribuida \n --------------------";h <- geraChave'; cicloEuro h}
                    "S" -> putStrLn "Fim do Jogo"
                    "?" -> do {putStrLn (show a);cicloEuro a}
                    _  -> cicloEuro a }

menu' :: IO String
menu' = do {putStrLn menuText;
            putStrLn "Opção :" ;
            c <- getLine;
            return c}
        where menuText = unlines ["","-------(EuroMilhoes)-------","","Jogar            --->  [J]","Gera Nova Aposta  --->  [G]","","Sair             --->  [S]"]


cicloJogo :: Aposta -> IO ()
cicloJogo x = do {p <- leAposta;
                  z <- return (premio x p);
                  case z of
                       (Just x) -> do {putStrLn ("Premio " ++ show x);main}
                       (Nothing) -> do {print "Nothing";main } }

instance Show Aposta where
 show (Ap [x,y,l,p,u] (z,w)) = "Ap [" ++ show x ++ "," ++ show y ++ "," ++ show l ++ "," ++ show p ++"," ++ show u ++"] (" ++ show z ++ "," ++ show w ++ ")"










