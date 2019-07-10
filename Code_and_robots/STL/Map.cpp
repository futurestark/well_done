/*****************************************************************************
 * This example demonmtrates the use of the Map, Multimap, Unordered_map and Unordered_multimap containers STL
 *
 * Этот пример демонстрирует применение контейнеров Map, Multimap, Unordered_map и Unordered_multimap из STL
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
#include <map>
#include <unordered_map>

#include <algorithm>
#include <iterator>

using namespace std;

void show(pair<int, char> p)
{
	cout << p.first << " = " << p.second << ", ";
}

int main()
{
// MAP
	map<int, char> mt;

	if (mt.empty())
		for (int i = 0; i < 5; i++)
			mt.insert(make_pair(i, char(70+i)));

	for (int i = 0; i < 6; i++)
		mt.emplace(make_pair(i, char(70+i)));						// Insert only 5

	cout << "Ms: " << mt.max_size() << endl;						// The maximum possible size
	cout << "S: " << mt.size() << endl;								// The actual size

	for_each(mt.begin(), mt.end(), show);cout << endl;
	for_each(mt.rbegin(), mt.rend(), show);cout << endl;

	//auto it = advance(mt.begin(), 3);								// Forbidden

	mt.emplace_hint(mt.begin(), make_pair(50, char(90)));			// Insert in back - Autosort
	//mt.emplace_hint(mt.end(), make_pair(50, char(90)));			// Insert in back - Autosort
	cout << "Emplace_hint: ";
	for_each(mt.begin(), mt.end(), show);cout << endl;

	auto itFind = mt.find(3);										// Searches the container for an element with a ke
	cout << "Find: ";
	cout << itFind->first << " = " << itFind->second;

	cout << endl << "At(4): " << mt.at(4) << endl;

//MultiMap

	multimap<int, char> mmp; cout << endl;

	if (mmp.empty())
		for (int i = 0; i < 5; i++)
			mmp.insert(make_pair(i, char(70+i)));

	for (int i = 0; i < 6; i++)
		mmp.insert(make_pair(i, char(75+i)));						// Insert all

	cout << "Multimap: ";
	for_each(mmp.begin(), mmp.end(), show);cout << endl;

	auto eqr = mmp.equal_range(3);
	cout << "Equal_range: ";
	for_each(eqr.first, eqr.second, show);cout << endl;

	//cout << endl << "At(4): " << mmp.at(4) << endl;				// Forbidden

//Unordered_map

	unordered_map<int, char> ump; cout << endl;

	if (ump.empty())
		for (int i = 0; i < 5; i++)
			ump.insert(make_pair(i, char(70+i)));

	for (int i = 0; i < 6; i++)
		ump.insert(make_pair(i, char(70+i)));

	cout << "Unordered_map: ";
	for_each(ump.begin(), ump.end(), show);cout << endl;

	cout << "At(4): " << ump.at(4) << endl;

//Unordered_multimap

	unordered_multimap<int, char> ummp; cout << endl;

	if (ummp.empty())
		for (int i = 0; i < 5; i++)
			ummp.insert(make_pair(i, char(70+i)));

	for (int i = 0; i < 6; i++)
		ummp.insert(make_pair(i, char(75+i)));

	cout << "Unordered_multimap: ";
	for_each(ummp.begin(), ummp.end(), show);cout << endl;

	//cout << endl << "At(4): " << ummp.at(4) << endl;					// Forbidden

	cout << "Bucket_count: " << ummp.bucket_count() << endl;
	cout << "Bucket_size: " << ummp.bucket_size(3) << endl;				// Count elements in one bucket
	cout << "Num bucket for elem. 5: " << ummp.bucket(5) << endl;

	unordered_multimap<int, char> ums; cout << endl;
	auto fn = ums.hash_function();										// Get hash-function

	cout << "that: " << fn (12) << endl;
	cout << "than: " << fn (10) << endl;

	//ummp.load_factor();												Return load factor (public member function)
	//ummp.max_load_factor();											Get or map maximum load factor (public member function)
	//ummp.rehash();													map number of buckets (public member function )
	//ummp.reserve();													Requemt a capacity change (public member function)
}
