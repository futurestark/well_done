/*****************************************************************************
 * This example demonstrates the use of the Deque container STL
 *
 * Этот пример демонстрирует применение контейнера Deque из STL
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
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

void show(int i)
{
	cout << i << ", ";
}

int main()
{
	deque<int> dq;

	if (dq.empty())
		for (int i = 0; i < 10; i++)
			dq.emplace_front(i);

	cout << "Ms: " << dq.max_size() << endl;					// The maximum possible size of the vector
	cout << "S: " << dq.size() << endl;							// The actual size of the vector

	for_each(dq.begin(), dq.end(), show);cout << endl;
	for_each(dq.rbegin(), dq.rend(), show);cout << endl;

	dq.resize(6, 50);											// Make the size of the vector equal to N, and fill it with elements

	cout << "S: " << dq.size() << endl;

	cout << dq[5] << endl;
	cout << dq.at(5) << endl;

	dq.insert(dq.begin()+2, 3, 120);							// Inserts elements at a certain position with a shift of the rest

	dq.push_back(1800);
	dq.push_front(3800);

	for_each(dq.begin(), dq.end(), show);cout << endl;

	dq.shrink_to_fit();											// Requests the container to reduce its memory usage to fit its size.
}
