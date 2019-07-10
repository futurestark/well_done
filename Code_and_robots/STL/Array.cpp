/*****************************************************************************
 * This example demonstrates the use of the Array container STL
 *
 * Этот пример демонстрирует применение контейнера Array из STL
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

//STL
#include <array> //In C++ 11 Info: http://www.cplusplus.com/reference/array/array/
#include <algorithm>
#include <iterator>

using namespace std;

void display(char* str)
{
	cout << str << endl;
}

int main()
{

	array<char*, 3> arr;

	/* Ambiguity in Empty
	 * Неоднозначность в Empty */
	if (!arr.empty())
	{
		arr[0] = (char*)"String 1";
		//arr.at(1) = (char*)"String 2";
		arr.at(2) = (char*)"String 3";
	}

	cout << "Array size: " << arr.size() << endl;
	cout << "Array max size: " << arr.max_size() << endl;

	//Method get
	cout << get<1>(arr) << endl;

	/* Create iterators
	 * Создание итераторов */
	auto iterStart = arr.begin();
	auto iterEnd = arr.end();

	/* Create reverse iterators
	 * Создание обратных итераторов */
	auto RiterStart = arr.rbegin();
	auto RiterEnd = arr.rend();

	for_each(iterStart, iterEnd, display);

	arr.fill((char*)"fill");
	cout << endl;

	for_each(RiterStart, RiterEnd, display);
}
