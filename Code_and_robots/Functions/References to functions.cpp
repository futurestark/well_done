/*****************************************************************************
 * This example demonstrates how to transfer the function to the function
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

using namespace std;

/* Sorting Functions
 * Сортировка от меньшего */
void lessMySort (int &x, int &y, bool &swapped)
{
	if (x > y)
	{
		swapped = true;
		int temp = 0;
		temp = x;
		x = y;
		y = temp;
	}
}

void greaterMySort (int &x, int &y, bool &swapped)
{
	if (x < y)
	{
		swapped = true;
		int temp = 0;
		temp = x;
		x = y;
		y = temp;
	}
}

//Run sorting
void sort (int *arr, int n, void (*f)(int&, int&, bool&))
{
	for (int i = 0; i < n-1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n-i-1; j++)
		{
			f(arr[j], arr[j+1], swapped);
		}
		if (!swapped)
			break;
	}

}

int main()
{
	/* Declare and initialize references to functions
	 * Объявление и инициализация ссылок на функции */
	void (*lessPtr) (int&, int&, bool&) = &lessMySort;
	void (*greaterPtr) (int&, int&, bool&) = &greaterMySort;

	int arr[5] = {10, 32, 15, 93, 42};

	//Sorting less
	sort (arr, 5, lessPtr);
	//Viev
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;

	cout << "   ---   " << endl;

	//Sorting greater
	sort (arr, 5, greaterPtr);
	//Viev
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;
}
