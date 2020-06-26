#include <stdio.h>

//1
float multInt (int n,float m) {
	int r=0;
	if (n>0) {
		for (; n>0 ; n--) r+=m;
			{printf("%d\n",r);return r;}
	}
	else {for (r=0 ; n<0 ; n++) r-=m;
			{printf("%d\n",r);return r;}
		}
	}

//2
float multInt2 (int n,float m) {
	int z=0;
	if (n>0) {
	while (n>=1) {
		if (n%2!=0) z += m;
		n /= 2;
		m *= 2;
	}
		}
	else {
		while (n!=0) {
		if (n%2!=0) z -= m;
		n /= 2;
		m *= 2;
	}
}
	printf ("%d\n",z);
	return z;
}

//3
int mdc (int a,int b) {
	int r;
	if (a>b) {r=b;
		while (b%r !=0 || a%r !=0) {
				--r;
		}
		{printf("%d\n",r);return r;}
	} 
	else {r=a;
		while (b%r !=0 || a%r !=0) {
				--r;
		}
		{printf("%d\n",r);return r;}
	}
}


//4
int mdc2 (int a,int b) {
	while (a!=0 || b!=0) {
		if (a>b) a-=b;
		   else if (a<b) b-=a;
		   	    else {printf ("%d\n",a);return a;}
	}
	return 0;
}

//5
int mdc3 (int a,int b) {
	while (a%b!=0 && b%a!=0) {
		if (a>b) a%=b;
			else b%=a;
	}
	if (a%b == 0) {printf("%d\n",b);return b;}
		else {printf("%d\n",a);return a;}
}

//6a
int fib (int n) {
	if (n>2) {
		n = fib(n-1) + fib(n-2);
	}
 	 else n=1;
	{printf ("%d\n",n);return n;}
}

//6b
int fib2 (int n) {
	int a=n-1,b=n-2;
	n=0;
	
	if (a<2 && b<2) {n+=1;}
	else if (a>2 && b<2) {n+=1;fib2 (b);}
			else if (a<2 && b>2) {n+=1;fib2 (a);}  
				else {n=fib2 (a) + fib2 (b);}
	{printf ("%d\n",n);return n;}

}







int main () {
	//multInt (2,0);
	multInt2 (2,2);
	//mdc (2,10);
	//mdc2 (10,45);
	//mdc3 (126,45);
	//fib (6);
	//fib2 (10);
	return 0;
}