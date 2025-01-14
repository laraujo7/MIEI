  
  -- | Este módulo define funções comuns da Tarefa 1 do trabalho prático.
module Tarefa1_2018li1g002 where

import LI11819
import Tarefa0_2018li1g002

-- * Testes

-- | Testes unitários da Tarefa 1.
--
-- Cada teste é uma sequência de 'Instrucoes'.
testesT1 :: [Instrucoes]
testesT1 = [[Roda,MudaTetromino,Desenha,MudaParede,Desenha,MudaParede,Move D,Roda,Roda, MudaTetromino,Roda, Move E,Move B, Move C,MudaParede,Desenha]]

--testesT2 :: [Instrucoes]
--testesT2 = [[MudaTetromino,Move B,Move D,Desenha,MudaParede,Move B,Move B,Roda,Move E,Desenha,MudaTetromino,Move B,Desenha,Move D,MudaTetromino,Roda,Desenha]]

--testesT3 :: [Instrucoes]
--testesT3 = [[Desenha,Move B,Move B,Move D,Move D,MudaParede,Roda,Desenha,Roda,Roda,Desenha,MudaTetromino,Move B,Move D,Move B,Move B,Move E,Desenha,MudaTetromino,Desenha,MudaTetromino,MudaParede,Desenha]]

--testesT4 :: [Instrucoes]
--testesT4 = [[MudaTetromino,MudaTetromino,MudaTetromino,MudaParede,Desenha,MudaParede,Move C,Move C,Move E,MudaTetromino,Roda,Roda,Desenha,Roda,MudaTetromino,Move E,Move E, Move B,Move E, MudaParede,Desenha,MudaTetromino,Move D,Desenha]] 

-- * Funções principais da Tarefa 1.

-- | Aplica uma 'Instrucao' num 'Editor'.
--
--    * 'Move' - move numa dada 'Direcao'.
--
--    * 'MudaTetromino' - seleciona a 'Peca' seguinte (usar a ordem léxica na estrutura de dados),
--       sem alterar os outros parâmetros.
--
--    * 'MudaParede' - muda o tipo de 'Parede'.
--
{- |    * 'Desenha' - altera o 'Mapa' para incluir o 'Tetromino' atual, sem alterar os outros parâmetros -}
instrucao :: Instrucao -- ^ A 'Instrucao' a aplicar.
          -> Editor    -- ^ O 'Editor' anterior.
          -> Editor    -- ^ O 'Editor' resultante após aplicar a 'Instrucao'.
instrucao Roda e = e{direcaoEditor = rodaDirecao (direcaoEditor e)}
instrucao MudaTetromino e = e{tetrominoEditor = mudaTetromino (tetrominoEditor e)}
instrucao MudaParede e = e{paredeEditor = trocaParede (paredeEditor e)}
instrucao (Move d) e = e{posicaoEditor = somaVetores (direcaoParaVetor d) (posicaoEditor e)}
instrucao Desenha e = e{mapaEditor = recebeDesenha (buscarPosicao (tetrominoParaMatriz (tetrominoEditor e)) (direcaoEditor e) (posicaoEditor e)) (Bloco (paredeEditor e)) (mapaEditor e)}

{- | Buscar o tetromino a desenha conforme a direcao do tetromino -}
desenhaTetromino :: Matriz Bool -> Direcao -> Matriz Bool
desenhaTetromino x C = x
desenhaTetromino x D = rodaMatriz x
desenhaTetromino x B = rodaMatriz (rodaMatriz x)
desenhaTetromino x E = rodaMatriz (rodaMatriz (rodaMatriz x))

{- | Bucar a posicoes onde o tetromino vai ser aplicado 
(ou seja, as posicoes na matriz do tetromino onde seja True) -}
buscarPosicao :: Matriz Bool -> Direcao -> Posicao ->[Posicao]
buscarPosicao [] _ _ = []
buscarPosicao l k (a,b) = aux (0,0) (a,b) (desenhaTetromino l k)

-- | auxiliar para a funcao buscarPosicao
aux :: Posicao -> Posicao -> Matriz Bool -> [Posicao]
aux (x,y) _ [] =[]
aux (x,y) (a,b) ([]:t) = aux (x+1,0) (a,b) t
aux (x,y) (a,b) ((h:xs):t) | h==True && length ((h:xs):t)/=0 = (x+a,y+b):aux (x,y+1) (a,b) (xs:t)
                           | h/=True && length ((h:xs):t)/=0 = aux (x,y+1) (a,b) (xs:t)
                           | otherwise = []


{- | Recebe as posicoes onde o tetromino é True e Desenha(ou seja, altera o tipo de peca 
do mapa com Blocos Destrutiveis/Indestrutiveis nas posicçoes obtidas pela funcao buscarPosicoes -}
recebeDesenha :: [Posicao] -> Peca -> Mapa -> Mapa
recebeDesenha [] _ a = a
recebeDesenha (h:t) (Bloco Indestrutivel) a = recebeDesenha t (Bloco Indestrutivel) (atualizaPosicaoMatriz h (Bloco Indestrutivel) a)
recebeDesenha (h:t) (Bloco Destrutivel) a = recebeDesenha t (Bloco Destrutivel) (atualizaPosicaoMatriz h (Bloco Destrutivel) a)


{- | Troca o tipo de parede -}
trocaParede :: Parede -> Parede
trocaParede Indestrutivel = Destrutivel
trocaParede Destrutivel = Indestrutivel

{- | Muda o tipo de tetromino -}
mudaTetromino :: Tetromino -> Tetromino
mudaTetromino I = J
mudaTetromino J = L
mudaTetromino L = O
mudaTetromino O = S
mudaTetromino S = T
mudaTetromino T = Z
mudaTetromino Z = I

{- | Roda a direçao do tetromino -}
rodaDirecao :: Direcao -> Direcao
rodaDirecao C = D
rodaDirecao D = B
rodaDirecao B = E
rodaDirecao E = C

{- | Aplica uma sequência de 'Instrucoes' num 'Editor'. -}

instrucoes :: Instrucoes -- ^ As 'Instrucoes' a aplicar.
           -> Editor     -- ^ O 'Editor' anterior.
           -> Editor     -- ^ O 'Editor' resultante após aplicar as 'Instrucoes'.
instrucoes [] e = e
instrucoes (h:t) e = instrucoes t (instrucao h e)

{- | Cria um 'Mapa' inicial com 'Parede's nas bordas e o resto vazio. -}

mapaInicial :: Dimensao -- ^ A 'Dimensao' do 'Mapa' a criar.
            -> Mapa     -- ^ O 'Mapa' resultante com a 'Dimensao' dada.
mapaInicial (x,y) = matrizTrans (transfPeca (escolhaMa (0,0) (x,y)) (x,y)) (x,y)

{- | Criação de uma lista com todas as posições possiveis de uma matriz
com dimensoes (x,y) -}
escolhaMa :: Dimensao -> Dimensao -> [Dimensao]
escolhaMa (a,b) (x,y) | a/=x && b/=y = (a,b): escolhaMa (a,b+1) (x,y)
                      | a/=x && b==y = escolhaMa (a+1,0) (x,y)
                      | otherwise = []

{- | A utilizar a funçao anterior, substituimos as posiçoes necessarias 
para delimitar a matriz com blocos Indestruticel e o restante Peças Vazias -}
transfPeca :: [Dimensao] -> Dimensao -> [Peca]
transfPeca [] (a,b) = []
transfPeca ((x,y):t) (a,b) | x==0 || y==0 = Bloco Indestrutivel : transfPeca t (a,b)
                           | x==(a-1) || y==(b-1) = Bloco Indestrutivel : transfPeca t (a,b)
                           | otherwise = Vazia : transfPeca t (a,b)

{- | Mudança de lista de peças, da funcao anterior, para Matriz de Peca -}
matrizTrans :: [Peca] -> Dimensao -> [[Peca]]
matrizTrans [] (x,y) = []
matrizTrans (h:t) (x,y) = take y (h:t) : matrizTrans (drop y (h:t)) (x,y)

{- | Cria um 'editor' usando as funçoes previamente definidas ('mapaInicial','dimensaoInicial' e 'posicaoInicial') -}

editorInicial :: Instrucoes  -- ^ Uma sequência de 'Instrucoes' de forma a poder calcular a  'dimensaoInicial' e a 'posicaoInicial'.
              -> Editor      -- ^ O 'Editor' inicial, usando a 'Peca' 'I' 'Indestrutivel' voltada para 'C'.
editorInicial i = Editor {posicaoEditor = posicaoInicial i
, direcaoEditor = C
, tetrominoEditor = I 
, paredeEditor = Indestrutivel
, mapaEditor = mapaInicial (dimensaoInicial i)
}

{- | Criaçao de um 'Mapa' usando instruçoes dadas em 'Instrucoes' e editadas pelo editor 'mapaEditor'. -}

-- __NB:__ Deve chamar as funções 'instrucoes' e 'editorInicial'.
constroi :: Instrucoes -- ^ Uma sequência de 'Instrucoes' dadas a um 'Editor' para construir um 'Mapa'.
         -> Mapa       -- ^ O 'Mapa' resultante.
constroi is = mapaEditor (instrucoes is (editorInicial is)) 

