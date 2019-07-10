#include<stdio.h>
#include"in_out.h"
#include"data.h"

void input_all(void)
{
	printf("input_all\n");
}


static void print_stud(const char name[], int maxlen,
					   const int grade[], int k)
{
	int j;
	printf("%-*s", maxlen,name);
	for(j=0; j<k; ++j)
		printf("%2d", grade[j]);
	printf("\n");

}

void print_all(void)
{
	int i;
	for(i=0; i<cur_n; ++i)
		print_stud(name[i], M, grade[i], K);
}
