#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"menu.h"
#include"data.h"
#include"in_out.h"
#include"do_it.h"

void menu(void)
{
	char item_text[][32] =
	{
		"Ввод данных",
		"Обработка данных",
		"Вывод результатов"
	};

	const int n = sizeof item_text / sizeof item_text[0];
	int i, r;
	while(1)
	{
		do
		{
			system("cls");
			for(i=0; i<n; ++i)
				printf("%d. %s\n", i+1, item_text[i]);
			printf("%d. %s\n", 0, "Выход");

			printf("\nВаш выбор: ");
			fflush(stdin);
		}while(	scanf("%d", &r)!=1 || r<0 || r>n );

		system("cls");
		switch( r )
		{
		case 1:	input_all();	break;
		case 2: process_all();	break;
		case 3: print_all();	break;
		case 0: return;
		}
		system("pause");
	}
}