-- | Este módulo define funções comuns da Tarefa 2 do trabalho prático.
module Tarefa2_2018li1g002 where

import LI11819
import Tarefa0_2018li1g002
import Tarefa1_2018li1g002

-- * Testes

-- | Testes unitários da Tarefa 2.

{- Cada teste é um triplo (/identificador do 'Jogador'/,/'Jogada' a efetuar/,/'Estado' anterior/). -}
testesT2 :: [(Int,Jogada,Estado)]
testesT2 = [(0,Movimenta D, Estado [[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Destrutivel,Vazia,Vazia,Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Bloco Destrutivel,Bloco Destrutivel,Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]] [(Jogador (1,1) D 2 2 2),(Jogador (3,2) E 1 2 3)] [(DisparoCanhao 1 (3,3) E),(DisparoChoque 0 4)])]

-- * Funções principais da Tarefa 2.

{- | Efetua uma jogada. -}
jogada :: Int -- ^ O identificador do 'Jogador' que efetua a jogada.
       -> Jogada -- ^ A 'Jogada' a efetuar.
       -> Estado -- ^ O 'Estado' anterior.
       -> Estado -- ^ O 'Estado' resultante após o jogador efetuar a jogada.
jogada x (Movimenta h) e = e{jogadoresEstado = atualizaIndiceLista x (podeMover l (mapaEstado e) h (jogadoresEstado e) (disparosEstado e)) (jogadoresEstado e)}
                          where l = encontraIndiceLista x (jogadoresEstado e)
jogada x (Dispara h) e = e{jogadoresEstado = atualizaIndiceLista x (municao l h) (jogadoresEstado e), disparosEstado = (verificaDisparo x l h)++(disparosEstado e)}
                            where l = encontraIndiceLista x (jogadoresEstado e)

{- | Esta funcao adciona o disparo do jogador que esta a fazer a jogada na lista
de disparo, verificando primeiro se esse jogador pode der facto disparar, 
na funcao 'verificaDisparo' -}
podeDisparar :: Int -> Jogador -> Arma -> [Disparo]
podeDisparar i (Jogador (x,y) h _ _ _) Canhao = [(DisparoCanhao i (somaVetores (x,y) (direcaoParaVetor h)) h)]
podeDisparar i (Jogador (x,y) h v l c) Laser = [(DisparoLaser i (somaVetores (x,y) (direcaoParaVetor h)) h)]
podeDisparar i j Choque = [(DisparoChoque i 5)]

{- | Esta funcao funciona em conjunto com a funcao anterior, onde esta verifica se o
jogador pode de facto disparar (se o jogador tem vidas (>0) e se o jogador ainda tem municoes
 -}
verificaDisparo :: Int -> Jogador -> Arma -> [Disparo]
verificaDisparo i (Jogador (x,y) d v l c) Laser | v>0 && l>0 = podeDisparar i (Jogador (x,y) d v l c) Laser
                                                | otherwise = []
verificaDisparo i (Jogador (x,y) d v l c) Choque | v>0 && c>0 = podeDisparar i (Jogador (x,y) d v l c) Choque
                                                 | otherwise = []
verificaDisparo i (Jogador (x,y) d v l c) Canhao | v>0 = podeDisparar i (Jogador (x,y) d v l c) Canhao
                                                 | otherwise = []

{- | Apos o uso de um disparo especial (Laser ou Choque) retiramos 1 as muniçoes
disponiveis desse disparo caso as muniçoes disponiveis sejam 0 ou o jogador esteja
com 0 vidas nao realizamos o disparo -}
municao :: Jogador -> Arma -> Jogador
municao (Jogador p d v l c) Laser | v>0 && l>0 = (Jogador p d v (l-1) c)
                                  | otherwise = (Jogador p d v l c)
municao (Jogador p d v l c) Choque | v>0 && c>0 = (Jogador p d v l (c-1))
                                   | otherwise = (Jogador p d v l c)
municao (Jogador p d v l c) Canhao = (Jogador p d v l c)

{- | A funçao 'indiceTank' vai buscar a [Disparo] quem é que esta a efetuar 
o disparo choque (os indices dos jogadores). De seguida na 'qualJodador' usando os 
indices anteriormente adequiridos verifico quais os Jogadores que estao a efetuar
o choque. De seguida em 'choqueTank' verificamos se o jogador que esta a tentar mover
consegue mover (se esta dentro da area afetada pelo choque) caso isto seja 
verdade o jogador nao se consegue mover com a unica exceçao do jogador que
dispara o choque esse consegue movimentar-se normalmente caso isto seja falso
e o jogador esta fora da area do choque este consegue se moviemntar normalmente.
E para finalizar este proceso temos a 'checaMov' que recebe todas as funçoes anteriormente 
referidas e efetua o resultado pretendido -}
indiceTank :: [Disparo] -> [Int]
indiceTank [] =  []
indiceTank ((DisparoChoque f g):t) | g>0 = f: indiceTank t
                                 | otherwise = indiceTank t
indiceTank ((DisparoCanhao a b c):t) = indiceTank t
indiceTank ((DisparoLaser a b c):t) = indiceTank t

-- | Funcao auxiliar
qualJogador :: [Int] -> [Jogador] -> [Jogador]
qualJogador [] _ = []
qualJogador _ [] = []
qualJogador (h:t) (a:b) = encontraIndiceLista h (a:b) : qualJogador t (a:b)

-- | Funcao auxilia
choqueTank :: Jogador -> [Jogador] -> Bool
choqueTank x [] = True
choqueTank (Jogador (x,y) e r u f) ((Jogador (a,b) p o i m):t) | a-3>x || a+3<x || b-3>y || b+3<y || (x==a && y==b) && m>0  = choqueTank (Jogador (x,y) e r u f) t
                                                               | otherwise = False 

-- | Junçao de axuliares
checaMov :: [Disparo] -> [Jogador] -> Jogador -> Bool
checaMov l t a = choqueTank a (qualJogador (indiceTank l) t)

{- | Vai ao mapa verificar se o tanque pode se mover para uma posicao,ou seja, vai verificar
se numa certa posicao é um Bloco (Destrutivel ou Insdestrutivel) ou é Vazia, 
caso seja Bloco devolve um False (que significa que o tanque nao se pode movimentar para
essa possicao) e caso seja Vazia (significa que o tanque pode se movimentar para essa posicao -}
buscarMatriz :: Posicao -> Mapa -> Bool
buscarMatriz (0,0) ((h:t):ts) | h== Vazia = True
                              | otherwise = False
buscarMatriz _ [[]] = False
buscarMatriz (0,y) ((h:t):ts) = buscarMatriz (0,y-1) (t:ts)
buscarMatriz (x,y) ((h:t):ts) = buscarMatriz (x-1,y) ts

{- | Verifica se na posicao em que o tanque vai se mover existe outro tanque, caso exista
um outro tanque devolve um False(que quer dizer que nao se pode movimentar), caso nao exista
devolve um True (que significa que se pode movimentar) -}
podeAvancar :: Jogador -> Direcao -> [Jogador] -> Bool
podeAvancar _ _ [] = True
podeAvancar (Jogador (x,y) a b c d) C ((Jogador (q,w) _ v _ _):t) | ((x-2,y) == (q,w) || (x-2,y-1) == (q,w) || (x-2,y+1)  == (q,w)) && v>0 = False
                                                                  | otherwise = podeAvancar (Jogador (x,y) a b c d) C t
podeAvancar (Jogador (x,y) a b c d) D ((Jogador (q,w) _ v _ _):t) | ((x,y+2) == (q,w) || (x+1,y+2) == (q,w) || (x-1,y+2) == (q,w)) && v>0  = False
                                                                  | otherwise = podeAvancar (Jogador (x,y) a b c d) D t
podeAvancar (Jogador (x,y) a b c d) B ((Jogador (q,w) _ v _ _):t) | ((x+2,y) == (q,w) || (x+2,y-1) == (q,w) || (x+2,y+1) == (q,w)) && v>0 = False
                                                                  | otherwise = podeAvancar (Jogador (x,y) a b c d) B t
podeAvancar (Jogador (x,y) a b c d) E ((Jogador (q,w) _ v _ _):t) | ((x,y-2) == (q,w) || (x+1,y-2) == (q,w) || (x-1,y-2) == (q,w)) && v>0 = False
                                                                  | otherwise = podeAvancar (Jogador (x,y) a b c d) E t

{- | Movimenta o tanque para uma certa posicao, conforme a direcao, caso esse posicao
esteja Vazio, ou seja, o tanque so é movimentado para essa posicao se nesta posicao
nao tenha nenhum tipo de Bloco (Destrutivel ou Indestrutivel) ou nenhum outro tanque, como
tambem verifica se o tanque que se quer mover ainda tem vidas ou nao--}
podeMover :: Jogador -> Mapa -> Direcao -> [Jogador] -> [Disparo] -> Jogador
podeMover (Jogador (x,y) k a b c) m C l j | buscarMatriz (x-1,y) m && podeAvancar (Jogador (x,y) k a b c) C l && checaMov j l (Jogador (x,y) k a b c) && k==C && a>0 = (Jogador (x-1,y) C a b c)
                                          | a == 0 = (Jogador (x,y) k a b c)
                                          | otherwise = (Jogador (x,y) C a b c) 
podeMover (Jogador (x,y) k a b c) m D l j | buscarMatriz (x,y+2) m && podeAvancar (Jogador (x,y) k a b c) D l && checaMov j l (Jogador (x,y) k a b c) && k==D && a>0 = (Jogador (x,y+1) D a b c)
                                          | a == 0 = (Jogador (x,y) k a b c)
                                          | otherwise = (Jogador (x,y) D a b c) 
podeMover (Jogador (x,y) k a b c) m B l j | buscarMatriz (x+2,y) m && podeAvancar (Jogador (x,y) k a b c) B l && checaMov j l (Jogador (x,y) k a b c) && k==B && a>0 = (Jogador (x+1,y) B a b c)
                                          | a == 0 = (Jogador (x,y) k a b c)
                                          | otherwise = (Jogador (x,y) B a b c) 
podeMover (Jogador (x,y) k a b c) m E l j | buscarMatriz (x,y-1) m && podeAvancar (Jogador (x,y) k a b c) E l && checaMov j l (Jogador (x,y) k a b c) && k==E && a>0 = (Jogador (x,y-1) E a b c)
                                          | a == 0 = (Jogador (x,y) k a b c)
                                          | otherwise = (Jogador (x,y) E a b c) 





 