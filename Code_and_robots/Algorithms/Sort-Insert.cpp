/*****************************************************************************
 * This example demonstrates the development of algorithm sorting inserts
 *
 * Этот пример демонстрирует разработку алгоритма сортировки вставками
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/c/code_robots
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <functional>

enum type {less, greater};

template <typename T, type e>
void insertSort(T arr[], int n)
{
	int passages = 0;
	std::function<bool(T,T)> predicate;

	switch (e)
	{
		case greater:
			predicate = [] (T x, T y) { return x>y?true:false; };
		break;
		case less:
			predicate = [] (T x, T y) { return x<y?true:false; };
		break;
	}

	//Algorithm
	for (int j = 1; j < n; j++)
	{
		T key = arr[j];
		int i = j - 1;
		while (i >= 0 && predicate(arr[i], key))
		{
			passages++;
			arr[i+1] = arr[i];
			i--;
		}
		arr[++i] = key;
		passages++;
	}

	//Output
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << "(" << passages << ")" << std::endl;
}

int main()
{
	{
		int arr[] = {41, 58, 32, 64, 85, 73, 20};
		insertSort<int, greater> (arr, 7);
	}
	{
		int arr[] = {35, 58, 32, 45, 85, 73, 827};
		insertSort<int, greater> (arr, 7);
	}
	{
		int arr[] = {41, 58, 32, 64, 85, 73, 20};
		insertSort<int, less> (arr, 7);
	}
	{
		int arr[] = {35, 58, 32, 45, 85, 73, 827};
		insertSort<int, less> (arr, 7);
	}
}
