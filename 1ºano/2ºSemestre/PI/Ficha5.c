#include <stdio.h>

//1
void insere (int v[], int N, int x) {

    for ( ; N>=0 && x<v[N-1]; N--) {
        v[N]=v[N-1];
    }

    v[N] = x;
}

//2
void iSort (int v[], int N) {
    int i;

    for (i=1; (i<N); i++) {

    }

}

//3
int maxInd (int v[], int N) {
    int i,maximo = v[0], indice = 0;

    for (i=1 ; i<N ; i++) {
        if (v[i]>maximo) {
            maximo = v[i];
            indice = i;
        }
    }
    return indice;
}

//4
void swap (int v[], int i, int j) {
    int t;

    t=v[i];
    v[i]=v[j];
    v[j]=t;

}

void maxSort (int v[], int N) {
    int maximo;

    for ( ; N>0 ; N--) {

        maximo = maxInd(v,N);

        swap (v,maximo,N-1);
        
    }
}

//5
//void SmaxSort (int v[], int N) {

//}

//6
int bubble (int v[], int N,int flag) {
    int i;

    for (i=1;(i<N); i++) {

        if (v[i-1] > v[i]) {
        swap (v,i-1, i);
        flag=1;
        }
    }
    return flag;

}

//7
void bubbleSort (int v[], int N) { 
    int i=N,j;
    int flag=1;

    for (; N>0 && flag==1 ; N--) {
        flag=0;
        bubble(v,N,flag);
        
    }

    for (j=0 ; j<i ; j++) printf("%d ",v[j]);

    printf("\n");
}

//8




int main () {
    int a[4] = {2,4,1,5};

    bubbleSort (a,4);

    return 0;
}