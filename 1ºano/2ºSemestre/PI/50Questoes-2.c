#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

//1
int length (LInt l) {
    int res=0;

    while (l) {
        res++;
        l=l->prox;
    } 

    return res;
}

//2
void freeL (LInt l)  {
    LInt t;

    while (l) {
        t = l->prox;
        free(l);
        l = t;
    }
}

//3
void imprimeL (LInt l) {

    while (l) {
        printf("%d\n",l->valor);
        l=l->prox;
    }
}

//4
LInt reverseL (LInt l) {
    LInt t = NULL, x;

    while (l) {
        x = l;
        l = l->prox;
        x->prox = t;
        t = x;
    }
    return t;
}

//5
void insertOrd (LInt *l, int x) {
    LInt t,aux,ant;

    t = malloc (sizeof (struct lligada));
    t->valor = x;

    aux = l ; 
    ant = NULL;

    while (aux && aux->valor < x) {
        ant = aux;
        aux = aux->prox;
    }

    t->prox = aux;

    if (ant != NULL) ant->prox = t;
    else l = t;

    return l;

}

//6
int removeOneOrd (LInt *l, int x) {
    LInt aux = *l;
    LInt ant = NULL;
    int res = 1;

    while (aux && aux->valor != x) {
        
        ant = aux;
        aux = aux->prox;
        
    }

    if (ant == NULL && aux) {
        *l = (*l)->prox;
        res = 0;
    }
    else if (aux) {
        ant->prox = aux->prox;
        res=0;
    }

    return res;
}

//7
void merge (LInt *r, LInt a, LInt b) {


        while (a && b) {

            if (a->valor < b->valor) {
                *r = a;
                a = a->prox;
                }

            else {
                *r = b;
                b = b->prox;
            }

            r = &(*r)->prox;

        }

            if (!a) *r = b;
            else if (!b) *r = a;

}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {

    while (l) {
        if (l->valor < x) {
            
        *mx = l;
        mx = &(*mx)->prox;
        
        }
        
        else {
            *Mx = l;
            Mx = &(*Mx)->prox;
        }
        
        l = l->prox;
    }
    
    *mx = 0;
    *Mx = 0;

}

//9
LInt parteAmeio (LInt *l) {
    int x = 0;
    LInt aux = *l;
    LInt res = 0;

        while (aux) {
        x++;
        aux = aux->prox;
    } 
    

    for (x /= 2 ; x > 0 ; x--) {
        
        if (!res) aux = res = *l;
        else aux = aux->prox = *l;
        
        *l = (*l)->prox;
        aux->prox = 0;
    }


    return (res);
}

//10
int removeAll (LInt *l, int x) {
    LInt aux = *l;
    int res = 0;

    if (*l) {

    for (; aux ; aux = aux->prox ) {

        if (aux->valor != x) {

            *l = aux;
            l = &(*l)->prox;

            }
            
        else res++;

        }

    }
    
    *l = 0;

    return res;
}

//11
void removeDups (LInt *l) {

        for ( ; *l ; l = &(*l)->prox) {
        
        if ((*l)->prox) removeAll(&(*l)->prox,(*l)->valor);
    }

}

//12
int removeMaiorL (LInt *l) {
    LInt ant = 0;
    LInt aux = *l;
    int maior;


        maior = (*l)->valor;
        aux = aux->prox;

        for (; aux ; aux = aux->prox) {
            if (maior < aux->valor) maior = aux->valor;
        }

        for (; (*l)->valor != maior ; ant = *l , l = &(*l)->prox) 
        ;

        if (!ant) *l = (*l)->prox;
        
        else ant->prox = (*l)->prox;

    return maior;
} 

//13
void init (LInt *l) {

    while ((*l)->prox) {
        l = &(*l)->prox;
    }
    
    free(*l);
    *l = 0;
    
} 

//14
void appendL (LInt *l, int x) {
    LInt a;

    a = malloc(sizeof(struct lligada));
    a->valor = x;
    a->prox = 0;

    for ( ; *l ; l = &(*l)->prox);

    *l = a;

}

//15
void concatL (LInt *a, LInt b) {

    for (; *a ; a = &(*a)->prox) ;

    *a = b;

}

//16
LInt cloneL (LInt l) {
    LInt a = NULL;
    LInt res = NULL;

    if (l) {

        res = malloc(sizeof(struct lligada));
        res->valor = l->valor;
        res->prox = a;

        l = l->prox;

        while (l) {
        
        a = malloc(sizeof(struct lligada));
        a->valor = l->valor;
        a->prox = NULL;
        a = a->pox;

        l = l->prox;

        }

    a = NULL;

    }

    return res;

}


//17
LInt cloneRev (LInt l) {
    LInt novo;
    LInt a;

    if (l) {

        a = malloc(sizeof(struct lligada));
        a->valor = l->valor;
        a->prox = NULL;

        novo = a;
        l = l->prox;

    while (l) {

        novo = malloc(sizeof(struct lligada));
        novo->valor = l->valor;
        novo->prox = a;

        a = novo;
        l = l->prox;

        }

    }

    return novo;

}

//18
int maximo (LInt l) {
    int res = 0;

    while (l) {
        if (res == 0) res = l->valor;

        else {

            if (l->valor > res) res = l->valor;
            
        }

    l = l->prox;

    }

    return res;
}



//19
int take (int n, LInt *l){
    int res = n;
    
    while (n>0 && *l) {
        
        l = &(*l)->prox;
        n--;
        
    }
    
    if (n==0) *l = NULL;
    
    return res-n;
    
    
}


//20
int drop (int n, LInt *l) {
    int res = n;

    while (n>0 && *l) {

        *l = (*l)->prox;
        n--;

    }

    return res-n;

}

//21
LInt NForward (LInt l, int N) {

    while (N != 0) {
        l = l->prox;
        N--;
    }

    return l;
}

//22
int listToArray (LInt l, int v[], int N) {
    int i;

    for (i=0; l && N>0 ; i++) {

        v[i] = l->valor;
        l = l->prox;
        N--;

    }

    return i;

}

//23
LInt arrayToList (int v[], int N) {
    LInt res = NULL; 
    

    if (N>0) {
    
        res = malloc (sizeof(struct lligada));
        res->valor = v[0];
    
        res->prox = (arrayToList(v+1,N-1));

    }

    return res;

}

//24
LInt somasAcL (LInt l) {
    LInt res = NULL,a;
    int soma = 0;

    if (l) {
        res = malloc(sizeof(struct lligada));
        a = res;

    while (l) {

        a->valor = soma += l->valor; 

        if(l->prox) {
            a->prox = malloc(sizeof(struct lligada));
            a = a->prox;
            }

        l = l->prox;

        }
        
        a -> prox = NULL;

    }

    return res;

}

//25
void remreps (LInt l) {
    LInt next;

    if (l) {

        next = l->prox;

        while (next) {

        if (l->valor != next->valor) {
            
            l->prox = next;
            l = l->prox;
           
    }

        next = next->prox; 

        }
        
        l->prox = NULL;

    }

}

//26
LInt rotateL (LInt l) {
    LInt res,save;
    int flag=0;

    if (l && l->prox) {

        save = l;
        l = l->prox;
        res = l;

        while (res->prox) {
            
            res = res->prox;
        }

        res->prox = save;
        save->prox = NULL;

    }

    return l;

}

//27
LInt parte (LInt l) {
    LInt novo = NULL , a;

    if (l && l->prox) {

        novo = l->prox;

        while (l && l->prox) {

            a = l->prox;
            l->prox = a->prox;
            l = a;

        }

    }

    return novo;

}

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

//28
int altura (ABin a) {
    int esq,dir,alt = 0;

    if (a) {
        
        esq = 1+altura(a->esq);
        dir = 1+altura(a->dir);
        
        if (esq > dir) alt = esq;
        else alt = dir;
        
    }

    return alt;
    
}

//29
ABin cloneAB (ABin a) {
    ABin novo;

    if (a) {

        novo = malloc(sizeof(struct nodo));
        novo->valor = a->valor;

        novo->esq = cloneAB(a->esq);
        novo->dir = cloneAB(a->dir);


    }

    else return NULL;

    return novo;

}

//30
void mirror (ABin *a) {
    ABin t;

    if (*a) {
        t = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = t;

        mirror(&(*a)->dir);
        mirror(&(*a)->esq);

    }

}

//31
void inorder (ABin a, LInt *l) {

    if (a) {

        inorder(a->esq,l);

        while (*l) {
            l = &(*l)->prox;
        }

        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;

        inorder(a->dir,l);

    }

    else *l = NULL;

}

//32
void preorder (ABin a, LInt * l) {
    
    if(a) {

    *l = malloc(sizeof(struct lligada));
    (*l)->valor = a->valor;
    l = &(*l)->prox;

    preorder(a->esq,l);
    while (*l) {
        l = &(*l)->prox;
    }
    preorder(a->dir,l);

    }
    
    else *l = NULL;

}

//33
void posorder (ABin a, LInt *l) {

    if (a) {
        
        posorder(a->esq,l);
        
        while (*l) {
            l = &(*l)->prox;
        }
        
        posorder(a->dir,l);
        
        while (*l) {
            l = &(*l)->prox;
        }
        
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;

        
    }

    else *l = NULL;

}

//34
int depth (ABin a, int x) {
    int res = -1,esq,dir;

    if (a) {

        if (x == a->valor) res = 1;

        else {

            esq = depth(a->esq,x);
            dir = depth(a->dir,x);

            if (esq < 0 && dir < 0) res = -1;
            else if (esq < 0) res = 1+dir;
            else if (dir < 0) res = 1+esq;

            else if (esq < dir) res = 1+esq;
            else res = 1+dir;

        }

    }

    return res;

}

//35
int freeAB (ABin a) {
    int res = 0;

    if (a) {
        
        res = 1;
        res += freeAB(a->dir);
        res += freeAB(a->esq);
        free(a);
    
    }

    return res;

}

//36
int pruneAB (ABin *a, int l) {
    int res = 0;

    if (*a) {

    if (l>0) {

        res += pruneAB(&(*a)->esq,l-1);
        res += pruneAB(&(*a)->dir,l-1);
    
        }

    else {

        res = 1;

        res += pruneAB(&(*a)->esq,l-1);
        res += pruneAB(&(*a)->dir,l-1);
        free(*a);
        *a = NULL;

        }

    }

    return res;

}

//37
int iguaisAB (ABin a, ABin b) {
    int res = 1;

    if (a && b) {

        if (a->valor != b->valor) res = 0;

        if (res == 1) {

            res = iguaisAB(a->esq,b->esq);

            if (res == 1) res = iguaisAB(a->dir,b->dir);

        }

    }

    else if (a || b) res = 0;

    return res;

}

//38
LInt nivelL (ABin a, int n) {
    LInt b,res = NULL;

    if (a) {
        

        if (n==1) {

            res = malloc(sizeof(struct lligada));
            res->valor = a->valor;
            res->prox = NULL;

        }

        else {

            res = b = nivelL(a->esq,n-1);
            
            while (b && b->prox) {
            b = b->prox;
            }            
            
            if (b) b->prox = nivelL(a->dir,n-1);
            else res = nivelL(a->dir,n-1);
        }

    }

    return res;

}

//39
int nivelV (ABin a, int n, int v[]) {
    int res = 0;

    if (a) {

        if (n==1) {
            v[res] = a->valor;
            res++;
        }

        else {
            
            res += nivelV(a->esq,n-1,v);
            res += nivelV(a->dir,n-1,v+res);

            }

        }

    return res;
}

//40
int dumpAbin (ABin a, int v[], int N) {
    int res = 0;

    if (a && N>0) {
        
        res += dumpAbin(a->esq,v,N-1);

        v[res++] = a->valor;
        N -= res;
        
        res += dumpAbin(a->dir,v+res,N);
        
        
    }

    return res;
}

//41
ABin somasAcA (ABin a) {
    ABin res = NULL,aux;
    int soma = 0;

    if (a) {

        res = malloc(sizeof(struct nodo));
        res->esq = somasAcA(a->esq);
        res->dir = somasAcA(a->dir);
        res->valor = a->valor;

        if (res->esq) res->valor += res->esq->valor;
        

        if (res->dir) res->valor += res->dir->valor;

    }

    return res;
}

//42
int contaFolhas (ABin a) {
    int res = 0;

    if (a) {

        if (a->dir == NULL && a->esq == NULL) res = 1;

        else if (a->dir == NULL) res += contaFolhas(a->esq);

        else if (a->esq == NULL) res += contaFolhas(a->dir);

        else {
            res += contaFolhas(a->esq);
            res += contaFolhas(a->dir);
        }

    }

    return res;

}

//43
ABin cloneMirror (ABin a) {
    ABin res = NULL;

    if (a) {

        res = malloc(sizeof(struct nodo));
        res->valor = a->valor;
        
        res->esq = cloneMirror(a->dir);
        res->dir = cloneMirror(a->esq);

    }

    return res;

}

//44
int addOrd (ABin *a, int x) {
    ABin ant = NULL;
    int encontrado = 0;
    
    while (*a && encontrado == 0) {

        if (x == (*a)->valor) encontrado = 1;

        else if (x < (*a)->valor) a = &(*a)->esq;

        else a = &(*a)->dir;

    }

    if (encontrado == 0) {

        (*a) = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
    }

    return encontrado;
}

//45
int lookupAB (ABin a, int x) {
    int encontrado = 0;

    while (a && encontrado == 0) {

        if (a->valor == x) encontrado = 1;

        else if (a->valor > x) a = a->esq;

        else a = a->dir;

    }

    return encontrado;

}

//46
int depthOrd (ABin a, int x) {
    int encontrado = 0, res = 1;

    while (a && encontrado == 0) {

        if (a->valor == x) encontrado = 1;

        else if (a->valor > x) {

            a = a->esq;
            res++;

        }

        else {

            a = a->dir;
            res++;

        }


    }

    if (encontrado == 0) res = -1;

    return res;

}

//47
int maiorAB (ABin a) {

    for (; a->dir ; a = a->dir) 
    ;

    return a->valor;

}

//48
void removeMaiorA (ABin *a) {
    ABin ant = NULL;


    for (; (*a)->dir ; ant = *a , a = &(*a)->dir) 
    ;

    if (ant) {
        
        free(ant->dir);
        ant->dir = (*a)->esq;
        
    }
    
    else {
        
        ant = *a;
        *a = (*a)->esq;
        free(ant);
        
    }

}

//49
int quantosMaiores (ABin a, int x) {
    int res = 0;

    if (a) {

        if (a->valor > x) res++;
        
        res += quantosMaiores(a->esq,x);
        res += quantosMaiores(a->dir,x);
    
    }

    return res;

}

//50





int main () {

    return 0;
}