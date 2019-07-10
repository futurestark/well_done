//Напечатать N чисел Фибоначчи:1,0, 1, 1, 2, 3, 5, 8, ...
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int N, a,b,c;

	system("chcp 1251 > nul");

	while(1)
	{
		do
		{
			printf("Сколько чисел Фибоначчи напечатать? ");
			fflush(stdin);		//чистка буфера KB
		}while((scanf("%d", &N)!=1 || N<0)
			 && printf("ОШИБКА ВВОДА!!!\n")
			  );

		if(N==0) break;

		for(a=1, b=0; (c = a+b)<=N; a = b, b = c)
			printf("%d, ", c);
		printf("\b\b \n");

		system("pause");
//		system("cls");
	}
}





