/*****************************************************************************
 * This example demonstrates the development of algorithm select sorting
 *
 * Этот пример демонстрирует разработку алгоритма сортировки выбором
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
void selectSort(T arr[], int n)
{
	int passages = 0;
	std::function<bool(T,T)> predicate;

	switch (e)
	{
		case greater:
			predicate = [] (T x, T y) { return x<y?true:false; };
		break;
		case less:
			predicate = [] (T x, T y) { return x>y?true:false; };
		break;
	}

	//Algorithm
	for (int i = 0; i < n - 1; i++)
	{
		int el = i;
		for (int j = i + 1; j < n; j++)
		{
			if (predicate(arr[j], arr[el]))
				el = j;
			passages++;
		}

		if (el != i)
			std::swap(arr[i], arr[el]);
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
		selectSort<int, greater> (arr, 7);
	}
	{
		int arr[] = {35, 58, 32, 45, 85, 73, 827};
		selectSort<int, greater> (arr, 7);
	}
	{
		int arr[] = {41, 58, 32, 64, 85, 73, 20};
		selectSort<int, less> (arr, 7);
	}
	{
		int arr[] = {35, 58, 32, 45, 85, 73, 827};
		selectSort<int, less> (arr, 7);
	}
}
