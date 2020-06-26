#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//1
void exerc1 () {
	int x,y;
	scanf ("%i",&x);
y=x;
	while ((x>0) && (y>0)) {
		if (x>y) scanf ("%i",&y);
		   else scanf ("%i",&x);

	}
	if (x>y) printf("%i\n",x);
	   else printf("%i\n",y);
}

//1o1 <- melhor do que a de cima
void exerc1o1 () {
	int x,y=0;
	scanf ("%d",&x);
	while (x!=0) {
		if (x>y) y=x;
		else scanf ("%d",&x);
	}
	printf ("Maior numero da sequencia : %d\n",y);
}

//2
void exerc2 () {
	int x=0,y,k=0;
	double l;
	scanf ("%d",&y);
	k=y;
	for(; y!=0; x++) { 
		scanf ("%d",&y);
		k+=y;
	}
	l = k / x;
	printf("%f\n",l);
}


//2 
void ex22 () {
	float res=0;
	int i,divisor;

	for (divisor = 1 ; i!=0 ; divisor++) {
		scanf("%d",&i);
		res+=i;
	}

	printf("%f",(double) res/divisor);
		
}

void ex2 () {
    int soma = 0;
    int n=0 , x;

    scanf("%d",&x);
    if (x==0) n=1;

    while(x!=0) {
        soma += x;
        if (x!=0) n++;
        scanf("%d",&x);
    }

    printf ("%f <-\n", (double) soma/n);
}

//3
void ex3()
{
	int read, snd, fst;
	scanf("%d", &read);
	if (read < 0) snd=fst=read;
		else {snd=0;fst=0;}
	while (read)
	{
		if (read > fst)
		{
			snd = fst;
			fst = read;
		}
		else
			if (read > snd && read != fst)
				snd = read;
		scanf("%d", &read);
	}


		printf("%d\n", snd);

	
}




//4
 

//5
int trailingZ (unsigned int n) {
	int res=0;

	while (n%2==0) {
		res++;
		n/=2;

	}
	return res;

}

//6
int qDig (unsigned int n) {
	int k=1;
	while (n>10) {
		n=n/10; k++;
	}
	return k;
}

//7
char *mystrcat (char s1[], char s2[]) {
	int i,j;
	for (i=0; s1[i] != '\0' ; i++)
		;
		for (j=0 ; s2[j] != '\0' ; j++,i++) {
			s1[i]=s2[j];
		}
		s1[i] = '\0';

	return s1;

}

//8
char *mystrcpy (char *dest, char source[]) {
	int i;
	char *saved = dest;

	for (i=0 ; source[i] != '\0' ; i++) {

		*dest = source[i];

		dest++;

		}

		*dest='\0';

	return saved;
}


//9
int mystrcmp (char s1[],char s2[]) {
	int i;

	for (i=0 ; (s1[i] == s2[i] && s1[i] != '\0') ; i++)
		;
	
	return (s1[i]-s2[i]);

}

//10
char *mystrstr (char s1[],char s2[]) {
	int i,j,k,encontrado=0;

	if(*s1 && *s2) return 1;

	for (i=0 ; s1[i] && !encontrado ; i++) {
		encontrado = 1;
			for (j=i ,k=0; s1[j] && s2[k] && encontrado ; j++,k++) {
				if (s1[j]!=s2[k]) encontrado = 0;
			}
	}
	return (!s2[k] && encontrado ? s1+i-1 : NULL);
}


//11
void strrev (char s[]) {
	int i,j;
	char k;

	for (i=0 ; s[i]!='\0' ; i++)
		;
i--;

	for (j=0 ; j < i  ; j++,i--) {
		k=s[i];
		s[i]=s[j];
		s[j]=k;

    }
}

//12
int isVogal (char c) {
	int i,res=0;
	char vogal[10] = "AEIOUaeiou";

	for (i=0 ; i <10 ; i++) {
		if (c==vogal[i]) res=1;
	}
	return res;
}

void strnoV (char s[]) {
	int i , j=0;

	for (i=0 ; s[i] ; i++) {
		if (isVogal(s[i])==0) {
			s[j] = s[i];
			j++;
		} 
	}
	s[j]='\0';
}


//13
 void truncW (char t[], int n) {
	 int i,j=0,k,z;

	for (i=0 ; t[i] ; i++) {
			if (isspace(t[i])) j=0;
    
            else if (j<n) j++;
            
			else {

					for (k=i ; t[k] ; k++) {
							t[k]=t[k+1];
					}
					   
				i--;
			}
 		}
 }

void truncW(char t[], int n) {
	int i,j;

	for(i=j=0 ; t[i] ; i++) {

		if (isspace(t[i])) {t[j] = t[i] ; j=0;}

		else if (j<n) {
			t[j] = t[i];
			j++
		}

	}

	t[j] = '\0';
}



//14
char charMaisfreq (char s[]) {
	int i,guarda [256] = {0},res=0,p=0;

	for (i=0; s[i] ; i++) {
		guarda[s[i]]++;
		
		if (guarda[s[i]] > res) {
		    res = guarda[s[i]];
		    p=s[i];
	    }

	}
    return p;

}


//15
int iguaisConsecutivos (char s[]) {
	int i=0,res=0,k=1;

	for (; s[i] ; i++) {
    
		if (s[i]==s[i+1]) k++;
			else if (k > res) {res=k; k=1;}

	}
return res;

}

//16
int antes (char s[],int a,int b) {
    
    while (a<b && s[a]!=s[b]) {
        a++;
        
    }
    return ((s[a]==s[b])&&(a!=b))?1:0;
}


int difConsecutivos (char s[]) {
	int i=0,j=0,res=0;

	while (s[i]) {
	    j=i;
		while (s[j] && !antes (s,i,j)) {
            j++;
	}
            if (j-i > res) res=j-i;
            i++;

	
	}

	return res;
}

//17
int maiorPrefixo (char s1 [], char s2 []) {
	int i=0;

		for (; s1[i] && s2[i] && (s1[i]==s2[i]) ; i++) 
        ;
		return i;
}

//18
int maiorSufixo (char s1 [], char s2 []) {
	int i=0,res=0,j=0;

	i=strlen(s1);
	j=strlen(s2);

	for (; s1[i]==s2[j] ; i--,j--) {
			 res++;
		}
		
	return res-1;
}

//19
int sufPref (char s1[], char s2[]) {
	int i=0,res=0;
	char *s = s2;

	for ( ; *s1 ; s1++) {
			if (*s1==*s2) {s2++;res++;}
			
			else {res=0;s2=s;}
}

	return res;

}

//20
int contaPal (char s[]) {
	int i=0,res=0;

	for ( ; *s ; s++) {
	  if ((!isspace(s[i]) && isspace(s[i+1]) )|| (!isspace(s[i]) && s[i+1]==0))
		res++; 
	}
	return res;	

}

//21
int isVogals (char c) {
	char vogais[] = "aeiouAEIOU";
	int i=0;

	for (; vogais[i] ; i++) {
		if (vogais[i]==c) return 1; 
	}
	return 0;
}


int contaVogais (char s[]) {
	int i=0,res=0;

	for ( ; s[i] ; i++)
		if (isVogal(s[i])) {
			res++;
			
		}
	return res;
}

//22
int existe (char c, char *s) {

	for ( ; *s ; s++) {
		if (c == *s) return 1;
	}
	return 0;

}

int contida (char a[], char b[]) {

	for ( ; *a ; a++) {
		if (existe (*a,b)) 
		;
			else return 0;
		
}
return 1;

}

//23
int palindroma (char s[]) {
	int i=0,j=0;

	for (; s[i] ; i++)
	;
	i--;
	for ( ; s[j] ;j++,i--) {
			if (s[j] != s[i]) return 0;
}

	return 1;
}

//24
int remRep (char x[]) {
	int i=0,k=0;

	for ( ; x[i] ; i++) {
		k=i;
		if (x[i]==x[i+1]) {
			for ( ; x[i] ;i++) {
				x[i]=x[i+1];
			}
			i=k-1;
		}
		
	}
	return strlen(x);
}

//25
int limpaEspacos (char t[]) {
	int i=0,k=0;

		for ( ; t[i] ; i++) {
			k=i;

			if (t[i]==' ' && t[i+1]==' ') {

					for ( ; t[i] ; i++) {
						t[i]=t[i+1];
					}
					i=k-1;
			}
		}
		return strlen(t);
}

//26
void insere (int v[], int N, int x) {

		for ( ; N>0 && x < v[N-1] ; N--) {
			v[N]=v[N-1];
}

		v[N]=x;

}

void merge (int r [], int a[], int b[], int na, int nb){
       int i,j=0,k=0;
       
       for (i=0 ; i<na+nb ; i++) {
           
           if (j < na && a[j] < b[k]) {
               r[i] = a[j];
               j++;
           }
           
           else  {
               r[i] = b[k];
               k++;
           }
       }

       for (i=0 ; i<12 ; i++) {
           printf("%d\n",r[i]);
       }
   }


//27
void merge2 (int r [], int a[], int b[], int na, int nb) {
	int i=0,j;

	for ( ; i<na ; i++) {
		r[i]=a[i];
}

	for ( j=0; i<na+nb ; j++,i++)
		insere(r,i,b[j]);

}

//28
int crescente (int a[], int i, int j) {
	int r=1;
    
	for (; i<j ; j--) {
		if (a[j]>=a[j-1])
		;
		else r=0;
	}

return r;
}

//29
int retiraNeg (int v[], int N) {
	int res=0,i=0,j;

	for ( ; i<N ; i++) {
		if (v[i] < 0) {

			for (j=i ; j<N ; j++) {
				v[j]=v[j+1];
		}
			N--;
			i--;
			
		}
		else res++;
	}
	return res;
}

//30
int menosFreq (int v[], int N) {
	int i=0,contador=1,menor=1,res=v[0];

	for ( ; i<N && v[i]==v[i+1] ; i++) {
		contador++;
	}
	i++;

	for ( ; i<N ; i++) {
		if (v[i]==v[i+1])
		menor++;

		else {
			if (contador > menor) {
				contador = menor ;
				res=v[i];
			}
			menor=1;
		}
	}
return res;
}

//31
int maisFreq (int v[], int N) {
	int i=0,contador=1,maior=1,res=v[0];

	for ( ; i<N && v[i]==v[i+1] ; i++) {
		contador++;
	}
	i++;

	for ( ; i<N ; i++) {
		if (v[i]==v[i+1])
		maior++;

		else {
			if (contador < maior) {
				contador = maior ;
				res=v[i];
			}
			maior=1;
		}
	}
return res;
}

//32
int maxCresc (int v[], int N) {
	int i=0,melhor=1,t=1;

	for ( ; i<N && v[i]<=v[i+1] ; i++) {
		 melhor++;
	}
	i++;

	for ( ; i<N ; i++) {
		if (v[i]<=v[i+1]) t++;

		else { 
				if (t > melhor) melhor = t;
		
		t=1;
	   }
	}
return melhor;
		
}

//33
int elimRep (int v[], int n) {
	int i=0,j,k;

	for ( ; i<n ; i++) {
		j=i+1;
		for ( ; j<n ; j++) {
		    
			if (v[i]==v[j]) {
			    
				for (k=j; k<n ; k++) {
					v[k]=v[k+1];
				}
				n--;
				j--;

			}
		}
	}

		return n;
}

//35
int comunsOrd (int a[], int na, int b[], int nb) {
	int i=0,j=0,res=0;

	for ( ; i<na && j<nb ; i++,j++) {

		if (a[i]==b[j]) {
			res++;
		}

		else if (a[i] < b [j]) j--;
		    else i--;

	}

	return res;
}

//36
   int comuns (int a[], int na, int b[], int nb){
    int res=0,j=0,i=0,encontrado=0;
    
    while (i<na) {
        j=0;
        encontrado = 0;
        
        while (j<nb && !encontrado) {
            if (a[i]==b[j]) {
                res++;
                encontrado=1;
            }
            j++;
        }
        i++;
    }
    return res;
   }

//37
int minInd (int v[], int n) {
	int i,acumulador=0,menor=v[0];

	for (i=1 ; i<n ; i++)
		if (v[i] < menor) {
			acumulador = i;
			menor=v[i];
		}

return acumulador;
}

//38
void somasAc (int v[], int Ac [], int N) {
	int i=0,soma=0;

	for ( ; i<N ; i++) {
	soma+=v[i];
	Ac[i]=soma;
	}

}

//39
int triSup (int N, float m [N][N]) {
	int i,j,res=1;

	for (i=0 ; i<N && res==1; i++) {

		for (j=0; j<N && res==1; j++) {

			if (j-i<0) {

				if (m[i][j]!=0) res = 0;

			}
		}
	}
	return res;
}

//40
void transposta (int N, float m [N][N]) {
	int i,j,acumulador;

	for (i=0 ; i<N ; i++) {

		for (j=0 ; j<N ; j++) {

			if (j-i>0) {
			acumulador = m[i][j];
			m[i][j]=m[j][i];
			m[j][i]=acumulador;
			}

		}

	}
}

//41
void addTo (int N, int M, int a [N][M], int b[N][M]) {
	int i,j;

	for (i=0 ; i<N ; i++) {

		for (j=0 ; j<M ; j++) {

			a[i][j]+=b[i][j];
		}
	}
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
	int i;

	for (i=0 ; i<N ; i++)
		r[i] = v1[i] | v2[i];

		return 0;
	
} 

//43
int intersectSet (int N, int v1[N], int v2[N],int r[N]) {
	int i;

	for (i=0 ; i<N ; i++)
		r[i] = v1[i] & v2[i];

		return 0;
}

//44
int min (int x,int y) {

	return (x>y)?y:x;
}

int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
	int i;

	for (i=0 ; i<N ; i++) {
		r[i]=min (v1[i],v2[i]);
	}
	return i;
}

//45
int max (int x,int y) {

	return (x>y)?x:y;
}

int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
	int i;

	for (i=0 ; i<N ; i++) {
		r[i]= max (v1[i],v2[i]);
	}
	return i;
}



//46
int cardinalMSet (int N, int v[N]) {
	int i,soma=0;

	for (i=0 ; i<N ; i++)
	soma += v[i];

	return soma;
}
//47
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
	int i;

	for (i=0 ; i<N ;i++) {

		switch (mov[i]) {

			case Norte :
				inicial.y++;
				break;
			case Sul :
				inicial.y--;
				break;
			case Oeste :
			 	inicial.x--;
				 break;
			case Este :
				inicial.x++;
				break;
    	}
	    
	}

	return inicial;


}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
	int i;

	for (i=0 ; inicial.x != final.x || inicial.y != final.y ; i++) {
		if (i==N) return -1;

		if (inicial.x < final.x) {mov[i]=Este;inicial.x++;}
		else if (inicial.x > final.x) {mov[i]=Oeste;inicial.x--;}
		else if (inicial.y < final.y) {mov[i]=Norte;inicial.y++;}
		else if (inicial.y > final.y) {mov[i]=Sul;inicial.y--;}
        
        
	}
	return i;

}

//49
int maiscentral (Posicao pos[], int N) {
	int i,k=0;
	float menor,t;

	menor = abs(pos[0].x) + abs(pos[0].y);

	for (i=1 ; i<N ; i++) {
		t = abs(pos[i].x) + abs(pos[i].y);

		if (t<menor) {
			menor = t;
			k=i;
		}
	}

	return k;

}

//50
int vizinhos (Posicao p, Posicao pos[], int N) {
	int i,res=0;

	for (i=0 ; i<N ; i++) {

		if ((pos[i].x == (p.x)-1 && pos[i].y == p.y) || (pos[i].x == (p.x)+1 && pos[i].y == p.y) || (pos[i].y == (p.y)-1 && pos[i].x ==p.x) || (pos[i].y == (p.y)+1 && pos[i].x ==p.x))
		{
		res++;
		}
	}
	return res;
}




int main () {
	int a[] = { 0,1,2,3,4,5 };
    int r[12];

	float c[3][3] = {	{1, 3, 0}, 
										{0, 5, 9},
										{0, 2, 9}
									};

    merge(r,a,a,6,6);
	//ex2 ();
	//exerc1;
	//exerc1o1 ();
	//exerc2 ();
	//exerc3 ();
    //bitsUm(100);
	//mystrcat (a,b);
	//primo (605);
	//mystrcpy(a,b);
	//strnoV (b);
	//charMaisfreq (b);
	//difConsecutivos(b);
	//maiorSufixo(a,b);
	//sufPref(a,b);
	//palindorome (b);
	//insere (a,4,3);
	//maxCresc(a,20);
	//elimRep(a,20);
	//minInd(a,20);
	//triSup(3,c);
	return 0;
}

/*numero primo
int primo (int n) {
	int z=n-1;
	while (z!=1) {
		if (n%z==0) return 1;
			else z--;
	}
	printf("0\n");
	return 0;
}
*/









