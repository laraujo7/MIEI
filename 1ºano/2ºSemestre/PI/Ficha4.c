#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*
int eMaiuscula (char)

return (c>='A' && c<='Z')?1
                         :0;
*/



//1
int minusculas (char s[]) {
    int i=0,res=0;

    for (; s[i] ; i++) {

        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
            res++;
        }
    }

    return res;

}

//2
int contalinhas (char s[]) {
    int i=0,res=0;

    for (; s[i] ; i++) {

        if (s[i]=='\n') res++;
    }
    return res;
}

//3
int contaPal (char s[]) {
    int i=0,res=0;

    for (; s[i] ; i++) {

        if ((!isspace(s[i]) && isspace(s[i+1]) ) || (!isspace(s[i]) && !s[i+1] ))
        res++;
        
    }
    return res;
}

//4
int procura (char *p, char *ps[], int N) {
    int i=0;

    for ( ; i<N ; i++,ps++) {
        if (strcmp (p,*ps)==0) {i+=N;}
}
       return i-N;
}

//5
int procura2 (char *p, char *ps[],int N) {
    int i=0,found=-1;

    for ( ; i<N && (found <= 0 ) ; i++) {
        found = strcmp (p,ps[i]);
    }

    return (found==0?i:-1);
}

//7
int zeros (int N, int M, int m [N][M]) {
    int i=0,j=0,res=0;

    for (; i<N ; i++) {
        j=0;
        for (; j<M ; j++) {
            if (m[i][j] == 0) res++;
        }
    }
    return res;
}

//8
void identidade (int N, int m[N][N]) {
    int i=0,j;

    for (; i<N ; i++) {

        j=0;

        for (; j<N ; j++) {

            if (i==j) m[i][j]=1;
                else m[i][j]=0;

        }
    }
}

//9
void multV (int N, float t[N][N], float v[N], float r[N]) {
    int i=0,j;

    for ( ; i<N ; i++) {
        j=0;
        for (; j<N ; j++) {
            r[j] += (t[i][j]*v[j]);

        }
    }

}








int main () {
    char b[] = "abba";
    char *p[] = {"ola","abb","abba"};
    int a[4][4] = {
                         {10, 11, 12, 13},
                         {14, 15, 16, 17},
                         {2, 0 , 0, 0},
                         {20, 3 , 4 ,0}
                                           };
    //minusculas (b);
    //contalinhas (b);
    //contaPal(b);
    //contaPal(b);
    //zeros(3,10,a);
    //identidade(10,a);
    //multV(4,a,b,c);
    procura (b,p,3);
    return 0;
}