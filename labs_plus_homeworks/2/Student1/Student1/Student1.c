#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char stud1[] = "Азаров",
		 stud2[] = "Березовский",
		 stud3[] = "Пупкин";
	int g11=4, g12=4, g13=5,
		g21=3, g22=2, g23=4,
		g31=4, g32=5, g33=4;

	system("chcp 1251 > nul");

	printf("Результаты экзаменов\n");
	printf("%-20s %2d %2d %2d\n", stud1, g11,g12,g13);
	printf("%-20s %2d %2d %2d\n", stud2, g21,g22,g23);
	printf("%-20s %2d %2d %2d\n", stud3, g31,g32,g13);

	printf("\nСредний балл\n");
	printf("%-20s %4.1f\n", stud1, (g11+g12+g13)/3.);
	printf("%-20s %4.1f\n", stud2, (g21+g22+g23)/3.);
	printf("%-20s %4.1f\n", stud3, (g31+g32+g13)/3.);

	printf("\nНаши двоечники\n");
	(g11==2 || g12==2 || g13==2) && printf("%-20s\n", stud1);
	(g21==2 || g22==2 || g23==2) && printf("%-20s\n", stud2);
	(g31==2 || g32==2 || g33==2) && printf("%-20s\n", stud3);

	system("pause");
}


if(...)
{
	...
}
else
{
	...
}

_asm
{



}