#include <stdio.h>


typedef struct sList *Lint;

typedef struct sList {
    int valor;
    Lint prox;
} Node;

//1a
//int main () {

    Lint a = malloc (sizeof (Node));
    Lint b = malloc (sizeof (Node));
    Lint c = malloc (sizeof (Node));

    a->valor = 10;
    a->prox = b;

    b->valor = 5;
    b->prox = c;

    c->valor = 15;
    c->prox = NULL;

    showList(a);

//

    Nodo c = {15,NULL}, b = {5,&c} , a = {10,&b};

    Lint l = &a;

    showList(l);

}


//exercicio

void showList (LInt l) {

    while (l) {
        printf ("%d\n",l->valor);
        l=l->prox;
    }
}

//exercicio recursivo

void showList (LInt l) {

    if (l != NULL) {
        printf ("%d",l->valor);
        showList (l->prox);
    }
}

//1b

Lint cons (LInt l, int x) {

    Lint res;

    res = malloc (sizeof (Node));

    res->valor = x;
    res->prox = l;

    return res;


//1c

Lint tail (LInt l) {
    
    Lint res = l->prox;

    free(l);

    return res;
}

//1d
Lint init (LInt l) {
    Lint aux;
    Lint ant;

    ant = l;
    aux = l;

    while (aux->prox) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;

    free(aux);
    
    return l;
}

//1e
Lint snoc (Lint l,int x) {
    Lint a;
    Lint aux = l;

    a = malloc (sizeof (Node));
    a->prox = NULL;

    if (!aux) l=a;
    else {
        
        while (aux->prox) {
        aux = aux->prox;
    }

    aux->prox = a;
    }

    return l;
}

//1f
Lint concat (LInt a, LInt b) {
    Lint aux = a;

     if (a==NULL) aux = b;
        else {
            while (aux->prox) {
                aux=aux->prox;
            }
            aux->prox = b;
        }
            return a;
        

}


//2a

typedef struct Turma *LTurma;

typedef struct Turma {
    Aluno aluno;
    LTurma prox;
} Turma;

typedef struct Aluno {
    char nome[60];
    char numero[7];

} Aluno;


//exercicio

void showTurma (Lturma t1) {

    while (t1) {
        printf("%s %s %f\n",t1->Aluno.nome,t1->Aluno.numero,t1->Aluno.nota);
        t1 = t1->prox;
    }
}



int main () {
    Aluno a1 = {"Joao","A22222",15.5};
    Aluno a2 = {"Ana", "A32632",14.3};
    Aluno a3 = {"Filipe","A44751",12.7};

    Lturma t1;

    t1 = cons (cons (cons (t1,a3),a2),a1);

    showTurma(t1);
}