/*****************************************************************************
 * This example demonstrates use algorithm binary sorting
 *
 * Этот пример демонстрирует использование алгоритма бинарной сортировки
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/c/code_robots
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <algorithm>
#include <cstddef>
#include <utility>
#include <array>
#include <string>
#include <iostream>

template<typename T>
void tree_sort(T array[], std::size_t size) noexcept
{
	//Binary tree
	struct tree_t
	{
		tree_t *left, *right;
		T value;

		tree_t(T &&_value = T())
		{
			left = right = nullptr;
			value = std::forward<T>(_value);	//Perfect forwarding
		}

		//Recursive call
		//Move values of tree in array
		T* operator()(T array[])
		{
			if (this->left)
				array = this->left->operator()(array);

			*array++ = std::move(this->value);

			if (this->right)
				array = this->right->operator()(array);

			return array;
		}
	} root(std::move(array[0]));

	//Sorting / Build tree
	for (std::size_t idx = 1; idx < size; idx++)
	{
		bool inserted = false;
		tree_t *p_root = &root;
		while (!inserted)
		{
			if (array[idx] < p_root->value)
			{
				//Build left tree
				if (p_root->left) p_root = p_root->left;
				else
				{
					p_root->left = new tree_t(std::move(array[idx]));
					inserted = true;
				}
			}
			else
			{
				//Build right tree
				if (p_root->right) p_root = p_root->right;
				else
				{
					p_root->right = new tree_t(std::move(array[idx]));
					inserted = true;
				}
			}
		}
	}

	//Call operator()
	root(array);
}

using namespace std;

int main ()
{
	array <int, 7> arrInt = {543, 7, 12, 74, 381, 234, 815};
	array <string, 5> arrString = {"bcd", "gfg", "aba", "abca", "abc"};

	//Output
	for ( auto n : arrInt)
	{
		cout << n << ", ";
	} cout << endl;

	for ( auto n : arrString)
	{
		cout << n << ", ";
	} cout << endl << endl << endl;

		//Sorting
		tree_sort<int> (arrInt.data(), arrInt.size());
		tree_sort<string> (arrString.data(), arrString.size());

	//Output
	for ( auto n : arrInt)
	{
		cout << n << ", ";
	} cout << endl;

	for ( auto n : arrString)
	{
		cout << n << ", ";
	} cout << endl;

}
