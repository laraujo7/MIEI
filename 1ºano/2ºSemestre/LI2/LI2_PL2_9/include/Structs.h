    #ifndef PROJ_STRUCTS_H
    #define PROJ_STRUCTS_H


/// tipos de valores existentes no jogo
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;



typedef struct Ranking *LRanking;

///nodo da lista ligada do ranking constituido pelo nome e o score do jogador
typedef struct Score {
    char nome[256];
    float score;
} Score;


///struct para uma lista ligada que nos permite armazenar o ranking dos jogadores
typedef struct Ranking {
    Score jogador;
    LRanking prox;
} Ranking;



///struct que guarda o jogador e a grelha principal de jogo para o undo
struct Node {
    VALOR UndoJogador;
    VALOR UndoGrelha[8][8];
    struct Node *prox;
};

typedef struct Node *Undo;


///struct principal do programa guarda todas as informaçoes necessarias para o bom funcionamento do mesmo
typedef struct estado {


    int matrizValores[8][8];
    int dificuldade;             // dificuldade do bot. 0-> manual , 1-> facil , 2-> medio , 3-> dificil , 4-> competetivo
    char icon[5];

    VALOR peca;               // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char MatrizAjuda[8][8];
    Undo undoEstado;

    LRanking tabela;
    char nomeTemporario[256];

    int jogadas;
    char modo;               // modo em que se está a jogar! 0-> manual, 1-> contra computador


    VALOR MatrizAjudaBot[8][8];

    int Code;


} ESTADO;


///struct simples de coordenadas
typedef struct Posicao {
    int x, y;
} Posicao;






#endif //PROJ_STRUCTS_H
