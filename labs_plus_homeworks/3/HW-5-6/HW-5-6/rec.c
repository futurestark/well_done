
#include<stdio.h>
#include<stdlib.h>

int factorial(int n);

void bynary_r(unsigned x);
void bynary_s(unsigned x);
void bynary_i(unsigned x);

int main()
{
	int n=5, m;
	m = factorial(n);
	printf("%d\n", m);

	bynary_r(n); printf("\t%#X\n",n);
	bynary_r(m); printf("\t%#X\n",m);
	bynary_r(255); printf("\t%#X\n",255);
	bynary_r(32766); printf("\t%#X\n",32766);
	bynary_r(-1); printf("\t%#X\n",-1);
	bynary_r(0); printf("\t%#X\n",0);
	bynary_r(1); printf("\t%#X\n",1);
	puts("========================");
	bynary_s(8); printf("\t%#X\n",8);
	puts("========================");
	bynary_i(4); printf("\t%#X\n",4);
	bynary_i(-2); printf("\t%#X\n",-2);
}


int factorial(int n)
{ 
	if(n>1) return n*factorial(n-1);
	return 1;
}

void bynary_r(unsigned x)		//b(5)
{
	if(x>1) bynary_r(x/2);		//if(5>1)  b(2)
	printf("%d", x % 2);		//			if(2>1) b(1)
}								//					 if(1>1)...
								//					 "1"
								//					 "10"
								//					 "101"

void bynary_s(unsigned x)
{
	char buf[33];
	itoa(x,buf,2);
	printf(buf);
}

void bynary_i(unsigned x)
{
	unsigned m=0;
	for(m = ~(~m>>1); m; m >>= 1)
		printf("%d", (x & m) != 0);
}