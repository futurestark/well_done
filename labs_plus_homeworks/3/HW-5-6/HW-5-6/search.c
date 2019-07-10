//1. линейный поиск в массиве
//2. поиск max в массиве

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print_arr(const int a[], int n);
int lin_search(const int a[], int n, int x);
void lfind(const int a[], int n);
int bin_search(const int a[], int n, int x);
void bfind(const int a[], int n);
int max_pos(const int a[], int n);
void sort_by_max(int a[], int n);
void swap(int a[], int i, int j);

int main()
{
	int a[] = {5,8,3,6,1,5,7,2,9,4};
	const int n = sizeof a / sizeof a[0];

	int imax;

	system("chcp 1251 > nul");

	//печать массива
	print_arr(a, n);

	//линейный поиск
	lfind(a,n);

	//поиск max
	imax = max_pos(a,n);

// O(N) = N

	printf("max: a[%d] = %d\n", imax,a[imax]);

	//сортировка
	sort_by_max(a, n);
	print_arr(a,n);
	bfind(a,n);

	system("pause");
}

void print_arr(const int aa[], int nn)
{
	int i;
	//печать массива
	for(i=0; i<nn; ++i)
		printf("%d, ", aa[i]);
	printf("\b\b \n");
}

int lin_search(const int a[], int n, int x)
{
	int i;
	for(i=0; i<n && a[i]!=x; ++i)
		;	
	if(i<n) return i;
	return -1;
}

void lfind(const int a[], int n)
{
	//ключ поиска
	int x, i;
	printf("¬ведите ключ поиска: ");
	scanf("%d", &x);
	
	//линейный поиск

	i = lin_search(a, n, x);	

// O(N)~N/2
	
	if(i>=0)
		printf("a[%d] = %d\n", i,x);
	else
		printf("%d в массиве нет\n",x);


}

int max_pos(const int a[], int n)
{
	int i, max, imax;
	for(max=a[imax=0], i=1; i<n; ++i)
		if(a[i]>max) max=a[imax=i];
	return imax;
}

void swap(int a[], int i, int j)
{
	int b = a[i];
	a[i] = a[j];
	a[j] = b;
}

void sort_by_max(int a[], int n)
{
	for( ; n>1; --n)
	{
		int i = max_pos(a,n);
		swap(a,i,n-1);
	}
}

//протестировать дл€ {1,2,3}, {0,1}, {1}

int bin_search(const int a[], int n, int x)
{
	int lo, med, hi;
	
	for(lo=0, hi=n-1;  
				lo<=hi && a[med=(lo+hi)/2]!=x;
					   x<a[med] ? (hi=med-1) : (lo=med+1))
		;
	
	if(lo<=hi) return med;
	return -1;
}

void bfind(const int a[], int n)
{
	//ключ поиска
	int x, i;
	printf("¬ведите ключ поиска: ");
	scanf("%d", &x);
	
	//бинарный поиск

	i = bin_search(a, n, x);	

// O(N)<= log N
	
	if(i>=0)
		printf("a[%d] = %d\n", i,x);
	else
		printf("%d в массиве нет\n",x);


}
