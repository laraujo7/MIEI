-- | Este mÃ³dulo define funÃ§Ãµes comuns da Tarefa 4 do trabalho prÃ¡tico.
module Tarefa4_2018li1g002 where

import LI11819
import Tarefa3_2018li1g002
import Tarefa0_2018li1g002
import Tarefa1_2018li1g002
import Tarefa2_2018li1g002

--tickLasers (Estado [[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]] [(Jogador (2,4) D 5 5 5)] [(DisparoLaser 0 (2,4) B)])
--tickLasers (Estado (mapaInicial (15,15)) [(Jogador (4,4) D 5 5 5),(Jogador (10,5) E 4 4 4)] [(DisparoLaser 0 (6,4) B)])
--tickLasers (Estado (mapaInicial (15,15)) [(Jogador (2,2) D 5 5 5),(Jogador (10,3) E 4 4 4)] [(DisparoLaser 0 (3,2) B),(DisparoCanhao 1 (8,3) C),(DisparoChoque 0 4)])

--tickCanhoes (Estado [[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]] [(Jogador (2,4) D 5 5 5)] [(DisparoCanhao 0 (7,3) B)])
--tickCanhoes (Estado (mapaInicial (15,15)) [(Jogador (10,3) D 1 1 1),(Jogador (3,2) B 4 4 4)] [(DisparoCanhao 1 (9,2) B)])


-- * Testes
-- | Testes unitÃ¡rios da Tarefa 4.
--
-- | Cada teste Ã© um 'Estado'.
testesT4 :: [Estado]
testesT4 = [(Estado m1 j1 d1),(Estado m2 j2 d2),(Estado m3 j3 d3),(Estado m4 j4 d4)]
            where m1 = (mapaInicial (20,20))
                  j1 = [(Jogador (5,5) D 1 1 1),(Jogador (10,9) E 2 2 2)]
                  d1 = [(DisparoCanhao 0 (2,2) E),(DisparoLaser 1 (1,10) B),(DisparoChoque 0 3)]
                  m2 = [[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]]
                  j2 = [(Jogador (4,2) D 1 1 1),(Jogador (3,2) E 2 2 2)]
                  d2 = [(DisparoCanhao 0 (2,2) E),(DisparoLaser 1 (1,10) B),(DisparoCanhao 1 (3,2) C)]
                  m3 = [[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]]
                  j3 = [(Jogador (5,5) D 1 1 1),(Jogador (10,9) E 2 2 2),(Jogador (20,20) B 1 1 1)]
                  d3 = [(DisparoLaser 2 (20,1) B),(DisparoCanhao 1 (10,8) D),(DisparoChoque 1 1)]
                  m4 = (mapaInicial (40,40))
                  j4 = [(Jogador (6,8) D 1 1 1),(Jogador (20,9) E 2 2 2),(Jogador (8,30) B 1 1 1),(Jogador (30,2) C 0 2 2)]
                  d4 = [(DisparoCanhao 1 (30,3) E),(DisparoLaser 2 (4,2) D)]


-- * FunÃ§Ãµes principais da Tarefa 4.

-- | AvanÃ§a o 'Estado' do jogo um 'Tick' de tempo.
--
-- __NB:__ Apenas os 'Disparo's afetam o 'Estado' do jogo com o passar do tempo.
--
-- __NB:__ Deve chamar as funÃ§Ãµes 'tickChoques', 'tickCanhoes' e 'tickLasers' pela ordem definida.
tick :: Estado -- ^ O 'Estado' anterior.
     -> Estado -- ^ O 'Estado' apÃ³s um 'Tick'.
tick e = tickLasers (tickCanhoes (tickChoques e))


-- | AvanÃ§a o 'Estado' do jogo um 'Tick' de tempo, considerando apenas os efeitos dos tiros de 'Laser' disparados.
tickLasers :: Estado -> Estado
tickLasers e = e{mapaEstado = mapaLaser (disparosEstado e) (mapaEstado e),jogadoresEstado = atualizaJogador (jogadoresEstado e) (jogadorLaser (disparosEstado e) (mapaEstado e)),disparosEstado = removeL (colisaoLaserCanhao (jogadorLaser (disparosEstado e) (mapaEstado e)) (disparosEstado e))}

-- | AvanÃ§a o 'Estado' do jogo um 'Tick' de tempo, considerando apenas os efeitos das balas de 'Canhao' disparadas.
tickCanhoes :: Estado -> Estado
tickCanhoes e = e{mapaEstado = mapaCanhao  (disparosEstado e) (mapaEstado e),jogadoresEstado = jogadorCanhao (disparosEstado e) (jogadoresEstado e),disparosEstado = funcaoFinal  (disparosEstado e) (jogadoresEstado e) (mapaEstado e)}

-- | AvanÃ§a o 'Estado' do jogo um 'Tick' de tempo, considerando apenas os efeitos dos campos de 'Choque' disparados.
tickChoques :: Estado -> Estado
tickChoques e = e{disparosEstado = separaDisparos (disparosEstado e)}

-- | Inicio Canhoes (mapa)
mapaCanhao :: [Disparo] -> Mapa -> Mapa
mapaCanhao [] m = m
mapaCanhao ((DisparoCanhao a (x,y) d):t) m = mapaCanhao t (canhao (DisparoCanhao a (x,y) d) m)
mapaCanhao (h:t) m =  mapaCanhao t m

-- | Funcao
canhao :: Disparo -> Mapa -> Mapa
canhao (DisparoCanhao a (x,y) D) m | ((paraCanhao (x,y+1) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y+1) m) == Bloco Indestrutivel) = posicaoVazia [(x,y+1)] Vazia m
                                   | ((paraCanhao (x,y+1) m) == Bloco Indestrutivel) && ((paraCanhao (x+1,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y+1)] Vazia m
                                   | ((paraCanhao (x,y+1) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x,y+1),(x+1,y+1)] Vazia m
                                   | ((paraCanhao (x,y+1) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y+1) m) == Vazia) = posicaoVazia [(x,y+1)] Vazia m
                                   | ((paraCanhao (x,y+1) m) == Vazia) && ((paraCanhao (x+1,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y+1)] Vazia m
                                   | otherwise = m
canhao (DisparoCanhao a (x,y) E) m | ((paraCanhao (x,y) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y) m) == Bloco Indestrutivel) = posicaoVazia [(x,y)] Vazia m
                                   | ((paraCanhao (x,y) m) == Bloco Indestrutivel) && ((paraCanhao (x+1,y) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y)] Vazia m
                                   | ((paraCanhao (x,y) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y) m) == Bloco Destrutivel) = posicaoVazia [(x,y),(x+1,y)] Vazia m
                                   | ((paraCanhao (x,y) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y) m) == Vazia) = posicaoVazia [(x,y)] Vazia m
                                   | ((paraCanhao (x,y) m) == Vazia) && ((paraCanhao (x+1,y) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y)] Vazia m
                                   | otherwise = m
canhao (DisparoCanhao a (x,y) B) m | ((paraCanhao (x+1,y) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y+1) m) == Bloco Indestrutivel) = posicaoVazia [(x+1,y)] Vazia m
                                   | ((paraCanhao (x+1,y) m) == Bloco Indestrutivel) && ((paraCanhao (x+1,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y+1)] Vazia m
                                   | ((paraCanhao (x+1,y) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y),(x+1,y+1)] Vazia m
                                   | ((paraCanhao (x+1,y) m) == Bloco Destrutivel) && ((paraCanhao (x+1,y+1) m) == Vazia) = posicaoVazia [(x+1,y)] Vazia m
                                   | ((paraCanhao (x+1,y) m) == Vazia) && ((paraCanhao (x+1,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x+1,y+1)] Vazia m
                                   | otherwise = m
canhao (DisparoCanhao a (x,y) C) m | ((paraCanhao (x,y) m) == Bloco Destrutivel) && ((paraCanhao (x,y+1) m) == Bloco Indestrutivel) = posicaoVazia [(x,y)] Vazia m
                                   | ((paraCanhao (x,y) m) == Bloco Indestrutivel) && ((paraCanhao (x,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x,y+1)] Vazia m
                                   | ((paraCanhao (x,y) m) == Bloco Destrutivel) && ((paraCanhao (x,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x,y),(x,y+1)] Vazia m
                                   | ((paraCanhao (x,y) m) == Bloco Destrutivel) && ((paraCanhao (x,y+1) m) == Vazia) = posicaoVazia [(x,y)] Vazia m
                                   | ((paraCanhao (x,y) m) == Vazia) && ((paraCanhao (x,y+1) m) == Bloco Destrutivel) = posicaoVazia [(x,y+1)] Vazia m
                                   | otherwise = m
canhao x m = m 

-- | Funcao
paraCanhao :: Posicao -> Mapa -> Peca
paraCanhao (0,0) ((h:t):ts) | h == Bloco Destrutivel = Bloco Destrutivel
                            | h == Bloco Indestrutivel = Bloco Indestrutivel
                            | otherwise = Vazia
paraCanhao (0,y) ((h:t):ts) = paraCanhao (0,y-1) (t:ts)
paraCanhao (x,y) ((h:t):ts) = paraCanhao (x-1,y) ts

-- | Canhao (jogadores)
jogadorCanhao :: [Disparo] -> [Jogador] -> [Jogador]
jogadorCanhao [] x = x
jogadorCanhao _ [] = []
jogadorCanhao ((DisparoCanhao a (w,z) d):t) (x:xs) = (jogCanhao ((DisparoCanhao a (w,z) d):t) x) ++ jogadorCanhao ((DisparoCanhao a (w,z) d):t) xs
jogadorCanhao (h:t) (x:xs) = jogadorCanhao t (x:xs)

-- | Funcao
jogCanhao :: [Disparo] -> Jogador -> [Jogador]
jogCanhao [] x = [x]
jogCanhao ((DisparoCanhao a (x,y) D):t) (Jogador (w,z) d v l c) | ((x,y+1) == (w,z) || (x-1,y+1) == (w,z) || (x+1,y+1) == (w,z)) && v>0= jogCanhao t (Jogador (w,z) d (v-1) l c)
                                                                | otherwise = jogCanhao t (Jogador (w,z) d v l c)
jogCanhao ((DisparoCanhao a (x,y) E):t) (Jogador (w,z) d v l c) | ((x,y-1) == (w,z) || (x-1,y-1) == (w,z) || (x+1,y-1) == (w,z)) && v>0= jogCanhao t (Jogador (w,z) d (v-1) l c)
                                                                | otherwise = jogCanhao t (Jogador (w,z) d v l c)
jogCanhao ((DisparoCanhao a (x,y) B):t) (Jogador (w,z) d v l c) | ((x+1,y) == (w,z) || (x+1,y-1) == (w,z) || (x+1,y+1) == (w,z)) && v>0= jogCanhao t (Jogador (w,z) d (v-1) l c)
                                                                | otherwise = jogCanhao t (Jogador (w,z) d v l c)
jogCanhao ((DisparoCanhao a (x,y) C):t) (Jogador (w,z) d v l c) | ((x-1,y) == (w,z) || (x-1,y-1) == (w,z) || (x-1,y+1) == (w,z)) && v>0= jogCanhao t (Jogador (w,z) d (v-1) l c)
                                                                | otherwise = jogCanhao t (Jogador (w,z) d v l c)
jogCanhao (h:t) x = jogCanhao t x

-- | Funcao Canhao (Disparos)
funcaoFinal :: [Disparo] -> [Jogador] -> Mapa -> [Disparo]
funcaoFinal [] _ _ = []
funcaoFinal l j m = (colition' (disparosCanhao l j m))

-- | Funcao 
retiraColisao :: [Disparo] -> [Posicao]
retiraColisao [] = []
retiraColisao ((DisparoCanhao a (x,y) d):t) = (x,y) : retiraColisao t
retiraColisao (h:t) = retiraColisao t

-- | Funcao
colition :: [Posicao] -> [Posicao]
colition [] = []
colition (h:t) | elem h t = colition (filter (/=h) t)
               | otherwise = h : colition t
-- | Funcao
posicoesD :: [Disparo] -> [Posicao]
posicoesD [] = []
posicoesD l = colition (retiraColisao l)
-- | Funcao
colisao' :: [Disparo] -> [Posicao] -> [Disparo]
colisao' [] _ = []
colisao' x [] = []
colisao' ((DisparoCanhao a p d):s) (h:t) | p == h = (DisparoCanhao a p d) : colisao' s t
                                         | otherwise = colisao' s (h:t)
colisao' (h:t) (x:xs) = h: colisao' t (x:xs)

-- | Funcao
finalBoss :: [Disparo] -> [Disparo]
finalBoss [] = []
finalBoss l =  (filterSCanhao l) ++ colisao' l (posicoesD (filterCanhao l))

filterSCanhao :: [Disparo] -> [Disparo]
filterSCanhao ((DisparoCanhao a b c):t) = filterCanhao t
filterSCanhao (h:t) = h : filterCanhao t

filterCanhao :: [Disparo] -> [Disparo]
filterCanhao [] = []
filterCanhao ((DisparoCanhao a b c):t) = (DisparoCanhao a b c) : filterCanhao t
filterCanhao (h:t) = filterCanhao t

-- | Funcao
anotherOne :: [Disparo] -> [Disparo]
anotherOne [] = []
anotherOne ((DisparoCanhao a (x,y) d):t) | elem (True) (auxil (DisparoCanhao a (x,y) d) t) = anotherOne (talvez (auxil (DisparoCanhao a (x,y) d) t) t)
                                         | otherwise = (DisparoCanhao a (x,y) d) : anotherOne t
anotherOne (h:t) = h : anotherOne t
-- | Funcao
talvez :: [Bool] -> [Disparo] -> [Disparo]
talvez [] [] = []
talvez (True:t) (y:ys) = ys
talvez (False:t) (y:ys) = y : talvez t ys
-- | Funcao
auxil :: Disparo -> [Disparo] -> [Bool] 
auxil x [] = [False] 
auxil (DisparoCanhao a (x,y) d) ((DisparoCanhao c (b,e) f):t) | ((x,y-1) == (b,e) && d==D && f==E) || ((x,y+1) == (b,e) && d==E && f==D) || ((x-1,y) == (b,e) && d==B && f==C) || ((x+1,y) == (b,e) && d==C && f==B) = True : auxil (DisparoCanhao a (x,y) d) t
                                                              | otherwise = False : auxil (DisparoCanhao a (x,y) d) t
auxil h (x:xs) = False : auxil h xs
-- | Funcao
colition' :: [Disparo] -> [Disparo]
colition' [] = []
colition' l = anotherOne (finalBoss l)

-- | Funcao
disparosCanhao :: [Disparo] -> [Jogador] -> Mapa -> [Disparo]
disparosCanhao [] _ m = []
disparosCanhao ((DisparoCanhao a (w,z) D):t) (x:xs) m | temJogador (DisparoCanhao a (w,z) D) (x:xs) && podeMapa (w,z+1) m && podeMapa (w+1,z+1) m = (DisparoCanhao a (w,z+1) D) : disparosCanhao t (x:xs) m
                                                      | otherwise = disparosCanhao t (x:xs) m
disparosCanhao ((DisparoCanhao a (w,z) E):t) (x:xs) m | temJogador (DisparoCanhao a (w,z) E) (x:xs) && podeMapa (w,z) m && podeMapa (w+1,z) m = (DisparoCanhao a (w,z-1) E) : disparosCanhao t (x:xs) m
                                                      | otherwise = disparosCanhao t (x:xs) m
disparosCanhao ((DisparoCanhao a (w,z) B):t) (x:xs) m | temJogador (DisparoCanhao a (w,z) B) (x:xs) && podeMapa (w+1,z) m && podeMapa (w+1,z+1) m = (DisparoCanhao a (w+1,z) B) : disparosCanhao t (x:xs) m
                                                      | otherwise = disparosCanhao t (x:xs) m
disparosCanhao ((DisparoCanhao a (w,z) C):t) (x:xs) m | temJogador (DisparoCanhao a (w,z) C) (x:xs) && podeMapa (w,z) m && podeMapa (w-1,z+1) m = (DisparoCanhao a (w-1,z) C) : disparosCanhao t (x:xs) m
                                                      | otherwise = disparosCanhao t (x:xs) m
disparosCanhao (h:t) x m = h : disparosCanhao t x m
-- | Funcao
atualizaDisparo :: [Disparo] -> [Disparo]
atualizaDisparo ((DisparoCanhao a (x,y) D):t) = (DisparoCanhao a (x,y+1) D) : atualizaDisparo t
atualizaDisparo ((DisparoCanhao a (x,y) E):t) = (DisparoCanhao a (x,y-1) E) : atualizaDisparo t
atualizaDisparo ((DisparoCanhao a (x,y) C):t) = (DisparoCanhao a (x-1,y) C) : atualizaDisparo t
atualizaDisparo ((DisparoCanhao a (x,y) B):t) = (DisparoCanhao a (x+1,y) B) : atualizaDisparo t
atualizaDisparo (h:t) = h : atualizaDisparo t
-- | Funcao
temJogador :: Disparo -> [Jogador] -> Bool
temJogador x [] = True
temJogador (DisparoCanhao a (x,y) D) ((Jogador (w,z) d v l c):t) | v == 0 = temJogador (DisparoCanhao a (x,y) D) t
                                                                 | (x,y+1) == (w,z) || (x-1,y+1) == (w,z) || (x+1,y+1) == (w,z) = False
                                                                 | otherwise = temJogador (DisparoCanhao a (x,y) D) t
temJogador (DisparoCanhao a (x,y) E) ((Jogador (w,z) d v l c):t) | v == 0 = temJogador (DisparoCanhao a (x,y) E) t
                                                                 | (x,y-1) == (w,z) || (x-1,y-1) == (w,z) || (x+1,y-1) == (w,z) = False
                                                                 | otherwise = temJogador (DisparoCanhao a (x,y) E) t
temJogador (DisparoCanhao a (x,y) B) ((Jogador (w,z) d v l c):t) | v ==0 = temJogador (DisparoCanhao a (x,y) B) t
                                                                 | (x+1,y) == (w,z) || (x+1,y+1) == (w,z) || (x+1,y-1) == (w,z) = False
                                                                 | otherwise = temJogador (DisparoCanhao a (x,y) B) t
temJogador (DisparoCanhao a (x,y) C) ((Jogador (w,z) d v l c):t) | v == 0 = temJogador (DisparoCanhao a (x,y) C) t
                                                                 | (x-1,y) == (w,z) || (x-1,y+1) == (w,z) || (x-1,y-1) == (w,z) = False
                                                                 | otherwise = temJogador (DisparoCanhao a (x,y) C) t
-- | Funcao
podeMapa :: Posicao -> Mapa -> Bool
podeMapa (0,0) ((h:t):ts) | h== Vazia = True
                           | otherwise = False
podeMapa _ [[]] = False
podeMapa (0,y) ((h:t):ts) = podeMapa (0,y-1) (t:ts)
podeMapa (x,y) ((h:t):ts) = podeMapa (x-1,y) ts


-- | Inicio Laser (mapa)
mapaLaser :: [Disparo] -> Mapa -> Mapa
mapaLaser [] m = m
mapaLaser ((DisparoLaser a (x,y) d):t) m =  mapaLaser t (posicaoVazia (laserPosicao (DisparoLaser a (x,y) d) m) Vazia m)
mapaLaser (x:t) m = mapaLaser t m
-- | Funcao
posicaoVazia :: [Posicao] -> Peca -> Mapa -> Mapa
posicaoVazia [] _ m = m
posicaoVazia (h:t) Vazia m = posicaoVazia t Vazia (atualizaPosicaoMatriz h Vazia m) 
-- | Funcao
laserPosicao :: Disparo -> Mapa -> [Posicao]
laserPosicao (DisparoLaser a (x,y) D) m | paraLaser (x,y+1) m && paraLaser (x+1,y+1) m = (x,y+1) : (x+1,y+1) : laserPosicao (DisparoLaser a (x,y+1) D) m
                                        | otherwise = []
laserPosicao (DisparoLaser a (x,y) E) m | paraLaser (x,y-1) m && paraLaser (x+1,y-1) m = (x,y-1) : (x+1,y-1) : laserPosicao (DisparoLaser a (x,y-1) E) m
                                        | otherwise = []
laserPosicao (DisparoLaser a (x,y) B) m | paraLaser (x+1,y) m && paraLaser (x+1,y+1) m = (x+1,y) : (x+1,y+1) : laserPosicao (DisparoLaser a (x+1,y) B) m
                                        | otherwise = []
laserPosicao (DisparoLaser a (x,y) C) m | paraLaser (x-1,y) m && paraLaser (x-1,y+1) m = (x-1,y) : (x-1,y+1) : laserPosicao (DisparoLaser a (x-1,y) C) m
                                        | otherwise = []
laserPosicao _ m = []
-- | Funcao
paraLaser :: Posicao -> Mapa -> Bool
paraLaser (0,0) ((h:t):ts) | h== Bloco Indestrutivel = False
                           | otherwise = True
paraLaser _ [[]] = False
paraLaser (0,y) ((h:t):ts) = paraLaser (0,y-1) (t:ts)
paraLaser (x,y) ((h:t):ts) = paraLaser (x-1,y) ts

-- | Laser (Jogadores)
jogadorLaser :: [Disparo] -> Mapa -> [Posicao]
jogadorLaser [] m = []
jogadorLaser (h:t) m = (laserPosicao h m) ++ jogadorLaser t m
-- | Funcao
atualizaJogador :: [Jogador] -> [Posicao] -> [Jogador]
atualizaJogador x [] = x
atualizaJogador [] _ = []
atualizaJogador (h:t) p = (reduzirVida h p) : atualizaJogador t p
-- | Funcao
reduzirVida :: Jogador -> [Posicao] -> Jogador
reduzirVida x [] = x
reduzirVida (Jogador (x,y) d v l c) (h:t) | v>0 && (estaNaMesmaPos (x,y) h) = (Jogador (x,y) d (v-1) l c)
                                          | otherwise = reduzirVida (Jogador (x,y) d v l c) t
-- | Funcao
estaNaMesmaPos :: Posicao -> Posicao -> Bool
estaNaMesmaPos (x,y) (a,b) | (x,y) == (a,b) || (x+1,y) == (a,b) || (x,y+1) == (a,b) || (x+1,y+1) == (a,b) = True
                           | otherwise = False

-- | Laser (Disparos) -> posicoes dos laseres (jogadorLaser)
colisaoLaserCanhao :: [Posicao] -> [Disparo] -> [Disparo]
colisaoLaserCanhao [] x = x
colisaoLaserCanhao _ [] = []
colisaoLaserCanhao (x:xs) ((DisparoCanhao j p d):t) = colisao (x:xs) (DisparoCanhao j p d) ++ colisaoLaserCanhao (x:xs) t
colisaoLaserCanhao x ((DisparoLaser j p d):t) = [(DisparoLaser j p d)] ++ colisaoLaserCanhao x t
colisaoLaserCanhao x ((DisparoChoque p d):t) = [(DisparoChoque p d)] ++ colisaoLaserCanhao x t
-- | Funcao
colisao :: [Posicao] -> Disparo -> [Disparo]
colisao [] x = [x]
colisao (x:xs) (DisparoCanhao j p d) | x == p = []
                                     | otherwise = colisao xs (DisparoCanhao j p d)

-- | remove Laser
removeL :: [Disparo] -> [Disparo]
removeL [] = []
removeL ((DisparoLaser j p d):t) = removeL t 
removeL (x:t) = x:removeL t

---------------- Fim Laser -----------------

-- | Choque
separaDisparos :: [Disparo] -> [Disparo]
separaDisparos [] = []
separaDisparos ((DisparoChoque x y):t) | y <= 0 = separaDisparos t
                                       | otherwise = (DisparoChoque x (y-1)) : separaDisparos t 
separaDisparos (h:t) = h : separaDisparos t














