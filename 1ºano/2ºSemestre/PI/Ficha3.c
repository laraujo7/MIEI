#include <stdio.h>


/*
1 a) 
	int x [15] = {1, 2, 3, 4, 5,6, 7, 8, 9,10,11,12,13,14,15};
	int *y, *z, i;



	y = x; z = x+3;    // o y passará a ser igual ao array x[15] na possição 0 
					   // o z passará a ser igual ao array x[15] na posição 2

	for (i=0; (i<5); i++) {

		printf ("%d %d %d\n",x[i], *y, *z);  // ira printar os elementos de x[15] da possiçao 0 ate a 4 do array
											 // o *y sera igual ao x[i]
											 // o *z ira printar os elementos de x[15] a começar na posiçao 3 do array ate a 11, a saltar de 2 em 2

		y= y+1; z = z+2;    
}
}


1 b)
	int main () {
		int i,j,*a,*b;
		
	i=3 ; j=5;			

	a=&i ; b=&j;		// a sera o indereço de i ; b sera o indereço de j
	i++;

	j = i + *b ;       //
	b = a;
	j = j + *b;			// j = (i + *a) + *b

	printf ("%d\n",j);

	return 0;
	}

*/

// 2 )
void swapM (int *x,int *y) {
	int t = *x;
		*x = *y;
		*y = t;

}

// 3 )
void swap (int v[],int i,int j) {
	int acum;

	acum = v[i];
	v[i] = v[j];
	v[j] = acum;
}

// 4 )
int soma (int v[],int N) {
	int x,soma=0;

	for (x=0 ; x<N ; x++) {
		soma += v[x];
	}
	return soma;
}
/*

int somaR (int v[],int N) {


	if (N==0) return 0;

	else return *v + somaR (v++,N-1);

}

*/



// 5)
int maximum (int v[],int N,int *m) {
	int i,maior = v[0];

	if (N>0) {

		for (i=1 ; i<N ; i++) {

			if (v[i] > maior) maior = v[i];

		}

		m = &maior;

		return 0;
	}
	else return 1;
}

// 6 )
void quadrados (int q[],int N) {
	int x;

	for (x=0 ; x<N ; x++) {
		q[x]=(x+1)*(x+1);
	}

}


void pascal (int v[], int N) {
	int i=0,j;


	while (i<N) {

		v[i]=1;
		j=i-1;
			while (j>0 ) {
				v[j] += v[j-1];
				j--;

			}

			i++;
	}

	for (i=0 ; i<N ; i++)
		printf("%d",v[i] ); 





}










int main () {
	int k[8];
	//swap (k,2,4);
	quadrados (k,5);
	//pascal (k,5);
	soma (k,6);
	pascal (k,8);	
	return 0;
}





