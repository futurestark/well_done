/*****************************************************************************
 * This example demonstrates the use of the Vector container STL
 *
 * Этот пример демонстрирует применение контейнера Vector из STL
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
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void display(char* str)
{
	cout << str << endl;
}

int main()
{
	vector<char*> arr;

	cout << "Ms: " << arr.max_size() << endl;						// The maximum possible size of the vector
	cout << "S: " << arr.size() << endl;							// The actual size of the vector
	cout << "C: " << arr.capacity() << endl;						// The reserved space for the vector

	if (arr.empty())												// If the vector is empty
		arr.push_back((char*)"String 1");							// Add an element to the end
	arr.resize(3, (char*)"resize");									// Make the size of the vector equal to N, and fill it with elements

	cout << "S: " << arr.size() << endl;
	cout << "C: " << arr.capacity() << endl;
	arr.reserve(6);													// Reserve N cells under vector
	cout << "C: " << arr.capacity() << endl;
	arr.shrink_to_fit();											// Make the size of the vector equal to the number of elements in it
	cout << "C: " << arr.capacity() << endl;


	arr.insert(arr.begin()+2, 3, (char*)"Insert - 2");			// Inserts elements at a certain position with a shift of the rest
	//arr.erase (arr.begin()+2, arr.begin()+5);

	cout << "Ce: " << arr.capacity() << endl;
	arr.emplace(arr.begin()+5, (char*)"emplace");
	cout << "Ce: " << arr.capacity() << endl;

	auto iterStart = arr.begin();
	auto iterEnd = arr.end();

	cout << endl;
	for_each(iterStart, iterEnd, display);
}
