#include <stdlib.h>


#define MAX 100
typedef struct stack {
int sp;
int valores [MAX];
} STACK;

//1
void initStack (STACK *s) {
    *s.sp=0;
}

//2
int isEmpty (STACK *s) {
    return (*s.sp==0);
}

//3
int isFullS (STACK *s) {
    return (*s.sp == MAX-1);
}

int push (STACK *sm int *x) {
    if (!isFullS (s)) {
        *s.valores[*s.sp] = *x;
        *s.sp++;
        return 0;
    }
    else return 1;

}

//4
int isEmptyS (STACK *s) {
    return (*s.sp == 0);
}

int pop (STACK *s, int *x) {
    if (!isEmptyS(s)) {
        *x = *s.valores[*s.sp];
        *s.sp--;
        return 0;
    }
    else return 1;
}

//5
int top (STACK *s, int *x) {
    if (!isEmptyS(s)) {
        *x = *s.valores[*s.sp];
        return 0;
    }
    else return 1;
}


#define MAX 100
typedef struct queue {
int inicio, tamanho;
int valores [MAX];
} QUEUE;

//2.a
void initQueue (QUEUE *q) {
    *q.inicio = 0;
    *q.tamanho = 0;
}

//2.b
int isEmptyQ (QUEUE *q) {
    return (*q.tamanho==0);
}

int isFullQ (QUEUE *q) {
    return (*q.tamanho == MAX);
}

//2.c
int enqueue (QUEUE *q, int x) {
    int pos;
    
    if (!isFullQ (q)) {
        pos = (*q.inicio+*q.tamanho % MAX);
        *q.valores[pos] = x;
        *q.tamanho++;
        return 0;
    }
    else return 1;
}

//2.d
int dequeue (QUEUE *q, int *x) {

    if (!isEmptyQ(q)) {
        *x = *q.valores[ *q.inicio ];
        *q.inicio = (*q.inicio+1) % MAX;
        *q.tamanho--;
        return 0;
    }
    else return 1;
}

//2.e
int front (QUEUE *q, int *x) {
    
        if (!isEmptyQ(q)) {
        *x = *q.valores[ *q.inicio ];
        return 0;
    }
    else return 1;

}

//3.b
typedef struct queue2 {
    int size; // guarda o tamanho do array valores
    int inicio, tamanho;
    int *valores;
} QUEUE2;

void initQueue (QUEUE *q) {
    *q.size=100;
    *q.inicio=0;
    *q.tamanho=0;
    *q.valores=(int *) malloc (*q.size * sizeof(int))
}

int enequeue (QUEUE *q, int x) {
    int *aux;

    if (isFullQ(q)) {
        
        aux = *q.valores;
        *q.valores = (int *) malloc (*q.size * 2 + sizeof(int))
        copiaQueue(*q.valores,aux,*q.tamanho);
        *q.size += *q.size
        free(aux);
    }

    *q.valores[(*q.tamanho + *q.inicio) % *q.aumento] = x;
    *q.tamanho++;

    return 0;
}



//Exercicio (para casa)
void listQueue (QUEUE q1) {
    int i=0 ;

        while ()
    printf ("%d\n",q1.valores[q.inicio]);

}











int main () {

    QUEUE q1;

    //initQueue(&q1);

    listQueue(q1);








    /*
    int *val;
    STACK s1;

    initStack(&s1);

    for (int i=1 ; i<200 ; i+=2)
    push (&s1,i);

    while (s1.sp) {
        pop(&s1,val);
        printf("%d\n",*val);
    }
    */
}


