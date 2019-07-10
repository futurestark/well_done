/*****************************************************************************
 * This example demonstrates the use of the List container STL
 *
 * Этот пример демонстрирует применение контейнера List из STL
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
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

void show(int i)
{
	cout << i << ", ";
}

int main()
{
	list<int> ls;

	if (ls.empty())
		for (int i = 0; i < 5; i++)
			ls.push_back(i);
			//ls.push_front(i);

	cout << "Ms: " << ls.max_size() << endl;					// The maximum possible size of the list
	cout << "S: " << ls.size() << endl;							// The actual size of the list

	for_each(ls.begin(), ls.end(), show);cout << endl;
	for_each(ls.rbegin(), ls.rend(), show);cout << endl;

	ls.resize(10, 50);											// Make the size of the vector equal to N, and fill it with elements

	cout << "S: " << ls.size() << endl;

	auto it = ls.begin();
	advance(it, 5);												// Move of poiner

	ls.insert(it, 3, 120);										// Inserts elements at a certain position with a shift of the rest

	ls.push_back(180);											// Insert in back of List
	ls.push_front(380);											// Insert in front of List

	for_each(ls.begin(), ls.end(), show);cout << endl;

	list<int> ls2;
	ls2.assign(5, 66);

	ls.sort(greater<int>());									// Sorting on greater
	cout << "Sort: ";
	for_each(ls.begin(), ls.end(), show);cout << endl;

	ls.reverse();												// Reverse
	cout << "Reverse: ";
	for_each(ls.begin(), ls.end(), show);cout << endl;

	ls2.merge(ls);												// Merge and sort
	cout << "Merge: ";
	for_each(ls2.begin(), ls2.end(), show);cout << endl;

	ls2.unique();												// Remove duplicate items in a group
	cout << "Unique: ";
	for_each(ls2.begin(), ls2.end(), show);cout << endl;
}
