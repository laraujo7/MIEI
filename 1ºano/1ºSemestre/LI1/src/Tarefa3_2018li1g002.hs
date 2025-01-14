-- | Este módulo define funções comuns da Tarefa 3 do trabalho prático.
module Tarefa3_2018li1g002 where

import LI11819
import Data.Char
import Tarefa0_2018li1g002
import Tarefa1_2018li1g002
import Tarefa2_2018li1g002
import Debug.Trace

-- * Testes

-- | Testes unitários da Tarefa 3.
--
-- Cada teste é um 'Estado'.
testesT3 :: Estado
testesT3 = (Estado ([[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Bloco Destrutivel,Bloco Destrutivel,Bloco Indestrutivel],[Bloco Indestrutivel,Vazia,Vazia,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Destrutivel,Vazia,Bloco Indestrutivel],[Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel,Bloco Indestrutivel]]) ([(Jogador (2,42) D 3 2 1),(Jogador (4,3) E 2 1 1),(Jogador (2,2) B 33 3 3)]) ([(DisparoCanhao 16 (3,39) B),(DisparoChoque 3 92),(DisparoLaser 2 (21,2) C)]))


-- * Funções principais da Tarefa 3.

-- | Comprime um 'Estado' para formato textual.
--
-- __NB:__ A função 'show' representa um 'Estado' num formato textual facilmente legível mas extenso.
--
-- __NB:__ Uma boa solução deve representar o 'Estado' dado no mínimo número de caracteres possível.
comprime :: Estado -> String
comprime e = total (mapaEstado e) ++ " " ++ comprimirLista (jogadoresEstado e) ++ " " ++ comprimeDisparosCLH (disparosEstado e)

-- * Estrategia seguida para a comprenssão do mapa

-- | Para comprimir o mapa a minha estragia foi a seguinte : 
{- |  * 1) Primeiro retirar as bordas do mapa, pos sabemos que este tem sempre os blocos indestrutiveis, para isso ultizei a funcao 'retirarBoradas' que tem como auxiliar as seguintes funcoes : 'antesDeComprimir','aDC','retirar1C','retirar2C'; -}
{- |  * 2) Apos retirar as bordas, começei por transformar os "Blocos Indestrutivel" em apenas uma letra 'i', os "Blocos Destrutivel" em 'd', e os blocos " Vazia " em 'v', utilizando as funcoes : 'comprimeMapa' e 'comprimeLinha'; -}
{- |  * 3) Para comprimir ainda mais o mapa usei as funcoes 'constroiMSet' e 'cM' que verifica se os blocos a sua direita sao iguaiscaso sejam, ao primeiro este blocos de agrupam e formam assim um set de blocos (por exemplo : "vvvv" sera agora "4v"); -}
{- |  * 4) De seguida, como para descomprimir vou precisar do numero de colunas do mapa, pois ira ser necessario colocar as bordas de volta, decidi entao tambem posicionar o numero de colunas do mapa apos a comprensao do mapa, para isso utilizei as funcoes 'dimensaoMapa','dimensaoMapa', e 'mapaString'; -}
{- |  * 5) Para finalizar juntei a funcao que comprimia o mapa com a funcao que comprimia a dimensao do mapa, formando assim a funcao final da comprensao do mapa, a funcao 'total'. -}
compressaoDoMapa :: Mapa -> String
compressaoDoMapa [] = []

{- | 1. funcao para retirar as Bordas do mapa) -}
retirarBordas :: Mapa -> Mapa
retirarBordas [] = []
retirarBordas l = antesDeComprimir (aDC (retirar1C (retirar2C l)))

{- | primeiro auxiliar para retirar as bordas do mapa -}
antesDeComprimir :: Mapa -> Mapa
antesDeComprimir [] = []
antesDeComprimir l = (drop 1 l)

{- | segundo auxiliar para retirar as bordas do mapa -}
aDC :: Mapa -> Mapa
aDC [] = []
aDC l =  (take ((length l)-1) l)

{- | terceiro auxiliar para retirar as bordas do mapa -}
retirar1C :: Mapa -> Mapa
retirar1C [] = []
retirar1C (h:t) = (drop 1 h) : retirar1C t

{- | quarto auxiliar para retirar as bordas do mapa -}
retirar2C :: Mapa -> Mapa
retirar2C [] = []
retirar2C (h:t) = (take ((length h)-1) h):retirar2C t

{- | 2. funcao para comprimir os blocos do mapa em letras-}
comprimeMapa :: Mapa -> String
comprimeMapa [] = []
comprimeMapa (l:t) = (comprimeLinha l) ++ comprimeMapa t

{- | auxiliar da funcao anterior -}
comprimeLinha :: [Peca] -> String
comprimeLinha [] = []
comprimeLinha (h:t) | h == x = "i" ++ comprimeLinha t
                    | h == y = "d" ++ comprimeLinha t
                    | otherwise = "v" ++ comprimeLinha t
                    where x = Bloco Indestrutivel
                          y = Bloco Destrutivel

{- | 3. funcao que comprime ainda mais o mapa agrupando as letras seguidamente repetidas -}
constroiMSet' :: String -> String
constroiMSet' [] = []
constroiMSet' (h:t) = test' ((cM 1 h t)+1) ++ [h] ++ constroiMSet' (drop (cM 1 h t) t)

{- | auxiliar da funcao anterior, que conta o numero de letras seguidamente repetidas -}
cM :: Int -> Char -> String -> Int
cM x h [] = 0
cM a h (x:xs) | h==x = a+cM a h xs
              | otherwise = 0

{- | 4. funcao que me permite afixar o numero de colunas do mapa na comprensao do mapa -}
dimensaodoMapa :: Mapa -> String
dimensaodoMapa l = mapaString (dimensaoMapa l)

{- |  auxilar da funcao anterior que vai calcular a dimensao do mapa-}
dimensaoMapa :: Mapa -> Dimensao
dimensaoMapa [] = (0,0)
dimensaoMapa l = (nLi l , length (head l))

{- |  auxiliar necessaria da funcao 'dimensaodoMapa' para obter o numero de colunas do mapa e adcionar uma virgula
para podermos separar a comprensao do mapa e o numero de colunas do mapa-}
mapaString :: Dimensao -> String
mapaString (x,y) = "," ++ test' y

{- | 5. Esta funcao recebe todas as funcoes anteriores e comprime o mapa e o numero das suas colunas em uma String -}
total :: Mapa -> String
total l = constroiMSet' (comprimeMapa (retirarBordas l)) ++ dimensaodoMapa l

-- * Estrategia seguida para comprenssão da lista de Jogadores

{- |  Para comprimir a lista de jogadores simplismente segui a mesma regra que usei para comprimir o mapa, dividindo
as varias caracteristicas do jogador por virgulas e dividindo os jogadores por '$'. Para isso utilizei as funcoes
'comprimeJogador' e 'comprimirLista' -}
compressaoDaListaDeJogadores :: [Jogador] -> String
compressaoDaListaDeJogadores [] = []

{- | nesta funcao utilizo a funcao 'comprimeJogador' e adiciono o simbolo "$" para dividir os diversos jogadores -}
comprimirLista :: [Jogador] -> String
comprimirLista [] = []
comprimirLista [x] = comprimeJogador x
comprimirLista (h:t) = (comprimeJogador h) ++ "$" ++ comprimirLista t 

{- | auxiliar da funcao anterior. Ao aplicar a funcao 'test' comprimo as varias caracteristicas do jogador e adiciono
uma virgula para as separar -}
comprimeJogador :: Jogador -> String
comprimeJogador (Jogador (x,y) d v l c) = test' x ++ "," ++ test' y ++ "," ++ show d ++ "," ++  test' v ++ "," ++  test' l ++ "," ++ test' c

-- * Estrategia seguida para comprenssão da lista de Disparos

{- | Para comprimir a lista de disparos, tambem segui o mesmo metodo da comprensao dos jogadores, porem adicionei no
inicio de cada disparo uma letra, para o Canhao usei a letra "A", para o Laser "L" e para o Choque "H". Para tal, usufrui
das funcoes 'comprimeDisparosCLH' e 'comprimeDisparoCLH'. -}
compressaoDaListaDeDisparos :: [Disparo] -> String
compressaoDaListaDeDisparos [] = []

{- |  Esta funcao adquerede as solucoes obtidas da funcao 'comprimeDisparoCLH' e separa os jogadores como o simbolo "$".-}
comprimeDisparosCLH :: [Disparo] -> String
comprimeDisparosCLH [] = []
comprimeDisparosCLH [x] = comprimeDisparoCLH x
comprimeDisparosCLH (h:t) = (comprimeDisparoCLH h) ++ "$" ++(comprimeDisparosCLH t)

{- | esta funcao adiciona um letra para identificar o tipo do disparo, pois esta sera necessaria no funcao 'descomprime',
divide os caracteristicas do disparo por virgulas, com tambem utiliza a funcao 'test' para uma melhor comprensao do disparo -}
comprimeDisparoCLH :: Disparo -> String
comprimeDisparoCLH (DisparoCanhao x (a,b) d) = "A" ++ "," ++ test' x ++ "," ++ test' a ++ "," ++ test' b ++ "," ++ show d 
comprimeDisparoCLH (DisparoLaser x (a,b) d) = "L" ++ "," ++ test' x ++ "," ++ test' a ++ "," ++ test' b ++ "," ++ show d 
comprimeDisparoCLH (DisparoChoque x y) = "H" ++ "," ++ show x ++ "," ++ test' y

-- * Funcao para melhor compressão

-- | Para uma melhor comprensao do Estado, decidi que todos os numeros representados na lista final de comprensao passariam por uma funcao auxilia, a funcao 'test', para que este fosse convertido em simbolo, segunda a tabela de ascii, porem com algumas restrincoes.
{- | Esta restrincoes sao as seguintes : -}
{- |  * ' ' - pois este simbolo é utilizado para dividir o mapa da lista de jogadores e a lista de jogadores da lista dos disparos; -}
{- | * '$' - tal como o simbolo anterior este tambem é ultilizado para dividir, porem este divide apenas os diferentes jogadores; -}
{- | * ',' - este simbolo, talvez o mais importante, dividi todos as caracterias necessarias para a descompresão do Estado; -}
{- | * 'v','i','d' - estas letras sao utilizadas no comprimir do mapa para amazenar os diferentes tipos de blocos; -}
{- | * 'A','L','H' - como foi necessario adicionar estas letras na comprensao do Estado, convem nao as repetir em outros locais, pois estas têm um lugar proprio para tudo funcionar; -}
{- | * 'E','D','B','C' - estas letras sao necessarias na comprensao para guardar as direçoes tantos dos disparos como dos jogadores; -}
{- | * Para alem destas restrincao adicionei tambem um ultima restricap que faz com que so sejam aceites conversoes de numeros
entre 33 a 47 e de 57 a 127. Porque para baixo de 33 na tabela de ascii sao simbolos com 3 caracteres, ou seja nao valeria a pena estar a mudar 
um numero que tem 2 ou menos caracteres para um simbolo com 3 caracteres. O mesmo foi o meu pensamento para numeros maiores do que 127. Por ultimo 
restrinji que os numeros entre 47 e 57 nao podem converter porque estes nas tabela de ascii sao numeros de 0 a 9, e assim iria ficar complicado para
destingir simbolos de numeros na descompensao.-}
test' :: Int -> String
test' x | (x /= ord ' ') && (x /= ord '$') && (x /= ord ',') && (x /= ord 'v') && (x /= ord 'i') && (x /= ord 'd') && (x /= ord 'A') && (x /= ord 'L') && (x /= ord 'H') && (x /= ord 'E') && (x /= ord 'D') && (x /= ord 'B') && (x /= ord 'C') && ((x > 32) && (x < 48) || (x>57) && (x < 127)) = [chr x]
        | otherwise = show x

--
-- | Descomprime um 'Estado' no formato textual utilizado pela função 'comprime'.

--
-- __NB:__ A função 'comprime' é válida de for possível recuperar o 'Estado' utilizando a função 'descomprime', i.e.:
--
-- prop> descomprime . comprime = id
--
-- __NB:__ Esta propriedade é particularmente válida para a solução pré-definida:
--
-- prop> read . show = id
descomprime :: String -> Estado
descomprime l = Estado (codigoFinalM (separarMapa (porNormal l))) (descomprimeJogadores (separarJogadores (porNormal l))) (selecionaDisparo (separarDisparo (porNormal l)))

-- *  Estrategia seguida para descomprenssão do mapa

-- | O meu pensamento para descomprimir o Estado, foi basicamente fazer funcoes inversas as funcoes que utilizei para comprimir o Estado, porem nao foi assim tao facil. Por isso dividi o problema em varias partes :
{- |  * 1) Primeiro começei por reverter a funcao test, e colocar a descompressão na sua forma normal, para isso apliquei a funcao 'porNormal'; -}
{- |  * 2) De seguida decidi separar a comprensao do mapa, a lista de jogadores e a lista de disparos, para isto usei as funcoes 'separarMapa', 'separarJogadores' e 'separarDisparo'; -}
{- |  * 3) Apos a esta separaçao escolhi por trabalhar primeiro a descompressão do mapa. Sendo assim comecei por separar o mapa, do numero de colunas no mapa, que tinha previamente guardado, para tal utilizei as funcoes 'antesdaDesco' e 'descomprimeDimensao'; -}
{- |  * 4) Para começar a construir o mapa optei por transformar a String com a informaçao do mapa em uma lista de pares com o numero de blocos seguidos e o proprio bloco, porem neste passo ainda nao transformamos o Char em Blocos -> [(Int,Char)], para executar esta transformaçao construi as funcoes 'constrois','separaNumeros','letra','buscades','encontra' e 'descomprimeEmSet'; -}
{- |        -> 4.1) 'controis' - Para construir esta funcao utilizei 3 funcoes axiliares, 'separaNumeros' que vai buscar os primeiros numeros na comprensao, 'letra' que vai buscar a primeira ocorrencia de uma letra na comprensao, e a funcao 'buscades' que fornece o comprimendo da lista que sobrou ao retirar a primeira ocorrencia da letra. -}
{- |        -> 4.2) 'descomprimeEmSet' - utiliza a funcao 'constrois' com a lista previamente separada da funcao 'separarMapa' -}
{- |  * 5) Apos a construçao deste Set, transformo o agora entao num Set [(Int,Peca)], com a funcao 'descomp' que tem como auxiliar a funcao 'descomprimes', o qual transforma os diferentes Char's em Pecas, "v" -> Vazia, "i" -> Bloco Indestrutivel, "d" -> Bloco Destrutivel; -}
{- |  * 6) Posteriormente, modifiquei o Set [(Int,Peca)] formado anteriormente, para uma lista de Pecas, onde aqui reproduzo todas as pecas do mapa com a ajuda de um replicate, com exesao das bordas que irei adcionar ja de seguida,e para tal utizei a funcao 'criacaoDoMapa'; -}
{- |  * 7) Consecutivamente, nestas duas funcoes 'insertExp' e 'insertExtremidade' adiciono entao as bordas do mapa na lista; -}
{- |  * 8) Para que fosse introduzido uma String e nos desse como respostas a tal lista de Pecas, criei a funcao 'setMapa' que tem como funcao axiliar 'codigoFinal', as quais sao introduzidas as funcoes necessarias, tais como o tipo de bloco para fazer as bordas, e a funcao 'descomprimeADimensao' que dado a String da 'descomprimeDimensao' da nos o numero de colunas do mapa; -}
{- |  * 9) Finalizando entao a construcao do mapa, formei a funcao 'codigoFinalM' que com a funcao auxiliar 'matrizTrans2' gera a matriz final do mapa. -}
descompressaoDoMapa :: String -> Mapa
descompressaoDoMapa [] = []

{- | Como na funcao comprimir utilizei a funcao 'test', para voltar ao estado normal da comprensao do Estado utilizei esta funcao. -}
porNormal :: String -> String
porNormal [] = []
porNormal (h:t) | ((ord h > 32) && (ord h < 48) || (ord h > 57) && (ord h < 127)) && (ord h /= 65) && (ord h /= 76) && (ord h /= 72) && (ord h /= 44) && (ord h /= 36) && (ord h /= 105) && (ord h /= 118) && (ord h /= 100) && (ord h /= 67) && (ord h /= 69) && (ord h /= 66) && (ord h /= 68) = show (ord h) ++ porNormal t
                | otherwise = [h] ++ porNormal t

{- | Esta funcao separa o mapa do resto do Estado, facilitanto assim a descompressão do Estado, e permintindo-me trabalhar
a descompressão por partes. -}
separarMapa :: String -> String
separarMapa [] = []
separarMapa (h:t) | ord h /= ord ' ' = h:separarMapa t
                  | otherwise = []

{- | Esta funcao separa a lista de jogadores do resto do Estado. -}
separarJogadores :: String -> String
separarJogadores [] = []
separarJogadores (h:t) | ord h /= ord ' ' = separarJogadores t
                       | otherwise = separarMapa t

{- | Esta funcao separa a lista de desparos do resto do Estado. -}
separarDisparo :: String -> String
separarDisparo [] = []
separarDisparo (h:t) | ord h /= ord ' ' = separarDisparo t
                     | otherwise = separarJogadores t

{- | Esta funcao permite-me separar a comprensao do mapa do numero de colunas do mapa. -}
antesdaDesco :: String -> String
antesdaDesco [] = []
antesdaDesco (h:t) | (ord h) /= (ord ',') = h :antesdaDesco t
                   | otherwise = [] 

{- | Construcao de um Set com o numero de palavras consecutivas e a sua letra respetiva -}
constrois :: String -> [(Int,Char)]
constrois [] = []
constrois l = (converti (separaNumeros l),letra l) : constrois (drop (length l+1 - encontra l) l)

{- | Nesta funcao vou buscar a primeira aparencia de um numero na string -}
separaNumeros :: String -> String
separaNumeros [] = []
separaNumeros (h:t) | isDigit h = h :separaNumeros t
                    | otherwise = []

{- | Nesta funcao vou buscar a primeira ocorrencia de uma letra na string-}
letra :: String -> Char
letra (h:t) | isAlpha h = h
            | otherwise = letra t

{- | O meu objetivo com esta funcao é ir buscar o comprimenta da lista que sobrou ao retirar a primeira aparencia
do numero e da letra -}
encontra :: String -> Int
encontra [] = 0
encontra l = length (buscades l)

{- | auxiliar na funcao anterior -}
buscades :: String -> String
buscades (h:t) | isAlpha h = (h:t)
               | otherwise = buscades t

{- | Constroi um set de [(Int,Char)] com ajuda da funcao 'constrois' e a funcao que separa o mapa do resto do estado 'antesdaDesco' -}
descomprimeEmSet :: String -> [(Int,Char)]
descomprimeEmSet [] = []
descomprimeEmSet l = constrois (antesdaDesco l)

{- | Transforma o Set anterior num Set novo de [(Int,Peca)] -}
descomprimes :: [(Int,Char)] -> [(Int,Peca)]
descomprimes [] = []
descomprimes ((a,b):t) | b == 'i' = (a,x) :descomprimes t
                      | b == 'd' = (a,y) :descomprimes t
                      | otherwise = (a,z) :descomprimes t
                      where x = Bloco Indestrutivel
                            y = Bloco Destrutivel
                            z = Vazia

{- | Junta funcoes para que recebida uma string seja entrege o Set anterior [(Int,Peca)] -}
descomp :: String -> [(Int,Peca)]
descomp [] = []
descomp l = descomprimes (descomprimeEmSet l)

{- | Formacao de uma lista com todas as pecas do mapa, com exeçao das bordas -}
criacaoDoMapa :: [(Int,Peca)] -> [Peca]
criacaoDoMapa [] = []
criacaoDoMapa ((a,b):t) = (replicate a b)++criacaoDoMapa t 

{- | Instroduçao das bordas na lista de pecas -}
insertExp :: Peca -> Int -> Int -> [Peca] -> [Peca]
insertExp k _ _ [] = [k]++[k]
insertExp k x y (h:t) | (y-2)/=0 = h:insertExp k x (y-1) t
                      | otherwise = k:k:insertExp k x x (h:t)

{- | Auxiliar da funcao anterior-}
insertExtremidade :: [Peca] -> Int -> Peca -> [Peca]
insertExtremidade [] _ _ = []
insertExtremidade l y b = (replicate (y+1) b) ++ l ++ (replicate (y-1) b)

{- | Introduçao de todas as variaveis necessaria para formar a lisra de Pecas, tais como, o Bloco para formar as bordas,o numero de colunas do mapa,
 e a propria string. -}
codigoFinal :: Peca -> Int -> String -> [Peca]
codigoFinal _ 0 _ = []
codigoFinal b x l = insertExtremidade (insertExp (Bloco Indestrutivel) x x (criacaoDoMapa (descomp l))) x (Bloco Indestrutivel)

{- | Esta funcao vai buscar o numero de colunas do mapa, porem em string -}
descomprimeDimensao :: String -> String
descomprimeDimensao [] = []
descomprimeDimensao (h:t) | (ord h) /= (ord ',') = descomprimeDimensao t
                          | otherwise = t

{- | Funcao que fornece o numero de colunas do mapa em Int-}
descomprimeADimensao :: String -> Int
descomprimeADimensao l = converti (descomprimeDimensao l)

{- | Lista final de Peca's do mapa-}
setMapa :: String -> [Peca]
setMapa l = codigoFinal (Bloco Indestrutivel) (descomprimeADimensao l) l

{- | Codigo final para a criacao do mapa, que tem como auxilar a funcao 'matrizTrans2' -}
codigoFinalM :: String -> Mapa
codigoFinalM [] = []
codigoFinalM l = matrizTrans2 (setMapa l) (descomprimeADimensao l)

{- | Auxiliar da funcao anterior-}
matrizTrans2 :: [Peca] -> Int -> [[Peca]]
matrizTrans2 [] _ = []
matrizTrans2 (h:t) y = take y (h:t) : matrizTrans2 (drop y (h:t)) y

-- * Introdução a descompressão a lista de Jogadores

{- |  Para descomprimir a lista de Jogadores começei por fazer uma funcao 'descomprimeJogador' que trabalha um unico jogador de cada vez, para que isso acontecer, decidi separar os jogadores um por um com a funcao 'descomprimeJogadores', para tal funcionar foi necessario tambem criar 2 funcoes auxiliares para selecionar o jogador 'selecionaJogadores' e dropa-lo 'dropaJogador'. -}
{- |  Ou seja, na funcao 'descomprimeJodaor' primeiro seleciono o primeiro jogador com a funcao 'selecionaJogadores' de seguida trabalho esse jogador com a funcao 'descomprimeJogador', e de seguida faço a recursividade da funcao 'descomprimeJogadores' com a string da formada pela 'dropaJogador' que elemina o jogador que acabamos de trabalhar.  -}
descompressaoDaListaDeJogadores :: String -> [Jogador]
descompressaoDaListaDeJogadores [] = []

{- | Descomprime um jogador referindo a sua posicao, direcao, numero de vidas, numero de laser's e numero de choques. -}
descomprimeJogador :: String -> Jogador
descomprimeJogador l = Jogador (converti (separaNumeros l),converti (separaNumeros(descomprimeDimensao l))) (convertc [letra l]) (converti (separaNumeros(descomprimeDimensao(descomprimeDimensao(descomprimeDimensao l))))) (converti (separaNumeros(descomprimeDimensao(descomprimeDimensao(descomprimeDimensao(descomprimeDimensao l)))))) (converti (separaNumeros(descomprimeDimensao(descomprimeDimensao(descomprimeDimensao(descomprimeDimensao(descomprimeDimensao l)))))))

{- | Seleciona o primeiro jogador da string fornecida. -}
selecionaJogadores :: String  -> String
selecionaJogadores [] = [] 
selecionaJogadores (h:t) | ord h /= ord '$' = h:selecionaJogadores t
                         | otherwise = []

{- | Elimina o primeiro jogador da string. -}
dropaJogador :: String -> String
dropaJogador [] = []
dropaJogador l = drop (length (selecionaJogadores l)+1) l

{- | Descomprime a lista de jogadores com axilio das funcoes anteriores. -}
descomprimeJogadores :: String -> [Jogador]
descomprimeJogadores [] = []
descomprimeJogadores l = (descomprimeJogador (selecionaJogadores l)) : (descomprimeJogadores (dropaJogador l))

-- * Introdução a descompressão da lista de Disparos

{- |  Para descomprimir a lista de disparos, comecei por verificar o primeiro elemento da string, pois na comprensao do estado foi introduzido uma letra que guardasse o tipo de disparo, caso o primeiro elemento seja "H" selecionamos o disparo que esta a ser dividio pelo simbolo "$" e é nos levado para uma funcao axuliar 'divideH' que constroi o DisparoChoque, caso seja "L" tambem selecionamos o disparo e é nos transferido para a funcao 'divideL' que travalha o DisparoLaser, e caso nao seja nenhum dos dois selecionamos o disparo e este é direcionado para a funcao axiliar 'divideA' que trabalha o 'DisparoCanhao'. -}
{- | Apos isto, faz se a recursividade da funcao 'selecionaDisparo' com a string da lista de disparos sem o disparo previamente trabalhado. -}
descompressaoDaListaDeDisparos :: String -> [Disparo]
descompressaoDaListaDeDisparos [] = []

{- |  Constroi a lista de disparos com ajuda das funcoes auxiliares 'divideH','divideL','divideA','selecionaJogadores','dropaJogador'. -}
selecionaDisparo :: String -> [Disparo]
selecionaDisparo [] = []
selecionaDisparo (h:t) | ord h == ord 'H' = divideH (selecionaJogadores (h:t)) : selecionaDisparo (dropaJogador (h:t))
                       | ord h == ord 'L' = divideL (selecionaJogadores (h:t)) : selecionaDisparo (dropaJogador (h:t))
                       | otherwise = divideA (selecionaJogadores (h:t)) : selecionaDisparo (dropaJogador (h:t))

{- | Funcao auxiliar. -}
divideH :: String -> Disparo
divideH l = DisparoChoque (converti (separaNumeros (descomprimeDimensao l))) (convertt (separaNumeros (descomprimeDimensao (descomprimeDimensao l))))

{- | Funcao auxiliar. -}
divideL :: String -> Disparo
divideL l = DisparoLaser (converti (separaNumeros (descomprimeDimensao l))) (converti (separaNumeros (descomprimeDimensao (descomprimeDimensao l))),converti (separaNumeros (descomprimeDimensao (descomprimeDimensao (descomprimeDimensao l))))) (convertc [letra(descomprimeDimensao l)])

{- | Funcao auxiliar. -}
divideA :: String -> Disparo
divideA l = DisparoCanhao (converti (separaNumeros (descomprimeDimensao l))) (converti (separaNumeros (descomprimeDimensao (descomprimeDimensao l))),converti (separaNumeros (descomprimeDimensao (descomprimeDimensao (descomprimeDimensao l))))) (convertc [letra(descomprimeDimensao l)])

-- * Conversões auxiliares

{- | Conversor de uma String para Ticks. -}
convertt :: String -> Ticks
convertt l = read l :: Ticks

{- | Conversor de uma String para Int. -}
converti :: String -> Int
converti l = read l :: Int

{- | Conversor de uma String para Direcao. -}
convertc :: String -> Direcao
convertc l = read l :: Direcao

