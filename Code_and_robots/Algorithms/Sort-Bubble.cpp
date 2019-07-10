/*****************************************************************************
 * This example demonstrates the development of algorithm bubble sorting
 *
 * Этот пример демонстрирует разработку алгоритма пузырьковой сортировки
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
void bubbleSort(T arr[], int n)
{
	int passages = 0;
	bool swapped = false;
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
	for (int i = 0; i < n-1; i++)
	{
		swapped = false;
		passages++;
		for (int j = 0; j < n-i-1; j++)
		{
			if (predicate(arr[j],arr[j+1]))
			{
				T temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				swapped = true;
			}
			passages++;
		}
		if (!swapped) break;
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
		bubbleSort<int, greater> (arr, 7);
	}
	{
		int arr[] = {35, 58, 32, 45, 85, 73, 827};
		bubbleSort<int, greater> (arr, 7);
	}
	{
		int arr[] = {41, 58, 32, 64, 85, 73, 20};
		bubbleSort<int, less> (arr, 7);
	}
	{
		int arr[] = {35, 58, 32, 45, 85, 73, 827};
		bubbleSort<int, less> (arr, 7);
	}
}
