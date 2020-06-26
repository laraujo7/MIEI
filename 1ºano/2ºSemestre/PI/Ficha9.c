#include <stdio.h>
#include <string.h>

typedef struct abin {
int valor;
struct abin *esq,
*dir;
} *ABin;


//                                                     17
/*                                                   /    \
inorder - 5,7,13,15,17,22,34                        13     22
preorder - 17,13,7,5,15,22,34                      / \       \    
posorder - 5,7,15,13,34,22,17                     7   15      34
//                                               /
//                                              5

preoder serve principalmente para dar load a um ficheiro (mais facilmente).

posorder serve principalmente para converter expressoes matematicas.

Exemplo :
5 + 3 * 2

Esta expressao em posorder ficaria : 5 3 2 * +

E com uma expressao e uma stack, calculamos a expressao :

//                        | 11|
 |   |        | 6 |       | / |
 | 2 |  -->   | / |  -->  | / |
 | 3 |  3*2   | / |  5+6  | / |
 |_5_|        |_5_|       |_/_|

 */
  
void inorder (abin a) {
    
    if (a) {
        inorder(a->esq);
        printf("%d ",a->valor);
        inorder(a->dir);
    }

    printf("/n");

}

void preorder (abin a) {

    if (a) {
        printf(a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }

}

int existeElem (abin a, int x) {
    int res = 0;

    if (a) {

    if (x == a->valor) res = 1;

    else if (x < a-> valor) res = existeElem (a->esq,x);

    else (x > a->valor) res = existeElem (a->dir,x);

    }

    return res;

}

ABin insABin (ABin a, int x) {
    

    if (a) {
        
        if (x < a->valor) a->esq = insABin (a->esq,x);

        else a->dir = insABin(a->dir,x);

    }

    else {
        a = (ABin) malloc(sizeof (struct NodoABin));
        a->valor = x;
        a->esq = NULL;
        a->dir = NULL;
    }

    return a;

}

int efolha (ABin a) {
    return !a->esq && !a->dir;
}

ABin maxABin (ABin a) {

    while (a && a->dir) {
        a = a->dir;
    }

    return a;

}

