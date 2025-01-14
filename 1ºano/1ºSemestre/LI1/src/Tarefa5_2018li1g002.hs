-- | Este módulo define funções comuns da Tarefa 5 do trabalho prático.
module Main where

import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game
import Graphics.Gloss.Juicy
import Graphics.Gloss.Data.ViewPort
import Data.List (transpose)
import LI11819
import Tarefa4_2018li1g002
import Tarefa3_2018li1g002
import Tarefa2_2018li1g002
import Tarefa1_2018li1g002
import Tarefa0_2018li1g002
import Debug.Trace

-- * Introduçao Tarefa 5
{- | -}
{- | O objetivo desta tarefa foi passar da parte funcional do jogo para uma parte mais visional, para tal foi utilizado a biblioteca Gloss.  -}
{- | Para começar a fazer o jogo mais visivel, foi necessario criar um novo data base, para podermos armazenar o conteudo necessario para construir o jogo em Gloss, tais como, o estado funcional do jogo, imagens, e outros. -}
{- | Apos isto, construiu-se a funcao main para executar o jogo, neste damos load em imagens para a construçao do mapa, intruduzimos o estadoGloss inicial,damos o frame rate do jogo, entre outros. -}
{- | Foi um pouco desafiante entroduzir a imagem dos jogadores, pois nao consegui fazer com as imagens do jogadores rodassem conforme a direcao do mesmo, e para tal decidi incrementar apenas imagens de quadrados com diferentes cores. -}
{- | É necessario ainda expressar que estive bastante tempo a tentar fazer com que o jogador podesse andar com apenas a tecla presionada, para isto acontecer, adicionei no novo data base "EstadoGloss", uma lista de pares de numeros inteiros e de jogadas, -}
{- | com isto ja consigo saber que jogada cada quer jogador. Pois na funcao "reageEventoGloss" a cada evento efetuado, adiciono o indice do jogador e a jogada que o mesmo quer fazer. Apos as jogadas serem introduzidas nesta lista, a funcao "reageTempoGloss" -}
{- | ira executar essas jogadas,atraves da funcao da Tarefa 1 "jogada" ate que deixe de ser pressionar essa tal tecla, consequentemente sera retirado essa jogada da lista.  -}
{- | Outra dificuldade que encontrei pelo caminho foi fazer o menu, o qual nao consegui construi.-}

-- * Data Base de acomulaçao de informação do jogo

-- | Novo data base
data EstadoGloss = EstadoGloss 
     { estadoJogo :: Estado                        --   Estado do Jogo 
     , estadoJogadores :: [Picture]                --   Lista de Pictures dos jogadores  
     , pictureCanhao :: [Picture]                  --   Lista de Pictures do disparo canhao de cada jogador 
     , pictureLaser :: [Picture]                   --   Lista de Pictures do laser canhao de cada jogador 
     , pictureChoque :: [Picture]                  --   Lista de Pictures do disparo choque de cada jogador 
     , pictureMapa :: (Picture,Picture,Picture)    --   triplo de pictures para a construção do mapa 
     , pictureBackGroung :: Picture                --   Imagem de fundo 
     , jogadoresVivos :: [Int]                     --   Lista de jogadores vivos 
     , estadoKey :: [(Int,Jogada)]}                --   Lista de acontecimentos de cada jogador 

{- | -}
-- * Funções para o desenvolvimento do jogo

{- | Função principal-}
main :: IO ()
main = do i <- loadJuicy "paredeI.png"
          d <- loadJuicy "paredeD.png"
          v <- loadJuicy "Vazia.png"
          b <- loadJuicy "background.png"
          play dm                            -- janela onde irá correr o jogo
                (greyN 0.5)                  -- côr do fundo da janela
                fr                           -- frame rate
                (estadoGlossInicial i d v b) -- estado inicial
                desenhaEstadoGloss           -- desenha o estado do jogo
                reageEventoGloss             -- reage a um evento
                reageTempoGloss              -- reage ao passar do tempo

{- | Frame Rate do jogo-}
fr :: Int
fr = 4

{- | Dimensao do ecra do jogo-}
dm :: Display
dm = InWindow "Game of Tanks" (1280, 768) (200, 200)

{- | Funcao que intrudiz um EstadoGloss inicial. Devido a alguma limitações so existe 1 unico mapa. -}
estadoGlossInicial ::  Maybe Picture -> Maybe Picture -> Maybe Picture -> Maybe Picture -> EstadoGloss
estadoGlossInicial (Just i) (Just d) (Just v) (Just b) = (EstadoGloss (Estado (mapaInicial (30,30)) [(Jogador (1,1) D 6 3 3),(Jogador (1,27) B 6 3 3),(Jogador (27,27) E 6 3 3),(Jogador (27,1) C 6 3 3)] []) [jogadorPicture 0,jogadorPicture 1,jogadorPicture 2,jogadorPicture 3] [disparoCanhao 0,disparoCanhao 1,disparoCanhao 2,disparoCanhao 3] [disparoLaser 0,disparoLaser 1,disparoLaser 2,disparoLaser 3] [disparoChoque 0,disparoChoque 1,disparoChoque 2,disparoChoque 3] (i,d,v) b [0,1,2,3] [])
estadoGlossInicial _ _ _ _ = (EstadoGloss (Estado (mapaInicial (0,0)) [] []) [] [] [] [] (Blank,Blank,Blank) Blank [] [])

--estado2 :: Maybe Picture -> Maybe Picture -> Maybe Picture -> Maybe Picture -> EstadoGloss
--estado2 (Just i) (Just d) (Just v) (Just b) = (EstadoGloss (Estado [[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Bloco Destrutivel,Bloco Destrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]] [(Jogador (1,27) D 6 3 3),(Jogador (27,27) C 6 3 3)] []) [jogadorPicture 0,jogadorPicture 1] [disparoCanhao 0,disparoCanhao 1] [disparoLaser 0,disparoLaser 1] [disparoChoque 0,disparoChoque 1] (i,d,v) b [0,1] [])
 

{- | Construção da imagem do jogador, conforme o seu indice.-}
jogadorPicture :: Int -> Picture
jogadorPicture i = Color (escolheCor i) (Polygon [(0,0),(2,0),(2,2),(0,2),(0,0)])

{- | Construção da imagem do disparo canhao, conforme o seu indice.-}
disparoCanhao :: Int -> Picture
disparoCanhao i = Color (escolheCor i) (Polygon [(0,0),(2,0),(1,1),(0,0)])

{- | Construção da imagem do disparo laser, conforme o seu indice.-}
disparoLaser :: Int -> Picture
disparoLaser i = Color (escolheCor i) (Polygon [(0,0),(1,0),(1,1),(0,1),(0,0)])

{- | Construção da imagem do disparo choque, conforme o seu indice.-}
disparoChoque :: Int -> Picture
disparoChoque i = Color (escolheCor i) (Line [(4,4),(4,-2),(-2,-2),(-2,4),(4,4)])

{- | Escolha de uma cor, conforme o seu indice.-}
escolheCor :: Int -> Color
escolheCor 0 = red
escolheCor 1 = green
escolheCor 2 = white
escolheCor 3 = orange


{- | Nesta funcao transformamos um "EstadoGloss" em imagem, porem com algumas codiçoes. Visto que consiguimos saber quantos jogadores estao vivos atraves da lista de indices dos jogadores, introduzidos inicialmente, foi introdruzido a codiçao de,-}
{- | caso o tamanho dessa lista fosse 0 entao é porque nao existem jogadores vivos no mapa logo o resultado sera um empate, e caso so haja 1 jogador no mapa, o tamanho dessa lista sera entao 1, e podemos dizer que o jogador com essa cor venceu.-}
{- | Caso estas condições nao acontecem (que sera a maior parte do tempo do jogo) ira entao ser desenhado as seguintes imagens, e por esta ordem : -}
{- |       * 1 -> A imagem de fundo;-}
{- |       * 2 -> O mapa;-}
{- |       * 3 -> Os jogadores;-}
{- |       * 4 -> Os diparos (Canhao,Laser,Choque);-}
{- |       * 5 -> E por fim a sidebar-}
desenhaEstadoGloss :: EstadoGloss -> Picture
desenhaEstadoGloss (EstadoGloss (Estado m j d) ej c l eh (i,ds,v) b h ls)
                                | length h == 0 = Pictures [Scale 1 1 $ Color black $ text "Empate!"]
                                | length h == 1 = Pictures [Scale 1 1 $ Color (escolheCor (head h)) $ text "VENCEU!"]
                                | otherwise = applyViewPortToPicture (initialViewport)
                                          (Pictures [applyViewPortToPicture (backGroundViewPort) b,                 --  background picture
                                          (lenght(pegaImagem m (i,ds,v))),                                          --  picture do mapa
                                          applyViewPortToPicture (jogoViewPort) 
                                          (Pictures ((desenhaJogadores j ej) ++                                     --  picture dos jogadores
                                          (desenhaDisparoCanhao d c) ++                                             --  picture dos disparos canhao
                                          (desenhaDisparoLaser d m l) ++                                            --  picture dos disparos laser
                                          (desenhaDisparoChoque d j eh))),                                          --  picture dos disparos choque
                                          (Translate 60 0 fundo),
                                          Pictures (desenhaSideBar 0 60 0 j ej)                                     --  sidebar de informação
                                          ])




--  *          Funções para o Desenho do Mapa                

{- | Nesta funcao transformamos o mapa em uma lista de lista de imagens, para que seja possivel destingir a ordem que as imagens seram desenhadas. -}
pegaImagem :: Mapa -> (Picture,Picture,Picture) -> [[Picture]]
pegaImagem [] m = []
pegaImagem (h:t) m = (construir h m) : pegaImagem t m

{- | Função auxiliar da função anterior.-}
construir :: [Peca] -> (Picture,Picture,Picture) -> [Picture]
construir [] _ = []
construir (h:t) (i,d,v) | h == Vazia = (applyViewPortToPicture (pecaViewPort) v) : construir t (i,d,v)
                        | h == Bloco Indestrutivel = (applyViewPortToPicture (pecaViewPort) i) : construir t (i,d,v)
                        | otherwise = (applyViewPortToPicture (pecaViewPort) d) : construir t (i,d,v)

{- | Nesta funcao transformamos a lista de listas de imagem em uma so imagem na ordem correcta-}
lenght :: [[Picture]] -> Picture
lenght m = Pictures (funcAux m (0,40))

{- | Função auxiliar da função anterior-}
funcAux :: [[Picture]] -> (Float,Float) -> [Picture]
funcAux [] _ = []
funcAux ([]:t) (x,y) = funcAux t (0,(y-2))
funcAux ((h:t):s) (x,y) = (Translate x y h) : funcAux (t:s) ((x+2),y)


-- *           Funções para o Desenho de Jogadores         

{- | Esta função tonar os jogadores em imagens, desenhando um jogador de cada vez.-}
desenhaJogadores :: [Jogador] -> [Picture] -> [Picture]
desenhaJogadores [] _ = []
desenhaJogadores (h:t) (p:ps) = (desenhaJAux h p) : desenhaJogadores t ps

{- | Função auxiliar-}
desenhaJAux :: Jogador -> Picture -> Picture
desenhaJAux (Jogador (x,y) d v l c) p | v>0 = (Translate (convertFloat x) (convertFloat y) p)
                                      | otherwise = Blank

-- *           Funções para o Desenha de disparos de Canhao    

{- | Para esta função transformar a lista de disparos numa lista de imagens, foi nesseçario introduzir a propria lista de disparos para sabermos a possição do disparo e a imagem que vamos desenhar, e como na "desenhaJogadores" desenhamos -}
{- | um disparo de cada vez.-}
desenhaDisparoCanhao :: [Disparo] -> [Picture] -> [Picture]
desenhaDisparoCanhao [] _ = []
desenhaDisparoCanhao ((DisparoCanhao i (x,y) d):t) p = (desenhaCAux (DisparoCanhao i (x,y) d) (encontraIndiceLista i p)) : desenhaDisparoCanhao t p
desenhaDisparoCanhao (_:t) p = desenhaDisparoCanhao t p

{- | Função auxiliar, que desenha o disparo canhao-}
desenhaCAux :: Disparo -> Picture -> Picture
desenhaCAux (DisparoCanhao i (x,y) d) p | d == C = Translate (convertFloat x+2) (convertFloat y) (Rotate 270 p)
                                        | d == D = Translate (convertFloat x) (convertFloat y) p
                                        | d == B = Translate (convertFloat x) (convertFloat y+2) (Rotate 90 p)
                                        | otherwise = Translate (convertFloat x+2) (convertFloat y+2) (Rotate 180 p)


-- *           Funções para o Desenha de disparos de Laser

{- | Esta função serve para desenhar o disparo laser-}
desenhaDisparoLaser :: [Disparo] -> Mapa -> [Picture] -> [Picture]
desenhaDisparoLaser [] _ _ = []
desenhaDisparoLaser ((DisparoLaser i (x,y) d):t) m p = Pictures (printLaser (laserPosicao (DisparoLaser i (x,y) d) m) (encontraIndiceLista i p)) : desenhaDisparoLaser t m p
desenhaDisparoLaser (_:t) m p = desenhaDisparoLaser t m p

{- | Funcao auxiliar -}
printLaser :: [Posicao] -> Picture -> [Picture]
printLaser [] _ = []
printLaser ((x,y):t) p = Translate (convertFloat x) (convertFloat y) p : printLaser t p


-- *           Funções para o Desenha de disparos de Choque

{- | Esta função serve para transformar os disparos choque em imagem-}
desenhaDisparoChoque :: [Disparo] -> [Jogador] -> [Picture] -> [Picture]
desenhaDisparoChoque [] _ _ = []
desenhaDisparoChoque ((DisparoChoque i t):ts) j p = (desenhaChoque (encontraIndiceLista i j) (encontraIndiceLista i p)) : desenhaDisparoChoque ts j p
desenhaDisparoChoque (_:t) j p = desenhaDisparoChoque t j p

{- | Função auxiliar-}
desenhaChoque :: Jogador -> Picture -> Picture
desenhaChoque (Jogador (x,y) d v l c) p = Translate (convertFloat x) (convertFloat y) p


-- *           Funções para desenhar o sidebar

{- | Todas as funções abaixo das destinadas a construção da imagem da sidebar, onde temos todas as informação sobre os jogadores (as suas vidas, o numeros de laser,e choque).-}
-- |
{- | Esta funcao junta as funcoes abaixo e ordena a sidebar.-}
desenhaSideBar :: Int -> Float -> Float -> [Jogador] -> [Picture] -> [Picture]
desenhaSideBar _ _ _ [] _ = []
desenhaSideBar k a b ((Jogador (x,y) d v l c):t) (p:ps) = Translate a b (jogador1 k v l c) : desenhaSideBar (k+1) a (b-20) t ps 

{- | Função destinada para o desenho do fundo da sidebar.-}
fundo :: Picture
fundo = Color azure (Polygon [(40,40),(40,-40),(0,-40),(0,40),(40,40)])

{- | Desenha as a vida, numero de lasers, e numero de choque, de cada jogador.-}
jogador1 :: Int -> Int -> Int -> Int -> Picture
jogador1 a x y z = Pictures [Translate 4 36 jogadorText,(Translate 20 36 (jogadorPicture a)),Translate 5 31 (vidaJ1 x),Translate 5 26 (nLaser1 y),Translate 5 21 (nChoque1 z)]

{- | Função auxiliar-}
jogadorText :: Picture
jogadorText = Scale (0.02) (0.02) $ Color black $ text ("Jogador : ")

{- | Função auxiliar-}
vidaJ1 :: Int -> Picture
vidaJ1 x = Scale (0.02) (0.02) $ Color black $ text ("Vidas : " ++ (show x))

{- | Função auxiliar-}
nLaser1 :: Int -> Picture
nLaser1 x = Scale (0.02) (0.02) $ Color black $ text ("Disparos Laser : " ++ (show x))

{- | Função auxiliar-}
nChoque1 :: Int -> Picture
nChoque1 x = Scale (0.02) (0.02) $ Color black $ text ("Disparos Choque : " ++ (show x))


-- *           Funções que reagem a um evento

{- | Estas proximas funções modificando o EstadoGloss conforme o evento efetuado-}
reageEventoGloss :: Event -> EstadoGloss -> EstadoGloss
reageEventoGloss (EventKey (SpecialKey KeyEnter) Down _ _) (EstadoGloss a b c d e (k,w,z) g h i) = estadoGlossInicial (Just k) (Just w) (Just z) (Just g)
--reageEventoGloss (EventKey (SpecialKey KeySpace) Down _ _) (EstadoGloss a b c d e (k,w,z) g h i) = estado2 (Just k) (Just w) (Just z) (Just g)

reageEventoGloss (EventKey (SpecialKey KeyUp) Down _ _) e = e{estadoKey = acrescentaK (0,Movimenta D) (estadoKey e)}
reageEventoGloss (EventKey (SpecialKey KeyUp) Up _ _) e = e{estadoKey = removeK (0,Movimenta D) (estadoKey e)}

reageEventoGloss (EventKey (SpecialKey KeyDown) Down _ _) e = e{estadoKey = acrescentaK (0,Movimenta E) (estadoKey e)}
reageEventoGloss (EventKey (SpecialKey KeyDown) Up _ _) e = e{estadoKey = removeK (0,Movimenta E) (estadoKey e)}

reageEventoGloss (EventKey (SpecialKey KeyLeft) Down _ _) e = e{estadoKey = acrescentaK (0,Movimenta C) (estadoKey e)}
reageEventoGloss (EventKey (SpecialKey KeyLeft) Up _ _) e = e{estadoKey = removeK (0,Movimenta C) (estadoKey e)}

reageEventoGloss (EventKey (SpecialKey KeyRight) Down _ _) e = e{estadoKey = acrescentaK (0,Movimenta B) (estadoKey e)}
reageEventoGloss (EventKey (SpecialKey KeyRight) Up _ _) e = e{estadoKey = removeK (0,Movimenta B) (estadoKey e)}

reageEventoGloss (EventKey (Char ',') Down _ _) e = e{estadoKey = acrescentaK (0,Dispara Canhao) (estadoKey e)}
reageEventoGloss (EventKey (Char ',') Up _ _) e = e{estadoKey = removeK (0,Dispara Canhao) (estadoKey e)}

reageEventoGloss (EventKey (Char '.') Down _ _) e = e{estadoJogo = jogada 0 (Dispara Laser) (estadoJogo e)}

reageEventoGloss (EventKey (Char '-') Down _ _) e = e{estadoJogo = jogada 0 (Dispara Choque) (estadoJogo e)}

reageEventoGloss (EventKey (Char 'w') Down _ _) e = e{estadoKey = acrescentaK (1,Movimenta D) (estadoKey e)}
reageEventoGloss (EventKey (Char 'w') Up _ _) e = e{estadoKey = removeK (1,Movimenta D) (estadoKey e)}

reageEventoGloss (EventKey (Char 's') Down _ _) e = e{estadoKey = acrescentaK (1,Movimenta E) (estadoKey e)}
reageEventoGloss (EventKey (Char 's') Up _ _) e = e{estadoKey = removeK (1,Movimenta E) (estadoKey e)}

reageEventoGloss (EventKey (Char 'a') Down _ _) e = e{estadoKey = acrescentaK (1,Movimenta C) (estadoKey e)}
reageEventoGloss (EventKey (Char 'a') Up _ _) e = e{estadoKey = removeK (1,Movimenta C) (estadoKey e)}

reageEventoGloss (EventKey (Char 'd') Down _ _) e = e{estadoKey = acrescentaK (1,Movimenta B) (estadoKey e)}
reageEventoGloss (EventKey (Char 'd') Up _ _) e = e{estadoKey = removeK (1,Movimenta B) (estadoKey e)}

reageEventoGloss (EventKey (Char '1') Down _ _) e = e{estadoKey = acrescentaK (1,Dispara Canhao) (estadoKey e)}
reageEventoGloss (EventKey (Char '1') Up _ _) e = e{estadoKey = removeK (1,Dispara Canhao) (estadoKey e)}

reageEventoGloss (EventKey (Char '2') Down _ _) e = e{estadoJogo = jogada 1 (Dispara Laser) (estadoJogo e)}

reageEventoGloss (EventKey (Char '3') Down _ _) e = e{estadoJogo = jogada 1 (Dispara Choque) (estadoJogo e)}

reageEventoGloss (EventKey (Char 't') Down _ _) e = e{estadoKey = acrescentaK (2,Movimenta D) (estadoKey e)}
reageEventoGloss (EventKey (Char 't') Up _ _) e = e{estadoKey = removeK (2,Movimenta D) (estadoKey e)}

reageEventoGloss (EventKey (Char 'g') Down _ _) e = e{estadoKey = acrescentaK (2,Movimenta E) (estadoKey e)}
reageEventoGloss (EventKey (Char 'g') Up _ _) e = e{estadoKey = removeK (2,Movimenta E) (estadoKey e)}

reageEventoGloss (EventKey (Char 'f') Down _ _) e = e{estadoKey = acrescentaK (2,Movimenta C) (estadoKey e)}
reageEventoGloss (EventKey (Char 'f') Up _ _) e = e{estadoKey = removeK (2,Movimenta C) (estadoKey e)}

reageEventoGloss (EventKey (Char 'h') Down _ _) e = e{estadoKey = acrescentaK (2,Movimenta B) (estadoKey e)}
reageEventoGloss (EventKey (Char 'h') Up _ _) e = e{estadoKey = removeK (2,Movimenta B) (estadoKey e)}

reageEventoGloss (EventKey (Char '4') Down _ _) e = e{estadoKey = acrescentaK (2,Dispara Canhao) (estadoKey e)}
reageEventoGloss (EventKey (Char '4') Up _ _) e = e{estadoKey = removeK (2,Dispara Canhao) (estadoKey e)}

reageEventoGloss (EventKey (Char '5') Down _ _) e = e{estadoJogo = jogada 2 (Dispara Laser) (estadoJogo e)}

reageEventoGloss (EventKey (Char '6') Down _ _) e = e{estadoJogo = jogada 2 (Dispara Choque) (estadoJogo e)}

reageEventoGloss (EventKey (Char 'i') Down _ _) e = e{estadoKey = acrescentaK (3,Movimenta D) (estadoKey e)}
reageEventoGloss (EventKey (Char 'i') Up _ _) e = e{estadoKey = removeK (3,Movimenta D) (estadoKey e)}

reageEventoGloss (EventKey (Char 'k') Down _ _) e = e{estadoKey = acrescentaK (3,Movimenta E) (estadoKey e)}
reageEventoGloss (EventKey (Char 'k') Up _ _) e = e{estadoKey = removeK (3,Movimenta E) (estadoKey e)}

reageEventoGloss (EventKey (Char 'j') Down _ _) e = e{estadoKey = acrescentaK (3,Movimenta C) (estadoKey e)}
reageEventoGloss (EventKey (Char 'j') Up _ _) e = e{estadoKey = removeK (3,Movimenta C) (estadoKey e)}

reageEventoGloss (EventKey (Char 'l') Down _ _) e = e{estadoKey = acrescentaK (3,Movimenta B) (estadoKey e)}
reageEventoGloss (EventKey (Char 'l') Up _ _) e = e{estadoKey = removeK (3,Movimenta B) (estadoKey e)}

reageEventoGloss (EventKey (Char '7') Down _ _) e = e{estadoKey = acrescentaK (3,Dispara Canhao) (estadoKey e)}
reageEventoGloss (EventKey (Char '7') Up _ _) e = e{estadoKey = removeK (3,Dispara Canhao) (estadoKey e)}

reageEventoGloss (EventKey (Char '8') Down _ _) e = e{estadoJogo = jogada 3 (Dispara Laser) (estadoJogo e)}

reageEventoGloss (EventKey (Char '9') Down _ _) e = e{estadoJogo = jogada 3 (Dispara Choque) (estadoJogo e)}
reageEventoGloss _ s = s -- ignora qualquer outro evento 

{- | Esta função esta ligada com a funçao "reageEventGloss" pois esta acrescenta um evento acontecido, na lista do par (Int,Jogada).-}
acrescentaK :: (Int,Jogada) -> [(Int,Jogada)] -> [(Int,Jogada)]
acrescentaK x [] = [x]
acrescentaK x l | elem x l = l
                | otherwise = [x]++l

{- | Esta função tambem esta ligada com a funcção "reageEventGloss", porem faz o contrario da função anterior, em que esta remove um evento da lista.-}
removeK :: (Int,Jogada) -> [(Int,Jogada)] -> [(Int,Jogada)]
removeK _ [] = []
removeK x (h:t) | x == h = t
                | otherwise = h : removeK x t

-- *           Funções que reage ao tempo

{- | Esta e a função principal da reação ao tempo , em que define o que acontece em cada tick.-}
reageTempoGloss :: Float -> EstadoGloss -> EstadoGloss
reageTempoGloss n e = e{estadoJogo = tick (efetuaJogada (estadoJogo e) (estadoKey e)), jogadoresVivos = listaVivos (estadoJogo e) (jogadoresVivos e)}

{- | Nesta função recebemos o estado do jogo e a lista de eventos acontecidos num tick e efetuamos essas alterações no estado do jogo. Para tal ultilizamos a funcao "jogada" da Tarefa 1.-}
efetuaJogada :: Estado -> [(Int,Jogada)] -> Estado
efetuaJogada e [] = e
efetuaJogada e (h:t) = efetuaJogada (jogada (fst h) (snd h) e) t

{- | Esta função verifica em cada tick se ha jogadores sem vida e caso algum nao tenho vida, o indice desse jogador é retido da lista de jogadores vivos.-}
{- | Ultilizei aqui a função trace pois, estava a ter um erro ao qual se o primeiro jogador ficasse sem vida, o jogo acabava. Este erro estava a ocorrer devido a um erro na funçao a qual verificava se o tira vidas, se tivesse nao acontecia nada a lista de -}
{- | jogadores vivos, porem quando um dos jogadores tivesse 0 vidas, o indice era retirado da lista, e no proximo tick outro indice era removido, porque eu nao tinha nenhum controlo do indice que saia.-}
{- | No inicio nao estava a conseguir identificar o erro, e a função trace ajudou-me a encontrar o erro, pois consiguia assim ver o que é que se estava a passar com a lista de jogadores, na percursão dos ticks.-}
listaVivos :: Estado -> [Int] -> [Int]
listaVivos (Estado m [] d) _ = []
listaVivos (Estado m j d) [] = []
listaVivos (Estado m j i) (h:t) | trace (show (h:t)) $ (encontraVidaJ j h) == 0 = listaVivos (Estado m j i) t
                                | otherwise = h : listaVivos (Estado m j i) t

{- | Função auxiliar da função anterior-}
encontraVidaJ :: [Jogador] -> Int -> Int
encontraVidaJ ((Jogador (x,y) d v l c):t) 0 = v
encontraVidaJ (h:t) x = encontraVidaJ t (x-1)

-- *           Funções auxiliares para a funcionalidade do jogo

{- | Função de mudança de tipos -}
{- | Esta função foi introduzida pois estava a ter bastantes erros de tipos do Int para Float, para tal achei que facilitava as coisas se tivesse uma função que me fizzesse essa modificaçao no tipo.-}
convertFloat :: Int -> Float
convertFloat x = fromIntegral x :: Float

{- | Funcao ViewPort-}
jogoViewPort :: ViewPort
jogoViewPort = ViewPort { viewPortTranslate = (-10.6, -9.5), viewPortRotate = 0, viewPortScale = 2 }

{- | Funçao para a aumentar o tamanho das imagens do jogo.-}
initialViewport :: ViewPort
initialViewport = ViewPort { viewPortTranslate = (-50, 0), viewPortRotate = 0, viewPortScale = 8 }

{- | Funcao ViewPort da imagem das peças do mapa-}
pecaViewPort :: ViewPort
pecaViewPort = ViewPort { viewPortTranslate = (-400,0), viewPortRotate = 0, viewPortScale = 0.05 }

{- | Funcao ViewPort da imagem de fundo-}
backGroundViewPort :: ViewPort
backGroundViewPort = ViewPort { viewPortTranslate = (50,0), viewPortRotate = 0, viewPortScale = 0.2 }




