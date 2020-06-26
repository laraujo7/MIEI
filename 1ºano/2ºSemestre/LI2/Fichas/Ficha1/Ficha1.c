#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tarefa 2
void tarefa2 () {
	float a,b,c,x1,x2;
	printf ("introduza os valores dos termos a,b e c do polinomio ax^2 + bx + c\n");
	scanf ("%f %f %f",&a,&b,&c);
	x1 = (-1.0 * b + sqrt (pow(b,2) - 4.0 * a * c)) / (2.0 *a);
	x2 = (-1.0 * b - sqrt (pow(b,2) - 4.0 * a * c)) / (2.0 *a);
	printf("raizes x1 = %f e x2 = %f \n",x1,x2);
}

//Tarefa3 - a)
int validarTriangulo (int x,int y,int z) {
	if (abs (y-z) < x && y+z > x) {printf ("Este triângulo é possível\n");return 0;}
		else {printf("Este triângulo nao é possível\n"); return 1;}

}

//Tarefa3 - b)
void classificacaoTriangulo (int x,int y,int z) {
	if (x==y && x==z) printf("O triângulo é Equilatro\n");
		else if (x==y || x==z || y==z) printf("O triângulo é Isóceles\n");
				else printf("O triângulo é Escaleno\n");
}

//Tarefa3 - c)
void calculoAreaTriangulo (int x,int y,int z) {
	float s;
	s = (float) (x+y+z) / 2;
	s = sqrtf (s*(s-x)*(s-y)*(s-z));
	printf("A área do triângulo é de %f cm^2\n",s);

}

int main () {
	int x,y,z;
	printf ("Introduza os valores dos lados do seu triângulo (em cm) : ");
	scanf ("%d %d %d",&x,&y,&z);
	//tarefa2 ();
	if (validarTriangulo (x,y,z) == 0) {
	classificacaoTriangulo (x,y,z);
	calculoAreaTriangulo (x,y,z);
}
	else return 0;

}

