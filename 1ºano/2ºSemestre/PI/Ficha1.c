#include <stdio.h>

/* 1.1 
int x,y;
x = 3; y = x+1;
x = x*y; y = x + y;
prinf ("%d %d",x,y);

Primeiramente o x=3 , y = 3 +1
De seguida o novo x sera 3*4, logo x = 12
Apos isto o novo y sera o x=12 e o y=4, como tal y = 12+4 = 16
Para finalizar ira printar o valor de x e o valor de y -> "12 16"


-> 1.2
int x,y;
x=0;
printf ("%d %d\n",x,y) 

-> 1.3
char a,b,c;
a = 'A' ; b = ' ' ; c = '0';
printf ("%c %d\n",a,a);           -> %d de um char transforma o char em um inteiro conforme a tabela de ascii
a = a+1; c = c+2;
printf ("%c %d %c %d\n",a,a,c,c); 
c=a+b;
printf ("%c %d\n",c,c);

Isto ira guardar o caracter 'A' no a, ' ' no b , e o '0' no c
De seguida ir dar print ao caracter e o numero do caracter conforme a tabela de ascii
Apos isso, ira somar 1 a numero do caracter 'A' da tabela de ascii, ou seja ira ter agora o numero 66 que corresponde a letra 'B' e ao mesmo vai fazer ao caracter '0'
....

-> 1.4
int x,y;
x = 200 ; y = 100;
x = x+y ; y = x-y ; x = x-y ;
prinf ("%d %d\n",x,y);

x=200 , y=100
x=200+100 = 300 e y=200-100 = 100
x=300-100 = 200
E o output sera 100 200

-> 1.5
int x,y;
x = 100 ; y = 28;
x += y ; y -= x;
printf ("%d %d\n", x++, ++y);
printf ("%d %d\n",x,y);

Seja o x = 100 e o y = 28
x += y -> x = x+y -----> x = 100+28 = 128
y -= x -> y = y-x -----> y = 28-128 = -100
x++ = x+1 = ++x

Output sera "129 -99"
            "128 -100"   */


/* 2.1
a) 
int x,y;
x = 3 ; y = 5;
if (x > y)
 y = 6
printf ("%d %d\n",x,y);

Isto primeiramente ira criar duas variaveis x e y, depois ira atribuir valores a essas variaveis, em que x=3 e y=5
Apos isto, ira criar uma condiçao em que se o x for maior do que o y, era atribuir um novo valor ao y.
Como tal nao é verdade, apenas ira dar o print ao valor do x e ou valor do y, neste caso "3 5"

b)
int x,y;
x = y = 0;
while (x != 11) {
	x = x+1; y +=x;
}
printf ("%d %d\n",x,y);

Novamente cria 2 variaveis inteiras x e y, em que de seguida ir atribuir um valor ao x e ao y, tais que x=0 e y = 0
Apos isto, entraremos num ciclo em que caso o x sera diferente de 11, o x ira somar 1 e o y sera igual a y+x.
Neste caso como o x = 0 e o y = 0, e como tal x é diferente de 11, o x ira somar 1 e passara a ser x=1, e o y seja y=0+1 = 1
Como o x continua a ser diferente de 11, ira novamente somar 1 e passara a ser x=2, e o y = 1+2 = 3.
Este ciclo ira continuar ate que o x = 11 e apos isso ira dar print ao x que sera 11 e ao y que sera 66.

c)
int x,y;
x = y = 0;
while (x !=11) {
	x = x+2; y +=x;
}
printf ("%d %d\n",x,y)

Ciclo infinito pois x nunca sera igual a 11

d)
int i;
for (i=0 ; (i<20) ; i++)
 if (i%2 == 0)  putchar ('_');
 else putchar ('#');

Apartir do 0 ira fazer a contiçao if , em que se o resto da divisao for igual a 0 ira meter o char '_'
e caso nao seja ira meter o char '#' e vai sempre a somar 1 ao i

e)
char i,j;
for (i='a' ; (i != 'h'); i++) {
	for (j=i ; (j != 'h') ; j++)
	   putchar (j);
	putchar ('\n');
}

output -> abcdfg
          bcdfg
          cdfg
          dfg
          fg
          g


f)
void f (int n) {
	while (n>0) {
	 if (n%2 == 0) putchar ('0');
	 else putchar ('1');
	 n=n/2;
	}
	putchar ('\n');
}

int main () {
	int i;
	for (i=0; (i<16) ; i++)
	  f (i);
	return 0;
}

output -> 

1
01
11
001
101
011
111
0001
1001
0101
1101
0011
1011
0111
1111

*/

//2
void exercicio2 () {
	int x,k;
	printf ("Escolha o tamanho do seu quadrado : ");
	scanf ("%d", &k);
	for (x=1 ; (x<(k*k)+1) ; x++)
		if (x%k == 0) {putchar ('#');putchar ('\n');}
			else putchar ('#');

}

//3
void exercicio3 () {
	int x,k,l;
	printf ("Escolha o tamanho do seu quadrado : ");
	k = getchar ();
	l = '0';
	k=k-l;
	for (x=1 ; (x<(k*k)+1) ; x++)
		if (x%2 == 0) if (x%k == 0) {putchar('_');putchar('\n');}
	                      else putchar ('_');
			else if (x%k == 0) {putchar ('#');putchar ('\n');}
			      else putchar ('#');
}

//4a
void exercicio4a () {
	int x,k,y;
	printf ("Escolha o tamanho da sua piramide : ");
	scanf ("%d", &k);
	for (x=1 ; (x<=k) ; x++) {
		for (y=x ; (y!=0) ; y--)
		putchar ('#');
      putchar ('\n');
  };
    for (x=k ; (x!=0) ; x--) {
    	for (y=1 ; (y!=x) ; y++)
    		putchar ('#');
    	putchar ('\n');
    }
}

//4b
void exercicio4b () {
	int x,k,y;
	printf ("Escolha o tamanho da sua piramide : ");
	scanf ("%d", &k);
	for (x=0 ; (x!=k) ; x++){	
		for (y=0 ; (y!=k-x) ; y++)
			putchar (' ');
	     	for (y=0 ; (y<2*x+1) ; y++)
		        putchar ('#');
		         putchar ('\n');

	}
}


int main () {
	//exercicio2 ();
	exercicio3 ();
	//exercicio4a ();
	//exercicio4b ();
	return 0;
}


















